#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QMenu;

class mainwindow : public QMainWindow 
{
  Q_OBJECT
  public:
  
  mainwindow();
  
private slots:
  
  void open();
  void close(QCloseEvent* event);

private: 
  void createActions();
  void createToolBars();
  void createMenus();
  void createStatusBar();
  void load_file(const QString &filename);
  
  QMenu* _filemenu;
  QToolBar *_fileToolBar;
  QAction* _openAct;
  QAction* _exitAct;
};

#endif

 
