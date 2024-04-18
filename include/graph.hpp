#pragma once
#include <iostream>
#include <fstream>
#include <vector>

namespace cs251
{
    typedef int handle;

    enum color
    {
        RED, GREEN, BLUE, NONE
    };

    struct graph_edge
    {
        int m_weight = -1;
        handle m_sourceHandle = -1;
        handle m_destinationHandle = -1;
        color col;
    };

    struct graph_vertex
    {
        std::vector<graph_edge> m_edges{};
        handle m_handle = -1;
        int m_distance = 0;   //added for part 2
    };

    class graph
    {
        std::vector<graph_vertex> m_vertices;
        int numVertices = 0;
        int numEdges = 0;
    public:
        void read_edge_weights(const std::string& filePath);
        void read_edge_colors(const std::string& filePath);

        int getNumVertices() {
            return numVertices;
        }

        int getNumEdges() {
            return numEdges;
        }

        void setNumVertices(int count) {
            numVertices = count;
        }

        void setNumEdges(int count) {
            numEdges = count;
        }

        void initializeAdjacencyList() {
            m_vertices.resize(numVertices);
            for (int i = 0; i < numVertices; i++) {
                m_vertices.push_back({ {}, i});
            }
        }

        std::vector<graph_vertex> getVertices() {
            return m_vertices;
        }

        void push(graph_edge edge, int colorCount) {
            m_vertices[edge.m_sourceHandle * 3 + colorCount].m_edges.push_back({edge.m_weight, edge.m_sourceHandle, edge.m_destinationHandle, edge.col});
        }
    };
}
