#ifndef GOBJECT_H
#define GOBJECT_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <string>

using std::string;

class GObject : public QGraphicsItem
{
    public:
        GObject(unsigned , unsigned , int , int , string);

        void setVisibility(bool);
        bool getVisibility(void);

        void setSizeX(unsigned);
        unsigned getSizeX(void);

        void setSizeY(unsigned);
        unsigned getSizeY(void);

        void setPosX(int);
        int getPosX(void);

        void setPosY(int);
        int getPosY(void);

        void setName(string);
        string getName(void);

        virtual QRectF boundingRect() const = 0;
        virtual void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *) = 0;

    protected:
        virtual void advance(int step) = 0;

    private:
        bool Visibility;
        unsigned sizeX, sizeY;
        int posX, posY;
        string name;

};

#endif // GOBJECT_H
