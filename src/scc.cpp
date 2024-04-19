#include "scc.hpp"
#include <iostream>

using namespace cs251;

int scc::search(graph& g) {
    scc t(g.getNumVertices());

    for (auto vertex : g.getVertices()) {
        if (t.indexMap[vertex.m_handle] == -1) {
            t.strongConnect(g, vertex.m_handle);
        }
    }
    return t.countSCC;
}


