#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;


typedef struct Edge {
    int vertex1;
    int vertex2;
} Edge;


void parseLine(string line, Edge* edge) {
    string element;
    char* l = strdup(line.c_str()); // needed

    element = strsep(&l, " ");
    edge->vertex1 = stoi(element);
    element = strsep(&l, " ");
    edge->vertex2 = stoi(element);
}


void printGraph(vector<vector<int >> adjlist) {
    for (int i = 0; i < adjlist.size(); i++) {
        cout << "Node " << i +1 << ": ";

        for (int j = 0; j < adjlist[i].size(); j++) {
            cout << adjlist[i][j] + 1 << " -> ";
        }
        cout << "NULL" << endl;
    }

}



int main() {
    string filename = "example1.graph";
    ifstream file (filename);

    string line;
    getline(file, line);


    int num_vertices = 0;
    num_vertices = stoi(line);

    cout << "there are " << num_vertices << " verticies in this graph" << endl;



    vector<vector<int> > adjlist;
    adjlist.resize(num_vertices);

    Edge edge;
    while (getline(file, line)) {
        parseLine(line, &edge);
        cout << edge.vertex1 << " & " << edge.vertex2 << endl;
        adjlist[edge.vertex1-1].push_back(edge.vertex2-1); // -1 because array = 0 indexed and file is 1 indexed;
        // adjlist[edge.vertex2-1].push_back(edge.vertex1-1);
    }


    printGraph(adjlist);

    file.close();
    return 0;
}
