/***************************************************************************
 *   Copyright (C) 2006 by Jeroen van der Waal                             *
 *   jwaal@kabelfoon.nl                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "qdicomimage.h"

//dcmtk related includes
#include <dcmtk/config/osconfig.h>
#include <dcmtk/ofstd/ofstring.h>
#include <dcmtk/ofstd/oftypes.h>
#include <dcmtk/ofstd/ofconsol.h>
#include <dcmtk/dcmdata/dcdeftag.h>
#include <dcmtk/dcmdata/dcfilefo.h>
#include <dcmtk/dcmimgle/dcmimage.h>
#include <dcmtk/dcmimage/diregist.h> /* include to support color images */
#include <dcmtk/dcmjpeg/djdecode.h>  /* for jpeg decoder */
#include <dcmtk/dcmdata/dcrledrg.h>
#include <dcmtk/dcmdata/dcpixseq.h>
#include <dcmtk/dcmdata/dcpixel.h>
#include <dcmtk/dcmdata/dcpxitem.h>
#include <dcmtk/dcmjpeg/djdecabs.h>  // Decompress jpeg bytes
#include <dcmtk/dcmjpeg/djdijg8.h>  // Coder Decoder
#include "dcmfile.h"
//
#include <QDebug>

//qt related includes
#include <qvector.h>


/*! 
  \brief locally used class to manage (de)registration of dcmtk codecs.

  Dcmtk requires registration and deregistration of codecs. This class 
  is to be created before using the QDicomImage class and is to be
  destroyed after the last use of qdicomimage.
*/
/*
class DecoderRegistration
{
public:
   // Register codecs
  DecoderRegistration()
  {
    ///register RLE decompression codecs
    DcmRLEDecoderRegistration::registerCodecs(OFFalse, OFTrue);
    /// register JPEG decompression codecs
    DJDecoderRegistration::registerCodecs();
  }

   // Deregister codecs
  ~DecoderRegistration()
  {
    DJDecoderRegistration::cleanup();
    DcmRLEDecoderRegistration::cleanup();
  }
};
*/
/**
 * \brief attributes of QDicomImage in private class
 */
 
class QDicomImagePrivate
{
public:
  QDicomImagePrivate()
      : m_dicomFileFormat(NULL)
      , m_dicomImage(NULL)
      , m_status(EIS_Normal)
      , m_qimage()
      , m_previousConvertedFrame(ULONG_MAX)
      , m_renewImage(false)
      , m_succes(false)
  {
    //empty
  }

  //Dcmtk attributes
  DcmFileFormat* m_dicomFileFormat;
  DicomImage* m_dicomImage;
  EI_Status m_status;

  //single decoder registration for all images.
  //static const DecoderRegistration m_decoderRegistration;
  //one color table shared among all images
//static const QGrayColorTable m_grayColorTable;
//  typedef enum {IMG_DEPTH = 8};

  //used when converting from dicom into qimage
  QImage m_qimage;
  //Used for simple cache.
  unsigned long m_previousConvertedFrame;
  //force convert when e.g. window center changes
  //this way the image is updated and the contrast change
  //is reflected.
  bool m_renewImage;
  
  //keep status of image loading
  bool m_succes;

};


QDicomImage::QDicomImage(const QString& filename, const unsigned long,
                         const unsigned long fstart, const unsigned long fcount)
    : d(new QDicomImagePrivate())
{
  d->m_succes = false;
  d->m_dicomFileFormat = new DcmFileFormat();
  OFCondition cond = d->m_dicomFileFormat->loadFile(filename.toAscii());

  if(cond.good())
  {
      E_TransferSyntax xfer = d->m_dicomFileFormat->getDataset()->getOriginalXfer();
      if(xfer == E_TransferSyntax(EXS_JPEGProcess14SV1TransferSyntax))
      {
          d->m_dicomImage = new DicomImage(d->m_dicomFileFormat, xfer,CIF_AcrNemaCompatibility, fstart, fcount);
          if (d->m_dicomImage->isMonochrome())
          {
              d->m_qimage = QImage(d->m_dicomImage->getWidth(),
                                   d->m_dicomImage->getHeight(),
                                   QImage::Format_Indexed8);
              d->m_succes = true;
          }
      }
      else {

          d->m_dicomImage = new DicomImage(d->m_dicomFileFormat, xfer,CIF_AcrNemaCompatibility, fstart, fcount);
          d->m_status = d->m_dicomImage->getStatus();
          if(EIS_Normal == d->m_status)
          {
              d->m_succes = true;
              if(d->m_dicomImage->isMonochrome())
              {
                  d->m_qimage = QImage(d->m_dicomImage->getWidth(),
                                       d->m_dicomImage->getHeight(),
                                       QImage::Format_Indexed8);
                  //        d->m_qimage.setColorTable(d->m_grayColorTable());
              }
              else
              {
                  d->m_qimage = QImage(d->m_dicomImage->getWidth(),
                                       d->m_dicomImage->getHeight(),
                                       QImage::Format_ARGB32);
              }
          }
          else
          {
            //problem opening dicom file.
            qDebug("QDicomImage problem during opening: %s\n",
                   d->m_dicomImage->getString(d->m_status));
          }
      }

  }
  else
  {
    qDebug( "QDicomImage not loaded, cause %s\n", cond.text());
  }
}

