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
        // this->adjlist[edge.vertex2-1].push_back(edge.vertex1-1);
    } else if (this->repr == ADJENCY_MATRIX) {
        this->adjmatrix.at(edge.vertex1-1).at(edge.vertex2-1) = 1;
        this->adjmatrix.at(edge.vertex2-1).at(edge.vertex1-1) = 1;

    } else {
        std::cout << "Sorry, ADJENCY_MATRIX not implemented yet" << std::endl;
    }
}


Graph::Graph(enum REPR_TYPE repr, std::string filename) {
    this->repr = repr;
    if (filename == "example1.graph") { std::cout << "No filename provided to consturctor... Using example1.graph as default" << std::endl; }
    std::ifstream file (filename);

    std::string line;
    std::getline(file, line);
    this->num_vertices = std::stoi(line);
    std::cout << "there are " << this->num_vertices << " verticies in this graph" << std::endl;




    // sizeing the arrays with the correct number of edges...
    if (this->repr == ADJENCY_LIST) {
        this->adjlist.resize(this->num_vertices);
    } else if (this->repr == ADJENCY_MATRIX) {
        this->adjmatrix.resize(this->num_vertices, std::vector<int>(this->num_vertices, 0));
    } else {
        std::cout << "Sorry, this method is not yet implemented" << std::endl;
    }


    Edge edge;
    while (std::getline(file, line)) {
        parseLine(line, &edge);
        std::cout << edge.vertex1 << " & " << edge.vertex2 << std::endl;
        addEdge(edge);
    }

    file.close();
}

void Graph::printGraph() {
    if (this->repr == ADJENCY_MATRIX) {
        // std::cout << this->adjmatrix.size() << std::endl;
        for (int i = 0; i < this->adjmatrix.size(); i++) {
            for (int j = 0; j < this->adjmatrix.at(i).size(); j++) {
                std::cout << this->adjmatrix.at(i).at(j) << " ";
                // std::cout << i << " " << j << std::endl;
            }
            std::cout << std::endl;
        }

    } else if (this->repr == ADJENCY_LIST) {
        for (int i = 0; i < this->adjlist.size(); i++) {
            std::cout << "Node " << i +1 << ": ";

            for (int j = 0; j < this->adjlist[i].size(); j++) {
                std::cout << this->adjlist[i][j] + 1 << " -> ";
            }
            std::cout << "NULL" << std::endl;
        }
    }
}


void Graph::setReprType(REPR_TYPE type) {
    this->repr = type;
}
