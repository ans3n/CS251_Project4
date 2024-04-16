#include "max_height.hpp"

using namespace cs251;

//path compression
handle find(handle p, std::vector<handle>& id) {
    while(p != id[p]) {
        p = id[p];
    }
    return p;
}

void unionTogether(handle p, handle q, std::vector<handle>& id) {
    handle idP = find(p, id);
    handle idQ = find(q, id);

    if (idP == idQ) {
        return;
    }
    id[idP] = idQ;
}

bool isConnected(handle p, handle q, std::vector<handle>& id) {
    return find(p, id) == find(q, id);
}

void heapifyUp(std::vector<graph_edge>& heap, int current) {
    while (current > 0) {
        int parent = (current - 1) / 2;
        if (heap[current].m_weight > heap[parent].m_weight) {
            //maxheap: swap if the current node has a larger value than its parent
            std::swap(heap[current], heap[parent]);
            current = parent;
        } else {
            // already in position
            break;
        }
    }
}

void heapifyDown(std::vector<graph_edge>& heap, int current) {
    int largestIndex = current;
    int leftIndex = 2 * current + 1;
    int rightIndex = 2 * current + 2;


    if (leftIndex < heap.size() && heap[leftIndex].m_weight > heap[largestIndex].m_weight) {
        largestIndex = leftIndex;
    }
    if (rightIndex < heap.size() && heap[rightIndex].m_weight > heap[largestIndex].m_weight) {
        largestIndex = rightIndex;
    }
    if (largestIndex != current) {
        std::swap(heap[current], heap[largestIndex]);
        heapifyDown(heap, largestIndex);
    }
}

void insert(std::vector<graph_edge>& heap, const graph_edge& edge) {
    heap.push_back(edge);
    heapifyUp(heap, heap.size() - 1);
}

graph_edge getMax(std::vector<graph_edge>& heap) {
    graph_edge maxEdge = heap.front(); //check whether front or back
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(heap, 0);
    return maxEdge;
}

//determine whether better to pass around vertex handles or vertex itself
std::vector<graph_edge> kruskal(const graph& g, std::vector<handle>& id, std::vector<graph_edge>& heap) {

    for (auto& vertex : g.getVertices()) {
        for (const auto& edge : vertex.m_edges) {
            insert(heap, edge);
        }
    }

    std::vector<graph_edge> T;
    while (T.size() < g.getVertices().size()) {
        graph_edge maxEdge = getMax(heap);
        handle u = maxEdge.m_sourceHandle;
        handle v = maxEdge.m_destinationHandle;

        if (!isConnected(u, v, id)) {
            T.push_back(maxEdge);
            unionTogether(u, v, id);
        }
    }
    return T;
}

int max_height::calculate(const graph& g) {
    std::vector<handle> id;
    std::vector<graph_edge> heap;

    //id.resize(g.getVertices().size());
    for (int i = 0; i < g.getVertices().size(); i++) {
        id.push_back(i);
    }

    std::vector<graph_edge> maxSpanning = kruskal(g, id, heap);

    return maxSpanning[maxSpanning.size() - 1].m_weight;
}


