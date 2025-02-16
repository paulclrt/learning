#include "graph.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>




void Graph::parseLine(std::string line, Edge* edge) {
    std::string element;
    char* l = strdup(line.c_str()); // needed

    element = strsep(&l, " ");
    edge->vertex1 = stoi(element);
    element = strsep(&l, " ");
    edge->vertex2 = stoi(element);
}

void Graph::addEdge(Edge edge) {
    if (this->repr == ADJENCY_LIST) {
        this->adjlist[edge.vertex1-1].push_back(edge.vertex2-1); // -1 because array = 0 indexed and file is 1 indexed;
                                                                // adjlist[edge.vertex2-1].push_back(edge.vertex1-1); // does not work at
    } else {
        std::cout << "Sorry, ADJENCY_MATRIX not implemented yet" << std::endl;
    }
}


Graph::Graph(std::string filename) {
    if (filename == "example1.graph") { std::cout << "No filename provided to consturctor... Using example1.graph as default" << std::endl; }
    std::ifstream file (filename);

    std::string line;
    std::getline(file, line);
    this->num_vertices = std::stoi(line);
    std::cout << "there are " << this->num_vertices << " verticies in this graph" << std::endl;



    this->adjlist.resize(this->num_vertices);

    // adjency list implementation
    if (this->repr == ADJENCY_LIST) {
        Edge edge;
        while (std::getline(file, line)) {
            parseLine(line, &edge);
            std::cout << edge.vertex1 << " & " << edge.vertex2 << std::endl;
            addEdge(edge);
        }
    } else {
        std::cout << "Sorry, ADJENCY_MATRIX is not yet implemented" << std::endl;
    }

    file.close();
}

void Graph::printGraph() {
    if (this->repr == ADJENCY_MATRIX) { std::cout << "SORRY, ADJENCY_MATRIX is not yet implemented" << std::endl; return; }

    for (int i = 0; i < this->adjlist.size(); i++) {
        std::cout << "Node " << i +1 << ": ";

        for (int j = 0; j < this->adjlist[i].size(); j++) {
            std::cout << this->adjlist[i][j] + 1 << " -> ";
        }
        std::cout << "NULL" << std::endl;
    }
}


void Graph::setReprType(REPR_TYPE type) {
    this->repr = type;
}
