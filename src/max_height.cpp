#include "max_height.hpp"

using namespace cs251;

int max_height::calculate(const graph& g) {
	//essentially want to get the smallest largest height - supremum of heights that can go from any city to another
    //  in the case of the example, 30 is the smallest largest height due to the cycle BGF such that to reach G 30 is
    //  the largest smallest height

    //construct a maximum spanning tree through Prim's algorithm and take the smallest value


}

void primMaximumSpanning(const graph& g, handle h) {

    std::vector<handle> edgeTo(g.getVertices().size(), -1);
    
}
