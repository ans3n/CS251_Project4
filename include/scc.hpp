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

        static bool existsIndexMap(std::vector<handle> indexMap, handle target);

        scc(int v) {
            countSCC = 0;
            indexMap.resize(v, -1);
            lowLinkMap.resize(v, -1);
            onStack.resize(v, false);
        }

        /*void initializeOnStack(graph &g) {
            onStack.resize(g.getNumVertices(), false);  //check num vertices or edges
        }*/

        std::vector<handle> getIndexMap() {
            return indexMap;
        }

        /*bool existsIndexMap(handle target) {
            for (handle h: indexMap) {
                if (h == target) {
                    return true;
                }
            }
            return false;
        }*/

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

            for (auto edge: g.getVertex(v).m_edges) {      //for each vertex and edge weight - check to be safe
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
                do {                 //check if do while or just while
                    w2 = stack[stack.size() - 1];
                    stack.pop_back();
                    onStack[w2] = false;
                } while (w2 != v);
                countSCC++;         //check versus needing a new SCC
            }

            /*for (auto vertex: g.getVertices()) {
                if (!existsIndexMap(v)) {
                    strongConnect(g, v);
                }
            }*/
            return countSCC;
        }
    };
}