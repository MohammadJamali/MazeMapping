#include "box.h"

Box::Box(unsigned _sizeX, unsigned _sizeY, int _posX, int _posY):
    GObject(_sizeX, _sizeY, _posX, _posY, "Box"){
    ChangeColor = false;

    sign = 1;
    i = 0.0000001;
}

void Box::changeColor(QColor objQColor)
{
    objNewQColor = objQColor;
    ChangeColor = true;
}

QRectF Box::boundingRect() const
{

}

void Box::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(QBrush(objQColor, Qt::SolidPattern));
    painter->drawRect(getPosX(), getPosY(), getSizeX(), getSizeY());
}

void Box::advance(int step)
{
    if (!step) return;

    if(ChangeColor) {
        if(objNewQColor.red() != objQColor.red()){
            if(objNewQColor.red() - objQColor.red() > 0)
                objQColor.setRed(objQColor.red() + 1);
            else
                objQColor.setRed(objQColor.red() - 1);
        }

        if(objNewQColor.green() != objQColor.green()){
            if(objNewQColor.green() - objQColor.green() > 0)
                objQColor.setGreen(objQColor.green() + 1);
            else
                objQColor.setGreen(objQColor.green() - 1);
        }

        if(objNewQColor.blue() != objQColor.blue()){
            if(objNewQColor.blue() - objQColor.blue() > 0)
                objQColor.setBlue(objQColor.blue() + 1);
            else
                objQColor.setBlue(objQColor.blue() - 1);
        }

        if((objNewQColor.red() == objQColor.red()) &&
           (objNewQColor.green() == objQColor.green()) &&
           (objNewQColor.blue() == objQColor.blue()))
                ChangeColor = false;

        setPos(getPosX() + i, getPosY());
        i += sign * 0.0000001;
        sign = sign * -1;
    }
}

void Box::setQColor(QColor input) { objQColor = input; }
QColor Box::getQColor(void){ return objQColor; }
