#include "gobject.h"

GObject::GObject(unsigned _sizeX, unsigned _sizeY, int _posX, int _posY, string _name)
{
    setVisibility(true);
    setPosX(_posX);
    setPosY(_posY);
    setSizeX(_sizeX);
    setSizeY(_sizeY);
    setName(_name);
}

void GObject::setVisibility(bool input){ Visibility = input; }
bool GObject::getVisibility(void) { return Visibility; }

void GObject::setSizeX(unsigned input){ sizeX = input; }
unsigned GObject::getSizeX(void){ return sizeX ;}

void GObject::setSizeY(unsigned input){ sizeY = input; }
unsigned GObject::getSizeY(void){ return sizeY; }

void GObject::setPosX(int input){ posX = input; }
int GObject::getPosX(void){ return posX; }

void GObject::setPosY(int input){ posY = input; }
int GObject::getPosY(void){ return posY; }

void GObject::setName(string input){ name = input; }
string GObject::getName(void){ return name; }
