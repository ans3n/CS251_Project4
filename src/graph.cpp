#include <iostream>
#include <fstream>
#include <string>
#include "graph.hpp"

using namespace cs251;

void graph::read_edge_weights(const std::string& filePath) {
    std::ifstream file(filePath);                                               //check if ifstream is used or something else
    if (!file.is_open()) {
        return;
    }

    int numEdges = 0;
    int numVertices = 0;
    int source = 0;
    int destination = 0;
    int weight = 0;

    file >> numVertices >> numEdges;    //reads the first two integers and stores
    m_vertices.resize(numVertices);

    for (int i = 0; i < numVertices; i++) {
        m_vertices.push_back({ {}, i});
    }

    //use num edges in case of directed
    for (int j = 0; j < numEdges; j++) {
        file >> source >> destination >> weight;
        file.ignore();  //ignore new line
        m_vertices[source].m_edges.push_back({weight, source, destination, NONE});    //check if source needed
    }
    file.close();
}

void graph::read_edge_colors(const std::string& filePath) {
    std::ifstream file(filePath);                                               //check if ifstream is used or something else
    if (!file.is_open()) {
        return;
    }

    int numEdges = 0;
    int numVertices = 0;
    int source = 0;
    int destination = 0;
    int weight = 0;
    char color = 0;

    file >> numVertices >> numEdges;    //reads the first two integers and stores
    m_vertices.resize(numVertices);

    for (int i = 0; i < numVertices; i++) {
        m_vertices.push_back({ {}, i});
    }

    //use num edges in case of directed
    for (int i = 0; i < numEdges; i++) {
        file >> source >> destination >> weight >> color;
        file.ignore();  //ignore new line
        enum color col;

        if (color == 'R') {
           col = RED;
        } else if (color == 'B') {
            col = BLUE;
        } else if (color == 'G') {
            col = GREEN;
        } else {
            col = NONE;
        }

        m_vertices[source].m_edges.push_back({weight, source, destination, col});   //check if source needed
    }
    file.close();
}
