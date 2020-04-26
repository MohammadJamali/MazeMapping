#ifndef BOX_H
#define BOX_H

#include <QGraphicsRectItem>
#include <QPainter>

#include "gobject.h"

class Box : public GObject
{
    public:
        Box(unsigned _sizeX, unsigned _sizeY, int _posX, int _posY);

        void setQColor(QColor);
        QColor getQColor(void);

        void changeColor(QColor);

        virtual QRectF boundingRect() const;
        virtual void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);

    protected:
        virtual void advance(int step);

    private:
        QColor objQColor, objNewQColor;
        bool ChangeColor;
        int sign;
        double i ;
};

#endif // BOX_H