bool QDicomImage::succes( )
{
  return d->m_succes;
}


QDicomImage::~QDicomImage()
{
  if(d->m_dicomImage)
  {
    delete d->m_dicomImage;
  }

  if(d->m_dicomFileFormat)
  {
    delete d->m_dicomFileFormat;
  }

  delete d;
}

/*const QImage& QDicomImage::outputData(const unsigned long p_frame, const int p_planar) const
{
  if((p_frame == d->m_previousConvertedFrame) &&
      (d->m_renewImage == false))
  {
    //this image is already converted, return immediately.
    return d->m_qimage;
  }
  d->m_renewImage = false;

  if(EIS_Normal == d->m_status)
  {
    d->m_previousConvertedFrame = p_frame;
    uchar* pixelData = (uchar *)(d->m_dicomImage->getOutputData(8,p_frame,p_planar));
    if (d->m_dicomImage->isMonochrome())
    {
      //Monochroom images
      //transform representation from dcmtk(gray) to qimage (gray)
      for(unsigned y=0; y < d->m_dicomImage->getHeight(); y++)
      {
        uchar* scanLine = d->m_qimage.scanLine(y);
        for(unsigned x = d->m_dicomImage->getWidth(); x != 0; --x)
        {
          *(scanLine++) = *(pixelData++);
        }
      } 
    }
    else
    {
      //color images
      //transform representation from dcmtk(RGB) to qimage (RGBA)      
      uchar* qImageBuffer = d->m_qimage.bits();
      for(unsigned long pixels = d->m_qimage.width() * d->m_qimage.height(); 
        pixels != 0; --pixels)
      {
        *qImageBuffer++ = *pixelData++ ; //R
        *qImageBuffer++ = *pixelData++;  //G
        *qImageBuffer++ = *pixelData++;  //B
        *qImageBuffer++ = 0xFF; //Alpha
      } 
    }
  }
  return d->m_qimage; // is ok to return, qimage supports shallow copy
}
*/
const QImage& QDicomImage::outputData(const unsigned long p_frame, const int p_planar) const
{
    DJDecoderRegistration::registerCodecs();
    DcmRLEDecoderRegistration::registerCodecs();

    OFCondition result = EC_Normal;
    DcmDataset *data=d->m_dicomFileFormat->getDataset();
    DcmElement* element = NULL;
    result = data->findAndGetElement(DCM_PixelData, element);
    if (result.bad() || element == NULL)
        qDebug() << "Result Error";
    DcmPixelData *dpix = NULL;
    dpix = OFstatic_cast(DcmPixelData*, element);
    /* Since we have compressed data, we must utilize DcmPixelSequence
         in order to access it in raw format, e. g. for decompressing it
         with an external library.
       */
    DcmPixelSequence *dseq = NULL;
    E_TransferSyntax xferSyntax = EXS_Unknown;
    const DcmRepresentationParameter *rep = NULL;
    // Find the key that is needed to access the right representation of the data within DCMTK
    dpix->getOriginalRepresentationKey(xferSyntax, rep);
    // Access original data representation and get result within pixel sequence
    result = dpix->getEncapsulatedRepresentation(xferSyntax, rep, dseq);
    if ( result == EC_Normal )
    {
        DcmPixelItem* pixitem = NULL;
        // Access first frame (skipping offset table)
        dseq->getItem(pixitem, 1);
        if (pixitem == NULL)
            qDebug() << "Error pixitem";
        Uint8* pixelData = NULL;
        Uint8* pixelDataUncompressed = NULL;

        // Get the length of this pixel item (i.e. fragment, i.e. most of the time, the lenght of the frame)
        Uint32 length = pixitem->getLength();
        if (length == 0)
            qDebug() << "Error Lengt";
        result = pixitem->getUint8Array(pixelData);
        if (result.bad())
            qDebug() << "Error decompress data";
        //Monochroom images
        //transform representation from dcmtk(gray) to qimage (gray)
        DJDecompressIJG8Bit* jpeg;
        result=jpeg->init();
        if (result.bad())
            qDebug() << "Error decompress init";
        jpeg->decode(pixelData,length,pixelDataUncompressed,length,NULL);
        for(unsigned y=0; y < d->m_dicomImage->getHeight(); y++)
        {
            uchar* scanLine = d->m_qimage.scanLine(y);
            for(unsigned x = d->m_dicomImage->getWidth(); x != 0; --x)
            {
                *(scanLine++) = *(pixelDataUncompressed++);
            }
        }
    }

    return d->m_qimage; // is ok to return, qimage supports shallow copy
    DJDecoderRegistration::cleanup();
    DcmRLEDecoderRegistration::cleanup();
}




