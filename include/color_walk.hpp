#pragma once
#include <iostream>
#include "graph.hpp"

namespace cs251 {

    class color_walk {
    public:
        static std::vector<std::pair<char, int>> calculate(graph& g, handle startHandle);
    };

    class MinHeap {
        std::vector<graph_vertex> heap{};

    public:
        void heapifyUp(int current) {
            while (current > 0) {
                int parent = (current - 1) / 2;
                if (heap[current].m_distance > heap[parent].m_distance) {
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


                if (leftIndex < heap.size() && heap[leftIndex].m_distance > heap[largestIndex].m_distance) {
                    largestIndex = leftIndex;
                }
                if (rightIndex < heap.size() && heap[rightIndex].m_distance > heap[largestIndex].m_distance) {
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

        void insert(graph_vertex& vertex) {
            heap.push_back(vertex);
            heapifyDown(heap.size() - 1);   //changed to reverse
        }

        graph_vertex getMin() {
            /*for (int i = 0; i < heap.size(); i++) {
                printf("%d %d %d\n", heap[i].m_sourceHandle, heap[i].m_destinationHandle, heap[i].m_distance);
            }*/
            /*if (heap.empty()) {
                // Handle case where heap is empty
                throw std::runtime_error("Heap is empty");
            }*/

            graph_vertex minDistance = heap.at(0); //to change?
            heap[0] = heap[heap.size() - 1];
            heap.pop_back();
            heapifyUp(0);   //changed to reverse
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
