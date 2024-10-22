# Grafos-EDD
#include <iostream>
#include "GrafoMatriz.h" // Asegúrate de que el archivo esté correctamente referenciado

void showMatriz(Grafo<int>& grafo);

int main() {
    // Crear un grafo de tipo int
    Grafo<int> grafo;

    // Insertar vértices
    std::cout << "Insertando vértices..." << std::endl;
    grafo.insertarVertice(4);
    grafo.insertarVertice(8);
    grafo.insertarVertice(12);
    grafo.insertarVertice(16);

    // Mostrar los vértices
    std::cout << "Vértices: ";
    for (const auto& vertice : grafo.getVertices()) {
        std::cout << vertice << " ";
    }
    std::cout << std::endl;

    // Insertar aristas
    std::cout << "Insertando aristas..." << std::endl;
    grafo.insertarArista(4, 12, 10);
    grafo.insertarArista(8, 16, 15);
    grafo.insertarArista(16, 4, 20);
    grafo.insertarArista(12, 8, 25);

    // Mostrar la matriz de adyacencia
    showMatriz(grafo);

    // Mostrar las aristas
    std::cout << "Aristas desde vértice 4:" << std::endl;
    for (int i = 0; i < grafo.cantVertices(); ++i) {
        int peso = grafo.buscarArista(4, grafo.getVertices()[i]);
        if (peso != 0) {
            std::cout << "  Vértice 4 a Vértice " << grafo.getVertices()[i] << " con peso " << peso << std::endl;
        }
    }

    // Eliminar un vértice
    std::cout << "Eliminando vértice 8..." << std::endl;
    if (grafo.eliminarVertice(8)) {
        std::cout << "Vértice 8 eliminado." << std::endl;
    } else {
        std::cout << "Vértice 8 no encontrado." << std::endl;
    }

    // Mostrar los vértices después de la eliminación
    std::cout << "Vértices después de la eliminación: ";
    for (const auto& vertice : grafo.getVertices()) {
        std::cout << vertice << " ";
    }
    std::cout << std::endl;

    // Mostrar la matriz de adyacencia después de la eliminación
    showMatriz(grafo);

    // Eliminar una arista
    std::cout << "Eliminando la arista entre 12 y 16..." << std::endl;
    if (grafo.eliminarArista(12, 16)) {
        std::cout << "Arista entre 12 y 16 eliminada." << std::endl;
    } else {
        std::cout << "Arista entre 12 y 16 no encontrada." << std::endl;
    }

    // Mostrar las aristas después de la eliminación
    std::cout << "Aristas desde vértice 4 después de la eliminación:" << std::endl;
    for (int i = 0; i < grafo.cantVertices(); ++i) {
        int peso = grafo.buscarArista(4, grafo.getVertices()[i]);
        if (peso != 0) {
            std::cout << "  Vértice 4 a Vértice " << grafo.getVertices()[i] << " con peso " << peso << std::endl;
        }
    }

    return 0;
}

void showMatriz(Grafo<int>& grafo) {
    std::cout << "Matriz de Adyacencia:" << std::endl;
    int numVer = grafo.cantVertices();
    for (int i = 0; i < numVer; ++i) {
        for (int j = 0; j < numVer; ++j) {
            std::cout << grafo.getAristas()[i][j] << " "; // Asegúrate de que 'aristas' sea accesible.
        }
        std::cout << std::endl;
    }
}

