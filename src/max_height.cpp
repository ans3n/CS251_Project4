#include "max_height.hpp"

using namespace cs251;

int max_height::calculate(graph& g) {
    MaxHeap heap;
    UnionFind uf(g.getVertices().size());

    std::vector<handle> id;

    id.resize(g.getVertices().size());
    for (int i = 0; i < g.getVertices().size(); i++) {
        id.push_back(i);
    }

    for (auto vertex : g.getVertices()) {
        for (auto edge : vertex.m_edges) {
            if (vertex.m_handle < edge.m_destinationHandle) {
                heap.insert(edge);
            }
        }
    }

    std::vector<graph_edge> maxSpanning;
    while (maxSpanning.size() < g.getVertices().size() - 1) {
        graph_edge maxEdge = heap.getMax();

        handle u = maxEdge.m_sourceHandle;
        handle v = maxEdge.m_destinationHandle;


        if (!uf.isConnected(u, v)) {
            maxSpanning.push_back(maxEdge);
            uf.unionTogether(u, v);
        }
    }

    //return maxSpanning[maxSpanning.size() - 1].m_weight;
}