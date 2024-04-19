#include "color_walk.hpp"
#include <iostream>
#include <vector>
#include <climits>

using namespace cs251;

std::vector<int> color_walk::dijkstras(graph& g, const handle startHandle) {
    std::vector<graph_vertex> vertices = g.getVertices();
    int numVertices = vertices.size();
    std::vector<int> dist(numVertices);
    //std::vector<int> prev(numVertices);
    MinHeap heap;

    dist[startHandle] = 0;
    for (int i = 0; i < vertices.size(); i++) {
        if (i != startHandle) {
            dist[i] = INT_MAX;
        }
        //prev[i] = -1;
        heap.insert(i, dist[i]);
    }

    while (!heap.is_empty() && !heap.unreachable()) {
        heapNode u = heap.getMin();

        for (graph_edge edge : g.getVertex(u.m_handle).m_edges) {
            handle destination = edge.m_destinationHandle;

            if (heap.exists(destination)) {
                int d = dist[u.m_handle] + edge.m_weight;
                if (d < dist[destination]) {
                    dist[destination] = d;
                    //prev[destination] = u.m_handle;
                    heap.set(d, destination);
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
    if (smallest == INT_MAX) {
        return std::make_pair('-', -1);
    }

    return std::make_pair( col, smallest);
}

std::vector<std::pair<char, int>> color_walk::calculate(graph& g, const handle startHandle) {
    //split graph
    graph coloredGraph;
    coloredGraph.newGraph(g.getNumVertices() * 3, g.getNumEdges());

    for (auto vertex : g.getVertices()) {
        //number colored graph's vertices
        for (int i = 0; i < 3; i++) {
            coloredGraph.coloredHandle(3 * vertex.m_handle + i, vertex.m_handle);
        }
        for (graph_edge edge : vertex.m_edges) {
            coloredGraph.push(edge);
        }
    }

    //calculation part
    std::vector<int> redDistance = dijkstras(coloredGraph, startHandle * 3);
    std::vector<int> greenDistance = dijkstras(coloredGraph, startHandle * 3 + 1);
    std::vector<int> blueDistance = dijkstras(coloredGraph, startHandle * 3 + 2);

    int smallestRed = 0;
    int smallestGreen = 0;
    int smallestBlue = 0;
    std::pair<char, int> smallest;
    std::vector<std::pair<char, int>> output(g.getNumVertices());
    output[startHandle] = std::make_pair('-', 0);   //initialize and shove in start vertex
    std::vector<graph_vertex> vertices = g.getVertices();

    for (int i = 0; i < vertices.size(); i++) {
        if (i != startHandle) {
            smallestRed = minHandle(redDistance[i * 3], redDistance[i * 3 + 1], redDistance[i * 3 + 2]);
            smallestGreen = minHandle(greenDistance[i * 3], greenDistance[i * 3 + 1], greenDistance[i * 3 + 2]);
            smallestBlue = minHandle(blueDistance[i * 3], blueDistance[i * 3 + 1], blueDistance[i * 3 + 2]);

            smallest = shortestWalk(smallestRed, smallestGreen, smallestBlue);
            output[i] = smallest;
        }
    }
    return output;
}
