/* -*- c-basic-offset: 3 -*- 
 *
 * GREYC-ENSICAEN-CNRS-UMR 6072
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 * 
 */ 

/**
 * @author Vincent Roullier <vincent.roullier@greyc.ensicaen.fr> 
 * @version     0.0.1 - Thu Oct 20 2011
 * 
 * @todo the list of improvements suggested for the file.
 * @bug the list of known bugs.
 */

#ifndef _DICOM_IMAGE_H
#define _DICOM_IMAGE_H


/**
 * @file dicom_image.h
 *  
 * Description of the program objectives.
 * All necessary references.
 */

//#include <cfunix.h>
#include <osconfig.h>
#include <dcmimage.h>
#include <dcfilefo.h>
#include <dcdeftag.h>


class dicom_image {
 private :
   const char*  _file;
   unsigned int _width;
   unsigned int _height;
   
   DcmFileFormat* _dcmFileFormat;
   DicomImage* _image;
   EP_Representation _dcm_rep;
   
   float* _dcm_data;
 public :
   dicom_image(const char* file);
   
   bool load_image();

   inline unsigned int get_width() { return _width;}
   
   inline unsigned int get_height() { return _height; }
   
   inline float* get_data() { return _dcm_data; }

   inline DicomImage* get_image() {return _image; }
};

#endif // _DICOM_IMAGE_H
