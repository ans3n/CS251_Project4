#include "color_walk.hpp"

using namespace cs251;

std::vector<std::pair<char, int>> color_walk::calculate(graph& g, const handle startHandle) {
    std::vector<std::pair<char, int>> output;
    graph coloredGraph;

	for (auto vertex : g.getVertices()) {
        for (auto edge : vertex.m_edges) {
            //insert every vertices each colored edge in the colored graph?
        }
    }

    //building dijkstra's
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

    return output;
}
