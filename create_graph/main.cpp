#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include<fstream>
#include<vector>
#include <queue>
#include<iomanip>


using namespace std;

// Includes all the header files for clarity.
#include "graph.h"
#include "graph.cpp"
#include "graphviz.h"
#include "graphviz.cpp"

int main() {
    string filename = "cleaned.csv";
    Graph graph(filename);
    // **Alternative to reading cleaned.csv. Using add edge, you can add as many nodes as possible. 
    // Graph graph;

    // graph.addEdge("a", "b");
    // graph.addEdge("c", "b");
    // graph.addEdge("d", "b");

    // graph.addEdge("e", "f");

   
    // graph.printNeighbors("Kanye West");
    // std::cout << "graph.size() is " << graph.adjList_.size() << '\n';

    graph.Kosaraju();




     
}

