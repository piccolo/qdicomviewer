#ifndef _QDICOMFOLDERWIDGET_H
#define _QDICOMFOLDERWIDGET_H


#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QString>
#include <QFileInfoList>
#include "qdicomimagewidget.h"
#include "dicom_image.h"

class qdicomfolderwidget : public QWidget {
  Q_OBJECT
  
private: 
  
  bool load_folder();
  
  QString _folder;
  
  QFileInfoList _list;

  qdicomimagewidget* _dicomwidget;

  QSlider* _slider;

 public:
 
  qdicomfolderwidget(QString f, QWidget* parent=0);
  
  
};

#endif 
