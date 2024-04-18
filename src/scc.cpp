#include "scc.hpp"
#include <iostream>

using namespace cs251;

int scc::search(graph& g) {
    Tarjans t;
    int countSCC = 0;

    for (auto vertex : g.getVertices()) {
        if (!t.existsIndexMap(vertex.m_handle)) {
            t.initializeOnStack(g);
            countSCC += t.strongConnect(g, vertex.m_handle);
        }
    }
    return countSCC;
}


