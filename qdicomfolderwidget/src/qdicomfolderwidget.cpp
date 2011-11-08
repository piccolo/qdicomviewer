#include <QDebug>
#include <QString>
#include <QDir>
#include <QVBoxLayout>

#include "qdicomfolderwidget.h"

qdicomfolderwidget::qdicomfolderwidget(QString folder, QWidget* parent)
  : QWidget(parent), _folder(folder)
{
  qDebug() << "Folder name : "<< _folder << endl;
  if (load_folder()) qDebug() << "Glop \n";
  _dicomwidget = new qdicomimagewidget(_list.at(0).filePath(),parent);
  qDebug() << _list.at(0).filePath();
  // PROBLEME _dcmFileFormat->LoadFile(_file);
  _slider = new QSlider(Qt::Horizontal);
  _slider->setRange(0,_list.size()-1);
  _slider->setValue(0);
  QVBoxLayout * layout = new QVBoxLayout;
  layout->addWidget(_dicomwidget);
  layout->addWidget(_slider);
  setLayout(layout);
  connect(_slider, SIGNAL(valueChanged(int)),
	  this, SLOT(setFile(int)));//setValue(int)));

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

  _list = dir.entryInfoList();
  qDebug() << "     Bytes Filename";
  qDebug() << _list.size() ;
  for (int i = 0; i < _list.size(); ++i) {
    QFileInfo fileInfo = _list.at(i);
    qDebug() << qPrintable(QString("%1 %2").arg(fileInfo.size(), 10)
			   .arg(fileInfo.fileName())) << "\n";
  }
  return true;
}

void qdicomfolderwidget::setFile(int n) {
  _dicomwidget->setImage(_list.at(n).filePath());
}
