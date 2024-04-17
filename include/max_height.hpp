#pragma once
#include <iostream>
#include "graph.hpp"

namespace cs251 {

    class max_height {
    public:
        static int calculate(graph &g);
    };

    class MaxHeap {
        std::vector<graph_edge> heap;

    public:
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
            bool sorted = false;

            while (!sorted) {
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
                    current = largestIndex;
                    sorted = false;
                } else {
                    sorted = true;
                }
            }
        }

        void insert(graph_edge& edge) {
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

    class UnionFind {
        std::vector<handle> id;

    public:
        UnionFind(int numVertices) {
            for (int i = 0; i < numVertices; i++) {
                id.push_back(i);
            }
        }

        //path compression
        handle find(handle p) {
            while(p != id[p]) {
                p = id[p];
            }
            return p;
        }

        void unionTogether(handle p, handle q) {
            handle idP = find(p);
            handle idQ = find(q);

            if (idP == idQ) {
                return;
            }
            id[idP] = idQ;
        }

        bool isConnected(handle p, handle q) {
            return find(p) == find(q);
        }
    };

}
