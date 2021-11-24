#ifndef IMGPROC_H
#define IMGPROC_H

#include <QThread>
#include <QImage>

/**
 * @brief Класс обработки изображенияы
 */

class ImgProc:public QThread
{
    Q_OBJECT
public:
    explicit ImgProc(QString name,QString path);
    void run() override;

signals:
    void ready(QString name);//Готовность изображения

private:
    QString name;//Имя потока = имя картинки
    QString path;//Путь к картинке
    QImage image;//Картинка
};

#endif // IMGPROC_H
