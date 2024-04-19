#pragma once

#include "graph.hpp"

namespace cs251 {

    class scc {
    private:
        int index = 0;
        std::vector<handle> stack{};
        int countSCC = 0;
        std::vector<handle> indexMap{};
        std::vector<handle> lowLinkMap{};
        std::vector<bool> onStack{};

    public:
        static int search(graph &g);

        scc(int v) {
            countSCC = 0;
            indexMap.resize(v, -1);
            lowLinkMap.resize(v, -1);
            onStack.resize(v, false);
        }

        std::vector<handle> getIndexMap() {
            return indexMap;
        }

        handle minHandle(handle u, handle v) {
            if (u < v) {
                return u;
            }
            return v;
        }

        int strongConnect(graph &g, handle v) {
            indexMap[v] = index;
            lowLinkMap[v] = index;
            index++;
            stack.push_back(v);
            onStack[v] = true;
            handle w;

            for (auto edge: g.getVertex(v).m_edges) {
                w = edge.m_destinationHandle;
                if (indexMap[w] == -1) {
                    strongConnect(g, w);
                    lowLinkMap[v] = minHandle(lowLinkMap[v], lowLinkMap[w]);
                } else if (onStack[w]) {
                    lowLinkMap[v] = minHandle(lowLinkMap[v], indexMap[w]);
                }
            }

            if (lowLinkMap[v] == indexMap[v]) {
                int w2;
                do {
                    w2 = stack[stack.size() - 1];
                    stack.pop_back();
                    onStack[w2] = false;
                } while (w2 != v);
                countSCC++;
            }

            return countSCC;
        }
    };
}