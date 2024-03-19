#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
# define INF 0x3f3f3f3f
#include "graph.h"


using namespace std;

// Default constructor for Graph class
 Graph::Graph() {}


// Constructor that takes a filename and creates a graph from the file
 Graph::Graph(string filename) {
    ifstream myFile;
    myFile.open(filename);
    int i =0;

    // Parse each line in the file to extract song and artist information
    while(myFile.good()) {
        string song, artist1, artist2, artist3, artist4, artist5;
        string line;
        getline(myFile, line);
        stringstream ss(line);
        getline(ss, song, ',');
        getline(ss, artist1, ',');
        getline(ss, artist2, ',');
        getline(ss, artist3, ',');
        getline(ss, artist4, ',');
        getline(ss, artist5, ',');

        // Add edges to the graph based on the parsed information
        if (artist1.size() >1 ) {
            if (artist3 == "") {
                artist2.pop_back();
                addEdge(artist1, artist2);
            }
            else if (!(artist3 == "") && artist4 == "") {
                artist3.pop_back();
                addEdge(artist1, artist2);
                addEdge(artist1, artist3);
                addEdge(artist2, artist3);
            }
            else if (!(artist4 == "") && artist5 == "") {
                artist4.pop_back();
                addEdge(artist1, artist2);
                addEdge(artist1, artist3);
                addEdge(artist1, artist4);
                addEdge(artist2, artist4);
                addEdge(artist2, artist3);
                addEdge(artist3, artist4);
            }
            else if (!(artist5 == "")) {
                artist5.pop_back();
                addEdge(artist1, artist2);
                addEdge(artist1, artist3);
                addEdge(artist1, artist4);
                addEdge(artist1, artist5);
                addEdge(artist2, artist3);
                addEdge(artist2, artist4);
                addEdge(artist2, artist5);
                addEdge(artist3, artist4);
                addEdge(artist3, artist5);
                addEdge(artist4, artist5);
            }
        }
        


        
    }

    size = adjList_.size();

}

// Function to add an edge between two artists
 void Graph::addEdge(string artist1, string artist2) {
    if (artist1 == "" || artist2 == "") {
         return;
    }
    if (this->exists(artist1, artist2)) {
        addOne(artist1, artist2);
        addOne(artist2, artist1);

    } else {
        this->adjList_[artist1].push_back(make_pair(artist2, 1));
        this->adjList_[artist2].push_back(make_pair(artist1, 1));
    }

 }

// Function to check if an edge exists between two artists
 bool Graph::exists(string artist1, string artist2) {
    list<pair <string, int> > tobechecked = this->adjList_[artist1];
    list< pair<string, int> >::iterator itr = tobechecked.begin();
    while (itr != tobechecked.end()) {
            if ((*itr).first == artist2) {
                return true;
            }
            ++itr;
        }
    return false;
 }


// Function to print the adjacency list representation of the graph
 void Graph::printList() {
         cout << endl << "The Adjacency List-" << endl;
    for (auto& value : this->adjList_) {
        string vertex = value.first;
        list< pair<string, int> > adjacentVertices = value.second;
        list< pair<string, int> >::iterator itr = adjacentVertices.begin();
         
        cout << "adjacencyList[" << vertex << "]";
          
        while (itr != adjacentVertices.end()) {
             cout << " -> " << (*itr).first << " (" << (*itr).second << ")";
            ++itr;
        }
         
        cout << endl;
    }
     
 }

// Function to increment the weight of an existing edge
 void Graph::addOne(string artist1, string artist2) {
    
    list< pair<string, int> >::iterator itr = this->adjList_[artist1].begin();
    while (itr != this->adjList_[artist1].end()) {
            
            if ((*itr).first == artist2) {
                (*itr).second++;
                // cout << (*itr).second << endl;
                return;
            }
            ++itr;
        }
 }


// Function to perform Breadth First Search (BFS) traversal starting from a given artist
 void Graph::BFS(string artist) {
     queue<string> tovisit;
     set<string> visited;
     tovisit.push(artist);
     visited.insert(artist);

     while (!tovisit.empty())
     {
         /* code */
        string currentartist = tovisit.front();
        tovisit.pop();
        cout << currentartist << endl;          // we could potentially remove the cout statement and store the order in the BFStraversal variable
        BFStraversal.push_back(currentartist); // vector created for testing to check if the BFS order is correct;
        list< pair<string, int> >::iterator itr = this->adjList_[currentartist].begin();
        while (itr != this->adjList_[currentartist].end()) {
            if (visited.find((*itr).first) == visited.end()) {
                tovisit.push((*itr).first);
                visited.insert((*itr).first);
            }
            itr++;
        }
     }
 }


// Function to create a Graphviz representation of the graph 
void Graph::viz(string artist) {
    unordered_map<string, list<string > > seen;


        string ns;
        for (int i = 0; i < artist.size(); i++){
            if (artist[i] != ' ') {
                ns += artist.at(i);
            }
        }
        ofstream file(ns + ".dot");

        file << "Graph {" << endl;
        file << "Gcharset=latin1" << endl;
        file << "graph[splines=true overlap=false]" << endl;

        int i = 0; //starting artist  
        bool start = false;   
        for (auto& value : this->adjList_) {
            if (value.first == artist) {
                start = true;
            }
            if (start == true) {

            

            
            string vertex = value.first;
            list< pair<string, int> > adjacentVertices = value.second;
            list< pair<string, int> >::iterator itr = adjacentVertices.begin();
       

            while (itr != adjacentVertices.end()) {
                string cleantex = clean(vertex);
                string cleantwo = clean((*itr).first);
                seen[cleantex].push_back(cleantwo);
            
            if (!(find(seen[cleantwo].begin(),seen[cleantwo].end(), cleantex ) != seen[cleantwo].end()) && i <500) { // depending on range of i, you can get different graphs
                file << "\"" + cleantex +"\"" + "--" + "\""+ cleantwo + "\"" + " [label=" + to_string((*itr).second) + "]"  << endl;
                i++;
            }

                
            ++itr;
            }
        }
         
    }
        file << "}";

        file.close();
     

}

