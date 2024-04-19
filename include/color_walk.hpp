#pragma once
#include <iostream>
#include "graph.hpp"

namespace cs251 {
    struct heapNode {
        int m_handle;
        int m_distance;
    };

    class color_walk {
    public:
        static std::vector<std::pair<char, int>> calculate(graph& g, handle startHandle);
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

                if (leftIndex < heap.size() && heap[leftIndex].m_distance < heap[smallestIndex].m_distance) {
                    smallestIndex = leftIndex;
                }
                if (rightIndex < heap.size() && heap[rightIndex].m_distance < heap[smallestIndex].m_distance) {
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
            heapifyUp(heap.size() - 1);
        }

        heapNode getMin() {
            heapNode minDistance = heap.at(0);
            heap[0] = heap[heap.size() - 1];
            heap.pop_back();
            heapifyDown(0);
            return minDistance;
        }

        bool empty() {
            return !heap.size();
        }

        bool exists(handle h) {
            for (int i = 0; i < heap.size(); i++) {
                if (heap[i].m_handle == h) {
                    return true;
                }
            }
            return false;
        }

        void set(int distance, handle h) {
            for (int i = 0; i < heap.size(); i++) {
                if (heap[i].m_handle == h) {
                    heap[i].m_distance = distance;
                    heapifyUp(i);
                    break;
                }
            }
        }
    };

}
