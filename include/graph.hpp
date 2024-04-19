#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

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
        int m_distance = -1;   //added for part 2
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
            //m_vertices.resize(numVertices);
        }

        void setNumEdges(int count) {
            numEdges = count;
        }

        void coloredHandle(int i, int newHandle) {
            m_vertices[i].m_handle = newHandle;
        }

        void initializeAdjacencyList() {
            m_vertices.resize(numVertices);
            for (int i = 0; i < numVertices; i++) {
                m_vertices.push_back({ {}, i});
            }
        }

        void newGraph(int n, int e) {
            m_vertices.resize((n));
            numVertices = n;
            numEdges = e;
        }

        std::vector<graph_vertex> getVertices() {
            return m_vertices;
        }

        graph_vertex getVertex(handle target) {
            return m_vertices[target];
        }

        void push(graph_edge edge) {
            if (edge.col == RED) {
                m_vertices[edge.m_sourceHandle * 3].m_edges.push_back({edge.m_weight, edge.m_sourceHandle * 3, edge.m_destinationHandle * 3 + 1, RED});
            } else if (edge.col == GREEN) {
                m_vertices[edge.m_sourceHandle * 3 + 1].m_edges.push_back({edge.m_weight, edge.m_sourceHandle * 3 + 1, edge.m_destinationHandle * 3 + 2, GREEN});
            } else if (edge.col == BLUE){
                m_vertices[edge.m_sourceHandle * 3 + 2].m_edges.push_back({edge.m_weight, edge.m_sourceHandle * 3 + 2, edge.m_destinationHandle * 3, BLUE});
            }
        }
    };
}