string Graph::clean(string source) {
    string newstring;
    for ( int i = 0 ; i < source.size(); i++) {
        if(source.at(i) != '/' && source.at(i) != '-' && source.at(i) != '(' && source.at(i) != ')' && source.at(i) != '?' && source.at(i) != '\\' ) {
            newstring += source.at(i);
        }
    }
    return newstring;
}

// Performs a breadth-first search starting from artist1 and prints the traversal path and 
// checks if artist2 is in the graph
 void Graph::BFSsearch(string artist1, string artist2){
          queue<string> tovisit;
     set<string> visited;
     tovisit.push(artist1);
     visited.insert(artist1);
    //Finish when tovisit is empty
     while (!tovisit.empty())
     {
         /* code */
        string currentartist = tovisit.front();
        tovisit.pop();
        cout << currentartist << endl;
        list< pair<string, int> >::iterator itr = this->adjList_[currentartist].begin();
        if (currentartist == artist2) {
            cout << "Artist in Graph!" << endl;
            return;
        }
        while (itr != this->adjList_[currentartist].end()) {
            if (visited.find((*itr).first) == visited.end()) {
                tovisit.push((*itr).first);
                visited.insert((*itr).first);
            }
            itr++;
        }
     }
 }

// Performs a breadth-first search starting from artist and returns a vector of connected artists
vector<string> Graph::getConnected(string artist) {
     queue<string> tovisit;
     set<string> visited;
     tovisit.push(artist);
     visited.insert(artist);
     vector<string> connected;

     while (!tovisit.empty())
     {
         /* code */
        string currentartist = tovisit.front();
        tovisit.pop();
        connected.push_back(currentartist);        // we could potentially remove the cout statement and store the order in the BFStraversal variable
        BFStraversal.push_back(currentartist); // vector created for testing to check if the BFS order is correct;
        list< pair<string, int> >::iterator itr = this->adjList_[currentartist].begin();
        while (itr != this->adjList_[currentartist].end()) {
            if (visited.find((*itr).first) == visited.end()) {
                tovisit.push((*itr).first);
                visited.insert((*itr).first);
            }
            itr++;
        }
     }
     return connected;
}

  // Performs a depth-first search starting from artist and prints the traversal path
 void Graph::dfs(string artist) {
     string currentartist = artist;
     visited[currentartist] = true;
     cout << currentartist << endl;
     DFStraversal.push_back(currentartist);
     list< pair<string, int> >::iterator itr;
     for (itr = adjList_[currentartist].begin(); itr !=  adjList_[currentartist].end(); ++itr) 
     {
         if (!visited[(*itr).first]) {
             dfs((*itr).first);
         }
     }

 }

// Prints the neighbors of the given artist
 void Graph::printNeighbors(string artist) {
    
        string vertex = artist;
        list< pair<string, int> > adjacentVertices = this->adjList_[artist];
        list< pair<string, int> >::iterator itr = adjacentVertices.begin();
         
        cout << "adjacencyList[" << vertex << "]";
          
        while (itr != adjacentVertices.end()) {
             cout << " -> " << (*itr).first << " (" << (*itr).second << ")";
            ++itr;
        }
         
        cout << endl;
    
 }

// Computes the shortest path from source to all other artists and prints the shortest distances
 void Graph::shortestPath(string source) {

    priority_queue<pair<int,string>,vector<pair<int,string> >,greater<pair<int,string> > > pq;
    

    unordered_map<string, int> dist;
    vector<string> connected = getConnected(source);
    for (unsigned i =0; i <connected.size(); i++) {
        dist[connected[i]] = INF;
    }
  
    pq.push(make_pair(0, source));
    dist[source] = 0;
  

    while (!pq.empty())
    {

        string u = pq.top().second;
        pq.pop();
  
        list< pair<string, int> >::iterator i;
        for (i = adjList_[u].begin(); i != adjList_[u].end(); ++i)
        {

            string v = (*i).first;
            int weight = (*i).second;
  
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
  
    // Print shortest distances stored in dist[]
    printf("Vertex   Distance from Source\n");
    for(unordered_map<string,int>::iterator iter = dist.begin(); iter != dist.end(); ++iter)
    {
    string k =  iter->first;
    cout << k << " is " << dist[k] << " degrees of separation from " << source << endl;
    shrt.insert(make_pair(k,dist[k])); 
    }
        
}

// Helper function for Kosaraju's algorithm.Performs a depth-first search starting from source
void Graph::dfs2(string source) {
    artists[source] = 1;
   
    cout << source << " ";
    kosahelp.insert(make_pair(source, kosaint)); 
    // Recur for all the vertices adjacent to this vertex
    list< pair<string, int> >::iterator itr;
    for (itr = adjList_[source].begin(); itr != adjList_[source].end(); itr++)
        if (!artists[(*itr).first])
            dfs2((*itr).first);
}

// Implements Kosaraju's algorithm to find strongly connected components and prints 
// the strongly connected components
 void Graph::Kosaraju() {

    kosaint = 0; 
    for (auto& value : this->adjList_) {
        string vertex = value.first;
        artists[vertex] = false;
    }

    for (auto& value : this->adjList_) {
        if (artists[value.first] == 0) {
            dfs2(value.first);
            kosaint++; 
            cout << "\n";
        }
    }



   
 }

