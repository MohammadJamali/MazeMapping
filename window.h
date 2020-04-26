#ifndef WINDOW_H
#define WINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>
#include <QTimer>
#include <string>

#include "maze.h"
#include <vector>

using std::string;
using std::vector;

class Window
{
    public:
        Window(int argc, char **argv, string winTitle, unsigned _sizeX, unsigned _sizeY);
        ~Window();

        int showWindow();

        QGraphicsScene *getQGraphicsScene();

    private:
        unsigned sizeX, sizeY;
        string title;

        QGraphicsView *objQGraphicsView;
        QApplication *objQApplication;
        QGraphicsScene *objQGraphicsScene;
};

#endif // WINDOW_H
