#include <QCoreApplication>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>

#include "point2d.h"
#include "mygraph.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const QString DATAPATH = qApp->applicationDirPath() + "/data.txt";

    MyGraph *graph = new MyGraph(DATAPATH, 100000);

//    graph->showVertices();

    qDebug() << "Edges:";
    graph->showEdges();

    qDebug() << "Components:";
    graph->showComponents();
    return a.exec();
}
