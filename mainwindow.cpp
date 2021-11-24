#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString path = "C:\\tmp\\1";
    ext = "*.png";//Расширение картинок
    dir = QDir(path);
    qDebug() << "Files number: " <<dir.count()-2;
    ui->label->setText(QString::number(dir.count()-2));
    foreach(QString path,dir.entryList(QStringList(ext))){
        //Добавление названия изображения в список
        ui->listWidget->addItem(path);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    N=0;
    //Запуск потоков обработки изображений
    foreach(QString path,dir.entryList(QStringList(ext))){
        ImgProc *imgProc = new ImgProc(path,dir.path()+"\\"+path);
        connect(imgProc,SIGNAL(ready(QString)), this, SLOT(imgReady(QString)));
        connect(imgProc,&ImgProc::finished,imgProc,&ImgProc::deleteLater);
        imgProc->start();
        threads.append(imgProc);
    }
}

void MainWindow::imgReady(QString name){
    qDebug() << name << " ready!";
    N+=1;
    int p = ((float) N)/dir.count() * 100;
    ui->progressBar->setValue(p+1);
}
