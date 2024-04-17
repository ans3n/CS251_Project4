#pragma once
#include <iostream>
#include "graph.hpp"

namespace cs251 {

    class max_height {
    public:
        static int calculate(graph &g);
    };

    class MaxHeap {
        std::vector<graph_edge> heap{};

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
            /*for (int i = 0; i < heap.size(); i++) {
                printf("%d %d %d\n", heap[i].m_sourceHandle, heap[i].m_destinationHandle, heap[i].m_weight);
            }*/
            /*if (heap.empty()) {
                // Handle case where heap is empty
                throw std::runtime_error("Heap is empty");
            }*/

            graph_edge maxEdge = heap.at(0); //check whether front or back
            heap[0] = heap[heap.size() - 1];
            heap.pop_back();
            heapifyDown(0);
            return maxEdge;
        }

        bool is_empty() {
            return !heap.size();
        }
    };

    class UnionFind {
        std::vector<handle> id{};

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
