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
 * @file main.cpp
 *  
 * Test dicomwidget.
 * All necessary references.
 */

#include <string>
#include <iostream>
#include <stdlib.h>

//#include "main.h"

using namespace std;

#include <QApplication>
#include <QString>
//#include "qdicomimagewidget.h"
#include "mainwindow.h"

int main(int argc, char* argv[]) {
   QApplication app(argc,argv);
   //   qdicomimagewidget* dcmw = new qdicomimagewidget(QString(argv[1]));
   //dcmw->show();
   mainwindow* mw = new mainwindow() ;
   mw->show();

   return app.exec();
}

