#include "color_walk.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace cs251;

std::vector<int> color_walk::dijkstras(graph& g, const handle startHandle) {
    std::vector<int> dist {};
    std::vector<handle> prev {};
    MinHeap heap;

    dist[startHandle] = 0;
    for (auto vertex : g.getVertices()) {
        if (vertex.m_handle != startHandle) {
            dist[vertex.m_handle] = INT_MAX;
        }
        prev[vertex.m_handle] = -1;
        heap.insert(vertex);
    }

    while (!heap.is_empty()) {
        graph_vertex u = heap.getMin();

        for (auto edge : u.m_edges) {
            if (heap.exists(edge.m_destinationHandle)) {
                int d = dist[u.m_handle] + edge.m_weight;
                if (d < dist[edge.m_destinationHandle]) {
                    dist[edge.m_destinationHandle] = d;
                    prev[edge.m_destinationHandle] = u.m_handle;
                    heap.set(d, edge.m_destinationHandle);  //not possible to have multiple?
                }
            }
        }
    }

    return dist;
}

std::pair<char, int> color_walk::shortestWalk(int redDistance, int greenDistance, int blueDistance) {
    char col = 'R';
    int smallest = redDistance;

    if (greenDistance < smallest) {
        smallest = greenDistance;
        col = 'G';
    }

    if (blueDistance < smallest) {
        smallest = blueDistance;
        col = 'B';
    }

    return std::make_pair( col, smallest);
}

std::vector<std::pair<char, int>> color_walk::calculate(graph& g, const handle startHandle) {
    graph coloredGraph;
    coloredGraph.setNumVertices(g.getNumEdges());   //assuming all directed graphs
    coloredGraph.initializeAdjacencyList(); //check if needed

    for (auto vertex : g.getVertices()) {
        int colorCount = 0;
        for (auto edge : vertex.m_edges) {
            if (edge.col != NONE) {
                coloredGraph.push(edge, colorCount);
                colorCount++;
            }
        }
    }

    std::vector<std::pair<char, int>> output;
    std::vector<int> redDistance = dijkstras(coloredGraph, startHandle * 3);
    std::vector<int> greenDistance = dijkstras(coloredGraph, startHandle * 3 + 1);
    std::vector<int> blueDistance = dijkstras(coloredGraph, startHandle * 3 + 2);

    std::pair<char, int> smallestRed;
    std::pair<char, int> smallestGreen;
    std::pair<char, int> smallestBlue;
    std::pair<char, int> smallest;
    output[startHandle] = std::make_pair('-', 0);   //initialize and shove in start vertex

    for (auto vertex : g.getVertices()) {
        if (vertex.m_handle != startHandle) {
            smallestRed = shortestWalk(redDistance[vertex.m_handle * 3], greenDistance[vertex.m_handle * 3], blueDistance[vertex.m_handle * 3]);
            smallestGreen = shortestWalk(redDistance[vertex.m_handle * 3 + 1], greenDistance[vertex.m_handle * 3 + 1], blueDistance[vertex.m_handle * 3 + 1]);
            smallestBlue = shortestWalk(redDistance[vertex.m_handle * 3], greenDistance[vertex.m_handle * 3 + 2], blueDistance[vertex.m_handle * 3 + 2]);

            smallest = smallestRed;
            //use strictly less than - if distances are the same, choose earlier color
            if (smallestGreen.second < smallest.second) {
                smallest = smallestGreen;
            }
            if (smallestBlue.second < smallest.second) {
                smallest = smallestBlue;
            }
            //unreachable node
            if (smallest.second == INT_MAX) {
                smallest = std::make_pair('-', -1);
            }
            output[vertex.m_handle] = smallest;
        }
    }
    return output;
}
