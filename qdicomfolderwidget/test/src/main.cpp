
#include <string>
#include <iostream>
#include <stdlib.h>

//#include "main.h"

using namespace std;

#include <QApplication>
#include <QString>
#include "qdicomfolderwidget.h"

int main(int argc, char* argv[]) {
   QApplication app(argc,argv);
   qdicomfolderwidget* dcmw = new qdicomfolderwidget(QString(argv[1]));
   dcmw->show();
   return app.exec();
}

