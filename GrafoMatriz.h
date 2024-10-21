#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H
#include <vector>

template<class T>
class Grafo {
    private:
        std::vector<T> vertices;
        int** aristas;
    public:
        Grafo();
        void setVertices(std::vector<T> v);
        void setAristas (int** a);
        std::vector<T> getVertices();
        int** getAristas();
        int cantVertices();
        int cantAristas();
        int buscarVertice(T vert);
        bool insertarVertice(T vert);
        bool insertarArista(T ori, T des, int cos);
        int buscarArista(T ori, T des);
        bool eliminarVertice(T ver);
        bool eliminarArista (T ori, T des);    
};

#include "Grafo.hxx"
#endif
