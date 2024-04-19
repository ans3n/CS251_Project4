#pragma once
#include <iostream>
#include "graph.hpp"

namespace cs251 {

    class color_walk {
    public:
        static std::vector<std::pair<char, int>> calculate(graph& g, handle startHandle);  //static
        static std::vector<int> dijkstras(graph& g, const handle startHandle);
        graph splitColors(graph &g);
        static std::pair<char, int> shortestWalk(int red, int green, int blue);
        static handle minHandle(handle u, handle v, handle w) {
            handle smallest = u;

            if (v < smallest) {
                smallest = v;
            }
            if (w < smallest) {
                smallest = w;
            }
            return smallest;
        }

    };

    class MinHeap {
        struct heapNode {
            int m_handle;
            int m_distance;
        };

    private:
        std::vector<heapNode> heap{};

    public:
        bool unreachable() {
            return heap[0].m_distance == INT_MAX;
         }

        void heapifyUp(int current) {
            while (current > 0) {
                int parent = (current - 1) / 2;
                if (heap[current].m_distance < heap[parent].m_distance) {
                    //minheap: swap if the current node has a smaller value than its parent
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
                int smallestIndex = current;
                int leftIndex = 2 * current + 1;
                int rightIndex = 2 * current + 2;

                if (leftIndex < heap.size() && heap[leftIndex].m_distance < heap[smallestIndex].m_distance) {    //changed to <
                    smallestIndex = leftIndex;
                }
                if (rightIndex < heap.size() && heap[rightIndex].m_distance < heap[smallestIndex].m_distance) {  //changed to <
                    smallestIndex = rightIndex;
                }
                if (smallestIndex != current) {
                    std::swap(heap[current], heap[smallestIndex]);
                    current = smallestIndex;
                    sorted = false;
                } else {
                    sorted = true;
                }
            }
        }

        void insert(int handle, int weight) {
            heapNode node;
            node.m_distance = weight;
            node.m_handle = handle;

            heap.push_back(node);
            heapifyUp(heap.size() - 1);   //still?
        }

        heapNode getMin() {
            /*for (int i = 0; i < heap.size(); i++) {
                printf("%d %d %d\n", heap[i].m_sourceHandle, heap[i].m_destinationHandle, heap[i].m_distance);
            }*/
            /*if (heap.empty()) {
                // Handle case where heap is empty
                throw std::runtime_error("Heap is empty");
            }*/

            heapNode minDistance = heap.at(0);
            heap[0] = heap[heap.size() - 1];
            heap.pop_back();
            heapifyDown(0);   //change to reverse?
            return minDistance;
        }

        bool is_empty() {
            return !heap.size();
        }

        bool exists(handle h) {
            for (auto vertex : heap) {
                if (vertex.m_handle == h) {
                    return true;
                }
            }
            return false;
        }

        void set(int distance, handle h) {
            for (auto vertex: heap) {
                if (vertex.m_handle == h) {
                    vertex.m_distance = distance;
                    break;
                }
            }
        }
    };

}
