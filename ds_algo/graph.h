#ifndef GRAPH_H 
#define GRAPH_H

#include <string>
#include <vector>

typedef struct Edge {
    int vertex1;
    int vertex2;
} Edge;

enum REPR_TYPE {
    ADJENCY_LIST,
    ADJENCY_MATRIX,
};


class Graph {
    private:
        std::vector<std::vector<int> > adjlist;
        int num_vertices = 0;
        REPR_TYPE repr = ADJENCY_LIST;

        void parseLine(std::string line, Edge* edge);
        void addEdge(Edge edge);
        

    public: 
        Graph(std::string filename = "example1.graph");

        void printGraph();
        void setReprType(REPR_TYPE type);
};



#endif
