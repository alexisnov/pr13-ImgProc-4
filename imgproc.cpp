#include "imgproc.h"

ImgProc::ImgProc(QString name,QString path):name(name),path(path)
{

}

void ImgProc::run(){
    //Загрузка картинки
    bool res = image.load(path);
    if(res){
        //TODO: обработка ошибки загрузки изображения
        //Обработка картинки
        if(!image.isNull()){
            int k = 2;
            //Масштабирование
            image = image.scaled(QSize(image.width()/k,image.height()/k));
            //Сохранение
            image.save(path);
            //Сигнал готовности
            emit ready(name);
        }
    }

}
