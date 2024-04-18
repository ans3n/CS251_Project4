#pragma once
#include "graph.hpp"

namespace cs251 {

class scc {
public:
	static int search(graph& g);
    static bool existsIndexMap(std::vector<handle> indexMap, handle target);
};

class Stack {
    std::vector<handle> stack;
public:
    void push(handle v) {

    }

    handle pop() {

    }
};

class Tarjans {
    int index = 0;
    Stack s;
    int countSCC = 0;
    std::vector<handle> indexMap;
    std::vector<handle> lowLinkMap;
    std::vector<bool> onStack;

public:
    void initializeOnStack(graph& g) {
        onStack.resize(g.getNumVertices(), false);  //check num vertices or edges
    }

    std::vector<handle> getIndexMap() {
        return indexMap;
    }

    bool existsIndexMap(handle target) {
        for (handle h : indexMap) {
            if (h == target) {
                return true;
            }
        }
        return false;
    }

    handle minHandle(handle u, handle v) {
        if (u < v) {
            return u;
        }
        return  v;
    }

    graph_vertex getVertex(graph& g, handle target) {
        for (auto vertex : g.getVertices()) {
            if (target == vertex.m_handle) {
                return vertex;
            }
        }
    }

    int strongConnect(graph& g, handle v) {
        int countSCC = 0;
        indexMap[v] = index;
        lowLinkMap[v] = index;
        index++;
        s.push(v);
        onStack[v] = true;
        handle w = 0;

        for (auto edge : getVertex(g, v).m_edges) {      //for each vertex and edge weight - check to be safe
            w = edge.m_destinationHandle;
            if (!existsIndexMap(w)) {
                strongConnect(g, w);
                lowLinkMap[v] = minHandle(lowLinkMap[v], lowLinkMap[w]);
            } else if (onStack[w]) {
                lowLinkMap[v] = minHandle(lowLinkMap[v], indexMap[w]);
            }
        }

        if (lowLinkMap[v] == indexMap[v]) {
            do {                 //check if do while or just while
                w = s.pop();
                onStack[w] = false;
                countSCC++;         //check versus needing a new SCC
            } while (w != v);
        }

        for (auto vertex : g.getVertices()) {
            if (!existsIndexMap(v)) {
                strongConnect(g, v);
            }
        }
        return countSCC;
    }

};

}
