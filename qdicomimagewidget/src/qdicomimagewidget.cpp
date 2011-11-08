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
 * @file qdicomwidget.cpp
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include <string>
#include <iostream>
#include <stdlib.h>

#include "qdicomimagewidget.h"
#include "dicom_image.h"
#include <QDebug>
#include <QPainter>

qdicomimagewidget::qdicomimagewidget( QString filename, QWidget *parent)
   : QWidget(parent), _filename(filename)
{
   qDebug() << "filename toto : " << filename;
   setImage(_filename);
}

void qdicomimagewidget::setImage(QString filename) {
   _filename = filename;
   qDebug() << _filename.toStdString().c_str();
   _dcmimage = new dicom_image(_filename.toStdString().c_str());
   qDebug() << _dcmimage->get_width() << " x " << _dcmimage->get_height();
   setFixedSize(_dcmimage->get_width(), _dcmimage->get_height());
   _qimagesize = _dcmimage->get_width() * _dcmimage->get_height();
   _qimagebuffer = new uchar[_qimagesize];
   _dcmimage->get_image()->setMinMaxWindow();
   _dcmimage->get_image()->getWindow(_windowcenter, _windowwidth);
   _dcmimage->get_image()->getOutputData(_qimagebuffer,_qimagesize,8);
   _qimage= QImage(_qimagebuffer, _dcmimage->get_width(), _dcmimage->get_height(), QImage::Format_Indexed8);
   update();
   //emit setImage(filename);
}

void qdicomimagewidget::paintEvent(QPaintEvent* e) {
   QPainter painter(this);
   painter.drawImage(0,0,_qimage);
}

void qdicomimagewidget::mousePressEvent(QMouseEvent* e) {
   e->accept();
   _lastMousePosition = e->pos();
}

void qdicomimagewidget::mouseMoveEvent(QMouseEvent* e) {
   e->accept();
   QPoint tmp = e->pos();
   QPoint delta = _lastMousePosition - tmp;
   qDebug() << delta.x() << " x " << delta.y() ;
   if (delta.x() != 0) {
      if (delta.x() > 0) 
	 _windowcenter+=5.0;
      else
	 _windowcenter -=5.0;
   }
   if (delta.y() != 0) {
      if (delta.y() > 0) 
	 _windowwidth += 5.0;
      else
	 _windowwidth -= 5.0;
   }
   _lastMousePosition = tmp;
   _dcmimage->get_image()->setWindow(_windowcenter,_windowwidth);
   _dcmimage->get_image()->getOutputData(_qimagebuffer,_qimagesize,8);
   _qimage= QImage(_qimagebuffer, _dcmimage->get_width(), _dcmimage->get_height(), QImage::Format_Indexed8);
   
   qDebug() << "window  : "<< _windowcenter << " , " << _windowwidth;
   update();
}


