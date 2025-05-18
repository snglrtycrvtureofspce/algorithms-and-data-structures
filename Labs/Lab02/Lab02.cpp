#include <iostream>
#include "Matrix.h"

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int vertices;

    // Ввод матрицы смежности
    inputAdjacencyMatrix(graph, vertices);

    // Вывод матрицы смежности
    printAdjacencyMatrix(graph, vertices);

    // Ввод вершины v для поиска смежных вершин
    int v;
    std::cout << "\nEnter vertex v (0-" << vertices - 1 << ") to find adjacent vertices: ";
    std::cin >> v;
    findAdjacentVertices(graph, vertices, v);

    // Ввод вершины v для поиска входящих вершин
    std::cout << "\nEnter a vertex v (0-" << vertices - 1 << ") to search for incoming vertices: ";
    std::cin >> v;
    findIncomingVertices(graph, vertices, v);

    // Выполнение алгоритма Флойда
    floydWarshall(graph, vertices);

    return 0;
}