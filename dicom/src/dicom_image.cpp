/* -*- c-basic-offset: 3 -*- 
 *
 * GREYC-ENSICAEN-CNRS-UMR 6072
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 *
 */ 

/**
 * @author Vincent Roullier  <vincent.roullier@greyc.ensicaen.fr> 
 * @version     0.0.1 - Thu Oct 20 2011
 * 
 * @todo the list of improvements suggested for the file.
 * @bug the list of known bugs.
 */

/**
 * @file dicom_image.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */


#include "dicom_image.h"

dicom_image::dicom_image(const char* file)
   : _file(file)
{
   load_image();
}

bool dicom_image::load_image() {
   _dcmFileFormat = new DcmFileFormat();
   OFCondition cond = _dcmFileFormat->loadFile(_file);
   if (cond.good()) {
      _image = new DicomImage(_file);
      if (_image->getStatus() == EIS_Normal) {
	 _width = _image->getWidth();
	 _height = _image->getHeight();
	 // const DiPixel* dmp=NULL;
	 // dmp = _image->getInterData();
	 // pixelData = new unsigned char[_width*height];
	 // unsigned char* pixelData = (unsigned char*)_image->getOutputData(8);
	 // _dcm_data = new float[_width*_height];
	 // _dcm_rep = _image->getInterData()->getRepresentation();
	 // if (_image->isMonochrome()) {
	 //    for (unsigned int y = 0 ; y < _height ; y++) {
	 //       for (unsigned int x= 0 ; x < _width ; x++) {
	 // 	  *(_dcm_data++) = *(pixelData++);
	 //       } 
	 //    }
      }
      
      
      //cout << "glop " << endl;
   }

}
