
cmake_minimum_required(VERSION 2.8)

if(POLICY CMP0020)
  cmake_policy(SET CMP0020 NEW)
endif()

PROJECT(SendDicomImages)

add_library(dcmtknet SHARED IMPORTED)
set_property(TARGET dcmtknet PROPERTY IMPORTED_LOCATION /usr/lib64/libdcmnet.so)

add_library(dcmdata SHARED IMPORTED)
set_property(TARGET dcmdata PROPERTY IMPORTED_LOCATION /usr/lib64/libdcmdata.so)

add_library(ofstd SHARED IMPORTED)
set_property(TARGET ofstd PROPERTY IMPORTED_LOCATION /usr/lib64/libofstd.so)

add_library(oflog SHARED IMPORTED)
set_property(TARGET oflog PROPERTY IMPORTED_LOCATION /usr/lib64/liboflog.so)

add_library(dcmimgle SHARED IMPORTED)
set_property(TARGET dcmimgle PROPERTY IMPORTED_LOCATION /usr/lib64/libdcmimgle.so)

add_library(dcmjpeg SHARED IMPORTED)
set_property(TARGET dcmjpeg PROPERTY IMPORTED_LOCATION /usr/lib64/libdcmjpeg.so)

add_library(ijg12 SHARED IMPORTED)
set_property(TARGET ijg12 PROPERTY IMPORTED_LOCATION /usr/lib64/libijg12.so)
# 
add_library(ijg16 SHARED IMPORTED)
set_property(TARGET ijg16 PROPERTY IMPORTED_LOCATION /usr/lib64/libijg16.so)

add_library(ijg8 SHARED IMPORTED)
set_property(TARGET ijg8 PROPERTY IMPORTED_LOCATION /usr/lib64/libijg8.so)

set (RESOURCES 	ResourceMainWindowIcons.qrc)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

if(${VTK_VERSION} VERSION_GREATER "6" AND VTK_QT_VERSION VERSION_GREATER "4")
  # Instruct CMake to run moc automatically when needed.
  set(CMAKE_AUTOMOC ON)
  find_package(Qt5Widgets REQUIRED QUIET)
else()
  find_package(Qt4 REQUIRED)
  include(${QT_USE_FILE})
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

file(GLOB UI_FILES *.ui)
file(GLOB QT_WRAP *.h)
file(GLOB CXX_FILES *.cpp)
file(GLOB Resource *.qrc)
qt4_add_resources (QRC_SOURCES ${RESOURCES})

if(${VTK_VERSION} VERSION_GREATER "6" AND VTK_QT_VERSION VERSION_GREATER "4")
  qt5_wrap_ui(UISrcs ${UI_FILES} )
  # CMAKE_AUTOMOC in ON so the MocHdrs will be automatically wrapped.
  add_executable(SendDicomImages MACOSX_BUNDLE
    ${CXX_FILES} ${UISrcs} ${QT_WRAP} ${Resource} ${QRC_SOURCES})
  qt5_use_modules(SendDicomImages Core Gui)
  target_link_libraries(SendDicomImages ${VTK_LIBRARIES} dcmtknet dcmdata ofstd oflog dcmimgle dcmjpeg ijg12 ijg8)
  
  else()
  QT4_WRAP_UI(UISrcs ${UI_FILES})
  QT4_WRAP_CPP(MOCSrcs ${QT_WRAP})
  
  add_executable(SendDicomImages MACOSX_BUNDLE ${CXX_FILES} ${UISrcs} ${MOCSrcs} ${QRC_SOURCES})

  if(VTK_LIBRARIES)
    if(${VTK_VERSION} VERSION_LESS "6")
      target_link_libraries(SendDicomImages ${VTK_LIBRARIES} QVTK dcmtknet dcmdata ofstd oflog dcmimgle dcmjpeg ijg12 ijg16 ijg8 )
      else()
      target_link_libraries(SendDicomImages ${VTK_LIBRARIES} dcmtknet dcmdata ofstd oflog dcmimgle dcmjpeg ijg12 ijg16 ijg8 )
    endif()
    else()
      target_link_libraries(SendDicomImages ${VTK_LIBRARIES} dcmtknet dcmdata ofstd oflog dcmimgle dcmjpeg ijg12 ijg16 ijg8 )
    endif()
endif()  
