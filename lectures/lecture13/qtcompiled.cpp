//#include <QApplication>
//#include <QTextEdit>
//#include <QUiLoader>
#include "ui_qtcompiled.h"

int main(int argc, char **argv)
{

     QApplication app(argc, argv);
     //QWidget *widget = new QWidget;
     QMainWindow *widget = new QMainWindow;

     Ui::MainWindow ui;
     ui.setupUi(widget);

     widget->show();
     return app.exec();
    //QUiLoader loader;
    //QFile file(":/myform.ui");
    //file.open(QFile::ReadOnly);
    //QWidget *myWidget = loader.load(&file, this);
    //file.close();

    //QVBoxLayout *layout = new QVBoxLayout;
    //layout->addWidget(myWidget);
    //setLayout(layout);
}
