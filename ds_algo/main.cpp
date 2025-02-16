#include <iostream>
#include "graph.h"

using namespace std;


int main() {

    Graph graph{ADJENCY_LIST};
    // graph.setReprType(ADJENCY_MATRIX);
    graph.printGraph();




    return 0;
}
