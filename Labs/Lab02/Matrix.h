#pragma once
#include <iostream>

const int INF = INT_MAX; // Бесконечность для недостижимых путей
const int MAX_VERTICES = 10; // Максимальное количество вершин

// Функция для ввода матрицы смежности
void inputAdjacencyMatrix(int graph[MAX_VERTICES][MAX_VERTICES], int& vertices) {
    std::cout << "Enter the number of vertices (7-10): ";
    std::cin >> vertices;
    while (vertices < 7 || vertices > 10) {
        std::cout << "Error! Enter a number between 7 and 10: ";
        std::cin >> vertices;
    }
    std::cout << "Enter the adjacency matrix (" << vertices << "x" << vertices << "):\n";
    std::cout << "For the absence of an edge enter -1, for an edge enter its weight (>0).\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            int weight;
            std::cin >> weight;
            if (weight == -1) {
                graph[i][j] = INF; // Отсутствие ребра
            }
            else if (weight > 0) {
                graph[i][j] = weight;
            }
            else {
                std::cout << "Error! The weight must be >0 or -1. Repeat entry for [" << i << "][" << j << "]: ";
                j--;
            }
        }
    }
}

// Функция для вывода матрицы смежности
void printAdjacencyMatrix(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    std::cout << "\nAdjacency matrix:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j] == INF) {
                std::cout << "-1\t";
            }
            else {
                std::cout << graph[i][j] << "\t";
            }
        }
        std::cout << std::endl;
    }
}

// Функция для поиска смежных вершин (исходящих из v)
void findAdjacentVertices(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int v) {
    if (v < 0 || v >= vertices) {
        std::cout << "Wrong! Apex " << v << " nonexistent.\n";
        return;
    }
    std::cout << "\nVertices adjacent to the vertex " << v << " (outgoing ribs):\n";
    bool hasAdjacent = false;
    for (int i = 0; i < vertices; i++) {
        if (graph[v][i] != INF) {
            std::cout << i << " ";
            hasAdjacent = true;
        }
    }
    if (!hasAdjacent) {
        std::cout << "Zero vertex (no adjacent vertices).\n";
    }
    else {
        std::cout << std::endl;
    }
}

// Функция для поиска вершин, из которых можно попасть в v
void findIncomingVertices(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int v) {
    if (v < 0 || v >= vertices) {
        std::cout << "Wrong! Apex " << v << " nonexistent.\n";
        return;
    }
    std::cout << "\nVertexes from which you can get to a vertex " << v << " (incoming edges):\n";
    bool hasIncoming = false;
    for (int i = 0; i < vertices; i++) {
        if (graph[i][v] != INF) {
            std::cout << i << " ";
            hasIncoming = true;
        }
    }
    if (!hasIncoming) {
        std::cout << "Zero node (no incoming nodes).\n";
    }
    else {
        std::cout << std::endl;
    }
}

// Алгоритм Флойда для нахождения кратчайших путей между всеми парами вершин
void floydWarshall(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    int dist[MAX_VERTICES][MAX_VERTICES]; // Матрица для хранения расстояний
    // Копирование графа в dist
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    std::cout << "\nFloyd's algorithm is executed...\n";

    // Основной цикл алгоритма
    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    // Вывод матрицы кратчайших расстояний
    std::cout << "\nShortest distance matrix (Floyd's algorithm):\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (dist[i][j] == INF) {
                std::cout << "-1\t";
            }
            else {
                std::cout << dist[i][j] << "\t";
            }
        }
        std::cout << std::endl;
    }
}