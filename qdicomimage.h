/***************************************************************************
 *   Copyright (C) 2007 by Jeroen van der Waal                             *
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
#ifndef QDICOMIMAGE_H
#define QDICOMIMAGE_H

/**
	@author Jeroen van der Waal <jwaal@kabelfoon.nl>
*/

#include "qimage.h"
#include "qsize.h"
#include <dcmtk/dcmjpeg/djcparam.h>



class QDicomImagePrivate;


//! Transforms dcmtk image into a Qt QImage 
/*! 
  Convert a dicom image into an QImage. Can be used for a single image or can
  be used for multiple images (runs/loops). Supports dcmtk window-center and 
  window-width (contrast / brightness). Images can be accessed via outputData.
  The frame rate in case of a loop or run is also determined in this class.
*/

class QDicomImage
{
public:

    /**
     * Opens a dicom file using the dcmtk toolkit. 
     * @param filename the filename of the of the dicom file to open
     * @param flags see documentation dcmtk
     * @param fstart see documentation dcmtk
     * @param fcount see documentation dcmtk
     */
     //! @todo should also be possible to dynamic load in another file.
     //! @todo aspect ratio is not taken into account
    QDicomImage(const QString& filename, const unsigned long flags=0,
                const unsigned long fstart=0, const unsigned long fcount=0);
    virtual ~QDicomImage();
    const QImage& outputData(const unsigned long p_frame=0,
                      const int p_planar=0) const;
    
    
    /**
     * Returns if everything is loaded succesfully
     * @return true when file is loaded succesfully
     */
    bool succes();
    
    /**
     * Available frames within the current file
     * @return number of available frames
     */
    unsigned long frameCount() const;
    
    /**
     * Tries on several ways to determine the required frame rate.
     * if not succusfull a default of 30 frames/sec is taken.
     * @return 
     */
    int frameTimeMsec() const;
    
    /**
     * Size of the image
     * @return size
     * @todo implicit within qimage. Not needed
     */
    QSize size();


    //Methods related to windowing of the image
    /**
     * Set the value for the Window Center (brightness)
     * @param center the value to set
     */
    void setWindowCenter(const double center);
    /**
     * Get the value for the Window Center (brightness)
     * @param center the current value
     */
    double windowCenter() const;
    /**
     * Set the value for the Window Width (brightness)
     * @param width the value to set
     */
    void setWindowWidth(const double width);
    /**
     * Get the value for the Window Width (contrast)
     * @param center the current value
     */
    double windowWidth() const;
    /**
     * Use the min max algorithm to set the window width
     * and window center. See dcmtk documentation.
     * @return 
     */
    bool setMinMaxWindow();
    /**
     * Get minimum and maximum pixel values.
     * @param min minimum pixel value (reference parameter)
     * @param max maximum pixel value (reference parameter)
     * @return true if successfull
     */
    bool minMaxValues(double& min, double& max) const;
private:
    QDicomImagePrivate *d;
};


#endif
