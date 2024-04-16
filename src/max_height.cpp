#include "max_height.hpp"

using namespace cs251;



int max_height::calculate(const graph& g) {
	//essentially want to get the smallest largest height - supremum of heights that can go from any city to another
    //  in the case of the example, 30 is the smallest largest height due to the cycle BGF such that to reach G 30 is
    //  the largest smallest height



}

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

    void heapifyUp(int index) {
        while (index > 0 && heap[index].m_weight > heap[(index - 1) / 2].m_weight) {
            std::swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heap.size() && heap[left].m_weight > heap[largest].m_weight) {
            largest = left;
        }
        if (right < heap.size() && heap[right].m_weight > heap[largest].m_weight) {
            largest = right;
        }
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
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
std::vector<graph_edge> kruskal(const std::vector<graph_edge>& edges, int V) {                      //v is the number of vertices
    MaxHeap Q;
    UnionFind UF(V);


    for (const auto& edge : edges) {
        Q.insert(edge);
    }

    std::vector<graph_edge> T;

    while (T.size() < V - 1) {
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


