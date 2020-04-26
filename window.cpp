#include "window.h"

Window::Window(int argc, char **argv, string winTitle, unsigned _sizeX, unsigned _sizeY):sizeX(_sizeX), sizeY(_sizeY)
  ,title(winTitle)
{
    objQApplication = new QApplication(argc, argv);

    objQGraphicsScene = new QGraphicsScene();

    objQGraphicsView = new QGraphicsView(objQGraphicsScene);
}

QGraphicsScene *Window::getQGraphicsScene(){return objQGraphicsScene;}

int Window::showWindow()
{
    objQGraphicsScene->setSceneRect(-20, -20, sizeX, sizeY);

    objQGraphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    objQGraphicsView->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, title.c_str()));
    objQGraphicsView->setCacheMode(QGraphicsView::CacheBackground);
    objQGraphicsView->setRenderHint(QPainter::Antialiasing);

    QTimer objQTimer;
    QObject::connect(&objQTimer, SIGNAL(timeout()), objQGraphicsScene, SLOT(advance()));
    objQTimer.start(1000 / 33);

    objQGraphicsView->show();

    return objQApplication->exec();
}

Window::~Window()
{
    delete objQApplication;
    delete objQGraphicsScene;
    delete objQGraphicsView;
}
