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

#ifndef _QDICOMIMAGEWIDGET_H
#define _QDICOMIMAGEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QFont>
#include <QString>
#include <QWheelEvent>


#include "dicom_image.h"
/**
 * @file qdicomimagewidget.h
 *  
 * Description of the program objectives.
 * All necessary references.
 */
class QPaintEvent;

class qdicomimagewidget : public QWidget
{
   Q_OBJECT;
 private :
   dicom_image* _dcmimage;
   QString _filename;
   
   uchar* _qimagebuffer;
   int _qimagesize;
   QImage _qimage;
   
   double _windowcenter;
   double _windowwidth;
   
   public slots:
   /* void setWindowWidth(int p); */
   /* void setWindowCenter(int p); */
   
 protected:
   virtual void mousePressEvent(QMouseEvent* e);
   virtual void mouseMoveEvent(QMouseEvent* e);
 public:
   qdicomimagewidget(QString f,QWidget *parent = 0 );
   
    void paintEvent(QPaintEvent*);
   void setImage(QString filename);
   QPoint _lastMousePosition;
   
   inline QImage & image();
  
};

QImage & qdicomimagewidget::image() { return _qimage; }

#endif