unsigned long QDicomImage::frameCount() const
{
  return d->m_dicomImage->getFrameCount();
}

/*!
    \fn QDicomImage::frameTimeMsec
    In case of a run/loop (movie) this method tries to determine the
    frames per second.
    determine the frame time from various dicom tags
    
 */
int QDicomImage::frameTimeMsec() const
{
  //no image loaded, return immediately
  if(d->m_dicomFileFormat == NULL)
  {
    return 0;
  }
  if(frameCount() < 2)
  {
    qDebug("No frame time calculated. Image has only "
           "zero or one frame.");
  }

  DcmDataset* dataset = d->m_dicomFileFormat->getDataset();
  OFCondition cond;

  int frameTime = 0;
  long int recommendedDisplayFrameRate = 0;
  cond = dataset->findAndGetLongInt(
           DCM_RecommendedDisplayFrameRate, recommendedDisplayFrameRate);
  if(cond.good())
  {
    qDebug("FrameTimeMsec-RecommendedDisplayFrameRate %ld", recommendedDisplayFrameRate);
    if(recommendedDisplayFrameRate)
    {
      frameTime = (1000 / (int)recommendedDisplayFrameRate);
    }
  }

  Float64 dicomFrameTime = 0.0;
  cond = dataset->findAndGetFloat64(
           DCM_FrameTime, dicomFrameTime);
  if(cond.good())
  {
    qDebug("FrameTimeMsec-FrameTime %f", (float)dicomFrameTime);
    if(!frameTime)
    {
      frameTime = int(dicomFrameTime);
    }
  }

  long int cineRate = 0;
  cond = dataset->findAndGetLongInt(
           DCM_CineRate, cineRate);
  if(cond.good())
  {
    qDebug("FrameTimeMsec-CineRate %ld", cineRate);
    if(!frameTime && cineRate)
    {
      frameTime = 1000 / cineRate;
    }
  }

  //default is 30 fps (1000 millisecond within 30 frames)
  if(frameTime)
  {
    qDebug("Frametime set to %d", frameTime);
  }
  else
  {
    qDebug("No frame time determined, setting default for"
           "30 fps.");
    frameTime = 1000 / 30;
  }
  return frameTime;
}


/*!
    \fn QDicomImage::size()
 */
QSize QDicomImage::size()
{
  QSize s(d->m_dicomImage->getWidth(),
          d->m_dicomImage->getHeight());
  return s;
}

void QDicomImage::setWindowCenter( const double center )
{
  d->m_renewImage = true;
  d->m_dicomImage->setWindow(center, windowWidth());
}

double QDicomImage::windowCenter( ) const
{
  double center;
  double width;
  d->m_dicomImage->getWindow(center, width);
  return center;
}

void QDicomImage::setWindowWidth( const double width )
{
  d->m_renewImage = true;
  d->m_dicomImage->setWindow(windowCenter(), width);
}

double QDicomImage::windowWidth( ) const
{
  double center;
  double width;
  d->m_dicomImage->getWindow(center, width);
  return width;
}

bool QDicomImage::setMinMaxWindow( )
{
  d->m_renewImage = true;
  return (d->m_dicomImage->setMinMaxWindow() > 0);
}

bool QDicomImage::minMaxValues( double & min, double & max ) const
{
  return (d->m_dicomImage->getMinMaxValues(min, max) > 0);
}


