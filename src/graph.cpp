#include <iostream>
#include <fstream>
#include <string>
#include "graph.hpp"

using namespace cs251;

void graph::read_edge_weights(const std::string& filePath) {
    bool part3 = false;
    if (filePath.find("part3") != std::string::npos) {
        part3 = true;
    }

    std::ifstream file(filePath);
    if (!file.is_open()) {
        return;
    }

    int e = 0;
    int v = 0;
    int source = 0;
    int destination = 0;
    int weight = 0;

    file >> v >> e;
    m_vertices.resize(numVertices);
    numEdges = e;
    numVertices = v;

    for (int i = 0; i < numVertices; i++) {
        m_vertices.push_back({ {}, i});
    }

    if (!part3) {
        //use num edges in case of directed
        for (int j = 0; j < numEdges; j++) {
            file >> source >> destination >> weight;
            file.ignore();  //ignore new line
            m_vertices[source].m_edges.push_back({weight, source, destination, NONE});
        }
    } else {
        //part 3 no weights
        for (int j = 0; j < numEdges; j++) {
            file >> source >> destination;
            file.ignore();  //ignore new line
            m_vertices[source].m_edges.push_back({1, source, destination, NONE});
        }
    }

    file.close();
}

void graph::read_edge_colors(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        return;
    }

    int v = 0;
    int e = 0;
    int source = 0;
    int destination = 0;
    int weight = 0;
    char color = 0;

    file >> v >> e;    //reads the first two integers and stores
    m_vertices.resize(numVertices);
    numEdges = e;
    numVertices = v;

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

        m_vertices[source].m_edges.push_back({weight, source, destination, col});
    }

    /*
    printf("%d %d\n", numVertices, numEdges);
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < m_vertices[i].m_edges.size(); j++) {
            enum color col = m_vertices[i].m_edges[j].col;
            char c;

            if (col == RED) {
                c = 'R';
            } else if (col == BLUE) {
                c = 'B';
            } else if (col == GREEN) {
                c = 'G';
            } else {
                c = '-';
            }
            printf("%d %d %d %c\n", i, m_vertices[i].m_edges[j].m_destinationHandle, m_vertices[i].m_edges[j].m_weight, c);
        }
    }
     */
    file.close();
}
