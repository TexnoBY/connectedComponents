#ifndef MYGRAPH_H
#define MYGRAPH_H

#include <QCoreApplication>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>



#include "point2d.h"


class MyGraph
{
    float R;
    int numberOfVertices;
    QList<Point2d> vertices;
    QList<int> *vertexAdjacencyLst;
    QList<QList<int>> connectedComponents;


    QList<Point2d> readFromTXTfile(const QString &path);
    void getVertexAdjacencyLst();
    void DFS(int vertice, bool visited[], QList<int> &component);
public:
    MyGraph(const QString &path, float R=10);
    void getConnectedComponents();
    void showVertices();
    void showEdges();
    void showComponents();
    ~MyGraph();
};

#endif // MYGRAPH_H
