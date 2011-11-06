#include <QDebug>
#include <QString>
#include <QDir>

#include "qdicomfolderwidget.h"

qdicomfolderwidget::qdicomfolderwidget(QString folder, QWidget* parent)
  : QWidget(parent), _folder(folder)
{
  qDebug() << "Folder name : "<< _folder << endl;
  if (load_folder()) qDebug() << "Glop \n";
  
} 


bool qdicomfolderwidget::load_folder() {
  QDir dir(_folder);
  qDebug() << "load folder \n ";
  if (!dir.exists()){
    qWarning("Cannot find the directory");
    return false;
  }
  dir.setFilter(QDir::Files | QDir::NoSymLinks | QDir::NoDotAndDotDot);
  //dir.setSorting(QDir::Size | QDir::Reversed);

  QFileInfoList list = dir.entryInfoList();
  qDebug() << "     Bytes Filename";
  qDebug() << list.size() ;
  for (int i = 0; i < list.size(); ++i) {
    QFileInfo fileInfo = list.at(i);
    qDebug() << qPrintable(QString("%1 %2").arg(fileInfo.size(), 10)
			   .arg(fileInfo.fileName())) << "\n";
  }
  return true;
}

