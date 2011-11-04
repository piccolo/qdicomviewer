
#include <QtGui>
#include <QDebug>
#include "mainwindow.h"
#include "qdicomimagewidget.h"
mainwindow::mainwindow() :
  QMainWindow()
{
  createActions();
  createToolBars();
  createMenus();
  createStatusBar();
}


void mainwindow::createActions() {
  
  _openAct = new QAction(QIcon(":/images/open.png"), tr("&Open..."), this);
  _openAct->setShortcuts(QKeySequence::Open);
  _openAct->setStatusTip(tr("Open an existing file"));
  connect(_openAct, SIGNAL(triggered()), this, SLOT(open()));
  
  _exitAct = new QAction(tr("E&xit"), this);
  _exitAct->setShortcuts(QKeySequence::Quit);
  _exitAct->setStatusTip(tr("Exit the application"));
  connect(_exitAct, SIGNAL(triggered()), this, SLOT(close()));
}

void mainwindow::createMenus() {
  _filemenu = menuBar()->addMenu(tr("&File"));
  _filemenu->addAction(_openAct);
  _filemenu->addSeparator();
  _filemenu->addAction(_exitAct);
  
}


void mainwindow::createToolBars()
{
    _fileToolBar = addToolBar(tr("File"));

    _fileToolBar->addAction(_openAct);

    //fileToolBar->addAction(saveAct);
}


void mainwindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void mainwindow::open() {
  QString fileName=QFileDialog::getOpenFileName(this);
  if (!fileName.isEmpty()) {
    qDebug() << "FileName : " << fileName << endl;
    load_file(fileName);
  }
}

void mainwindow::close(QCloseEvent *event) {
  event->accept();
}

void mainwindow::load_file(const QString &fileName) {
  qDebug() << "load file : "<< fileName ;
  qdicomimagewidget* qdw = new qdicomimagewidget(fileName);
  setCentralWidget(qdw);
  
}


