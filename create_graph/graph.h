#pragma once


#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<fstream>
#include<list>
#include <unordered_map>

#include "Artists.h"
using namespace std;

class Graph{
    public:
    unordered_map<string, list<pair <string, int> > > adjList_;
    unordered_map<string, bool> visited;
    unordered_map<string, bool> artists; //for use in strongly connected
    int size;

    vector<string> BFStraversal; // vector is created to check if the traversal is correct order
    vector<string> DFStraversal; // vector is created to check if the traversal is correct ordergit
    unordered_map<string,int> shrt; //map to help with testing shortestpath
    unordered_map<string,int> kosahelp; //to check if the connected components are the same
    int kosaint; // integer to help the test case

    Graph();

    Graph(string filename);

    void addEdge(string artist1, string artist2);

    bool exists(string artist1, string artist2);

    void printList();

    string clean(string source);



    void addOne(string artist1, string artist2);

    void BFS(string artist);

    void viz(string artist);

    void BFSsearch(string artist1, string artist2);

    void dfs(string artist);

    void dfs2(string artist );

    vector<string> getConnected(string artist);

    void shortestPath(string source);

    void printNeighbors(string artist);

    void Kosaraju();


};





