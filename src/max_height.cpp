#include "max_height.hpp"

using namespace cs251;

class UnionFind {
    int count = 0;  //able to set to n here?
    std::vector<handle> id;       //check of what type
    std::vector<handle> size;

public:
    UnionFind(int n) {    //check
        count = n;  //check if in right spot
        for (int i = 0; i < n; i++) {
            id[i] = i;
            size[i] = 1;
        }
    }

    void unionTogether(handle p, handle q) {
        handle idP = find(p);
        handle idQ = find(q);

        if (idP == idQ) {
            return;
        }

        if (size[idP] < size[idQ]) {
            id[idP] = idQ;
            size[idQ] += size[idP];
        } else {
            id[idQ] = idP;
            size[idP] += size[idQ];
        }
        count--;
    }

    //path compression
    handle find(handle p) {
        if (p == id[p]) {
            return p;
        }
        id[p] = find(id[p]);
        return id[p];
    }

    bool isConnected(handle p, handle q) {
        return find(p) == find(q);
    }

    int getCount() {
        return count;
    }
};

class MaxHeap {
    std::vector<graph_edge> heap;

    void heapifyUp(int current) {
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

    void heapifyDown(int current) {
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
            heapifyDown(largestIndex);
        }
    }

public:

    void insert(const graph_edge& edge) {
        heap.push_back(edge);
        heapifyUp(heap.size() - 1);
    }

    graph_edge getMax() {
        graph_edge maxEdge = heap.front(); //check whether front or back
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxEdge;
    }
};

//determine whether better to pass around vertex handles or vertex itself
std::vector<graph_edge> kruskal(const graph& g) {
    MaxHeap Q;
    UnionFind UF(g.getVertices().size());
    int vertices = 0;

    for (auto& vertex : g.getVertices()) {
        for (const auto& edge : vertex.m_edges) {
            Q.insert(edge);
        }
        vertices++;
    }

    std::vector<graph_edge> T;

    while (T.size() < vertices - 1) {
        graph_edge maxEdge = Q.getMax();
        handle u = maxEdge.m_sourceHandle;
        handle v = maxEdge.m_destinationHandle;

        if (!UF.isConnected(u, v)) {
            T.push_back(maxEdge);
            UF.unionTogether(u, v);
        }
    }
    return T;
}

int max_height::calculate(const graph& g) {
    std::vector<graph_edge> maxSpanning = kruskal(g);
    graph_edge smallest = maxSpanning[0];

    for (auto& edge : maxSpanning) {
        if (edge.m_weight < smallest.m_weight) {
            smallest = edge;
        }
    }
    return smallest.m_weight;
}


