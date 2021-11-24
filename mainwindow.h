#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <imgproc.h>
#include <QDir>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    /**
     * @brief Готовность картинки
     * @param name - имя картинки
     */
    void imgReady(QString name);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<ImgProc*> threads;//Потоки обработки
    QString ext;//Фильтр изображение = расширение
    QDir dir;//Рабочая папка
    int N;//кол-во обработанных файлов
};
#endif // MAINWINDOW_H
