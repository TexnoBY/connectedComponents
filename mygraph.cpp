#include "mygraph.h"


MyGraph::MyGraph(const QString &path, float R)
{
    this->vertices = readFromTXTfile(path);

    this->numberOfVertices = this->vertices.length();
    this->R = R;
    this->vertexAdjacencyLst = new QList<int>[this->numberOfVertices];
    getVertexAdjacencyLst();
    getConnectedComponents();

}

QList<Point2d> MyGraph::readFromTXTfile(const QString &path)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)) {
        qWarning() << 'My error:' << file.errorString();
    }
    QVector<Point2d> data;

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList point = line.split(" ");
        int x = point[0].toFloat();
        int y = point[1].toFloat();

        data.push_back(Point2d(x, y));
    }

    file.close();
    return data;
}

void MyGraph::getVertexAdjacencyLst()
{
    for(int i = 0; i < this->numberOfVertices; i++)
    {
        for(int j = i + 1; j < this->numberOfVertices; j++)
        {
            if(Point2d::distanceBetweenPoints(this->vertices[i], this->vertices[j]) <= this->R)
            {
                this->vertexAdjacencyLst[i].push_back(j);
                this->vertexAdjacencyLst[j].push_back(i);
            }
        }
    }
}

void MyGraph::getConnectedComponents()
{
    bool* visitedVertices = new bool[this->numberOfVertices];
    for(int i = 0; i < this->numberOfVertices; i++)
    {
        visitedVertices[i] = false;
    }

    int components = 0;
    for (int vertice = 0; vertice < this->numberOfVertices; vertice++)
    {
        if (visitedVertices[vertice] == false)
        {
            components++;
            this->connectedComponents.resize(components);
            DFS(vertice, visitedVertices, this->connectedComponents[components - 1]);
        }
     }
    delete[] visitedVertices;
}

void MyGraph::DFS(int vertice, bool visited[], QList<int> &component)
{
    visited[vertice] = true;
    component.push_back(vertice);

    QList<int>::iterator i;
    for (
         i = this->vertexAdjacencyLst[vertice].begin();
         i != this->vertexAdjacencyLst[vertice].end();
         ++i
        )
    {
        if (!visited[*i])
        {
            DFS(*i, visited, component);
        }
    }
}

void MyGraph::showVertices()
{
    QListIterator<Point2d> i(vertices);
    while(i.hasNext())
    {
        Point2d point = i.next();
        point.show();
    }
}

void MyGraph::showEdges()
{
    for(int i = 0; i < this->numberOfVertices; i++)
    {
        qDebug() << "Edge:" << i;
        for(int j = 0; j < this->vertexAdjacencyLst[i].length(); j++)
        {

            qDebug() << this->vertexAdjacencyLst[i][j]<< " ";
        }
        qDebug() << "\n";
    }
}

void MyGraph::showComponents()
{
    for(int i = 0; i < this->connectedComponents.length(); i++)
    {
        qDebug() << "Component:" << i;
        for(int j = 0; j < this->connectedComponents[i].length(); j++)
        {

            qDebug() << this->connectedComponents[i][j]<< " ";
        }
        qDebug() << "\n";
    }
}

MyGraph::~MyGraph() { delete[] vertexAdjacencyLst; }
