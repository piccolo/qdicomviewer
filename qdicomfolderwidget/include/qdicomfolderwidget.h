#ifndef _QDICOMFOLDERWIDGET_H
#define _QDICOMFOLDERWIDGET_H


#include <QWidget>
#include <QPushButton>

#include <QString>
#include "dicom_image.h"

class qdicomfolderwidget : public QWidget {
  Q_OBJECT
  
private: 
  
  bool load_folder();
  
  QString _folder;
  
 public:
 
  qdicomfolderwidget(QString f, QWidget* parent=0);
  
  
};

#endif 
