#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../graph.h"
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include<fstream>
#include<vector>
#include <queue>
#include<iomanip>

using namespace std;

string filename = "../test1.csv";
Graph graph(filename);


/** 
 * This tests makes sure that all new edges are being added correctly
 * or if the the edge already exists then the integer stored in the linked 
 * list increases
 */

TEST_CASE("ADD EDGE CHECK") {

    Graph funcGraph;

    funcGraph.addEdge("Kanye West" , "JZ");
    funcGraph.addEdge("Kanye West" , "Travis Scott");
    funcGraph.addEdge("Kanye West" , "Frank Ocean");
    funcGraph.addEdge("Travis Scott" , "Kanye West");

    if(funcGraph.adjList_.find("Kanye West") != funcGraph.adjList_.end()) {
        for(auto itr = funcGraph.adjList_["Kanye West"].begin(); itr != funcGraph.adjList_["Kanye West"].end(); ++itr) {

            if((*itr).first == "JZ")
            {    
                int check = (*itr).second;
                REQUIRE(check == 1);
                        
            }
            
            if((*itr).first == "Travis Scott")
            {   
                int check = (*itr).second;
                REQUIRE(check == 2);
            }

            if((*itr).first == "Frank Ocean")
            {   
                int check = (*itr).second;
                REQUIRE(check == 1);
            }
        }
    }

    if(funcGraph.adjList_.find("JZ") != funcGraph.adjList_.end()) {
        for(auto itr = funcGraph.adjList_["JZ"].begin(); itr != funcGraph.adjList_["JZ"].end(); ++itr) {

            if((*itr).first == "Kanye West")
                {
                    int check = (*itr).second;
                    REQUIRE(check == 1);
                }
            
        }
    }

    if(funcGraph.adjList_.find("Frank Ocean") != funcGraph.adjList_.end()) {
        for(auto itr = funcGraph.adjList_["Frank Ocean"].begin(); itr != funcGraph.adjList_["Frank Ocean"].end(); ++itr) {

            if((*itr).first == "Kanye West")
                {
                    int check = (*itr).second;
                    REQUIRE(check == 1);
                }
            
        }
    }

    if(funcGraph.adjList_.find("Travis Scott") != funcGraph.adjList_.end()) {
        for(auto itr = funcGraph.adjList_["Travis Scott"].begin(); itr != funcGraph.adjList_["Travis Scott"].end(); ++itr) {

            if((*itr).first == "Kanye West")
                {
                    int check = (*itr).second;
                    REQUIRE(check == 2);
                }
            
        }
    }

    if(funcGraph.adjList_.find("Travis Scott") == funcGraph.adjList_.end() || funcGraph.adjList_.find("Frank Ocean") == funcGraph.adjList_.end() || funcGraph.adjList_.find("JZ") == funcGraph.adjList_.end() || funcGraph.adjList_.find("Kanye West") == funcGraph.adjList_.end())
    {
        FAIL("ALL ARTIST ADDED NOT FOUND");
    }


}

/**
 * This test case check if the BFS traversal function 
 * results in the same traversal as expected from the 
 * BFS algorithm
 */
TEST_CASE("BFS CHECK") {
    Graph bfsGraph;
    bfsGraph.addEdge("A", "B");
    bfsGraph.addEdge("A", "B");
    bfsGraph.addEdge("A", "B");
    bfsGraph.addEdge("A", "B");
    bfsGraph.addEdge("A", "B");
    bfsGraph.addEdge("A", "C");
    bfsGraph.addEdge("A", "C");
    bfsGraph.addEdge("A", "C");
    bfsGraph.addEdge("A", "D");
    bfsGraph.addEdge("A", "D");
    bfsGraph.addEdge("A", "E");
    bfsGraph.addEdge("B", "C");
    bfsGraph.addEdge("B", "C");
    bfsGraph.addEdge("B", "C");
    bfsGraph.addEdge("B", "D");
    bfsGraph.addEdge("B", "D");
    bfsGraph.addEdge("B", "D");
    bfsGraph.addEdge("B", "E");
    bfsGraph.addEdge("B", "E");
    bfsGraph.addEdge("C", "D");
    bfsGraph.addEdge("C", "D");
    bfsGraph.addEdge("C", "D");
    bfsGraph.addEdge("C", "D");
    bfsGraph.addEdge("C", "D");
    bfsGraph.addEdge("C", "E");
    bfsGraph.addEdge("C", "E");
    bfsGraph.addEdge("C", "E");
    bfsGraph.addEdge("D", "E");
    bfsGraph.addEdge("D", "E");
    bfsGraph.addEdge("D", "E");
    bfsGraph.addEdge("D", "E");
    cout<<"Printing BFS traversal"<<endl;
    bfsGraph.BFS("A");

    string checkarray[5] = {"A", "B", "C", "D", "E"};
    int check = 0;

    for(int i = 0 ; i < 5; i++){
        if(bfsGraph.BFStraversal[i] != checkarray[i]) {check = 1;}
    }

    REQUIRE(check == 0);


}

/**
 * This test checks if the DFS traversal function 
 * results in the same traversal as expected from 
 * DFS algorithm
 */
TEST_CASE("DFS CHECK") {
    Graph dfsGraph;
    dfsGraph.addEdge("A", "B");
    dfsGraph.addEdge("A", "B");
    dfsGraph.addEdge("A", "B");
    dfsGraph.addEdge("A", "B");
    dfsGraph.addEdge("A", "B");
    dfsGraph.addEdge("A", "C");
    dfsGraph.addEdge("A", "C");
    dfsGraph.addEdge("A", "C");
    dfsGraph.addEdge("A", "D");
    dfsGraph.addEdge("A", "D");
    dfsGraph.addEdge("A", "E");
    dfsGraph.addEdge("B", "C");
    dfsGraph.addEdge("B", "C");
    dfsGraph.addEdge("B", "C");
    dfsGraph.addEdge("B", "D");
    dfsGraph.addEdge("B", "D");
    dfsGraph.addEdge("B", "D");
    dfsGraph.addEdge("B", "E");
    dfsGraph.addEdge("B", "E");
    dfsGraph.addEdge("C", "D");
    dfsGraph.addEdge("C", "D");
    dfsGraph.addEdge("C", "D");
    dfsGraph.addEdge("C", "D");
    dfsGraph.addEdge("C", "D");
    dfsGraph.addEdge("C", "E");
    dfsGraph.addEdge("C", "E");
    dfsGraph.addEdge("C", "E");
    dfsGraph.addEdge("D", "E");
    dfsGraph.addEdge("D", "E");
    dfsGraph.addEdge("D", "E");
    dfsGraph.addEdge("D", "E");
    cout<<"Printing DFS traversal"<<endl;
    dfsGraph.dfs("A");

    string checkarray[5] = {"A", "B", "C", "D", "E"};
    int check = 0;

    for(int i = 0 ; i < 5; i++){
        if(dfsGraph.DFStraversal[i] != checkarray[i]) {check = 1;}
    }

    REQUIRE(check == 0);

}
/**
 * This test checks if the DFS and BFS functions results in the same 
 * traversal result in the graph created
 */
TEST_CASE("CHECKING IF DFS AND BFS HAVE THE SAME ORDER") {
    Graph dfsGraph;
    dfsGraph.addEdge("A", "B");
    dfsGraph.addEdge("A", "B");
    dfsGraph.addEdge("A", "B");
    dfsGraph.addEdge("A", "B");
    dfsGraph.addEdge("A", "B");
    dfsGraph.addEdge("A", "C");
    dfsGraph.addEdge("A", "C");
    dfsGraph.addEdge("A", "C");
    dfsGraph.addEdge("A", "D");
    dfsGraph.addEdge("A", "D");
    dfsGraph.addEdge("A", "E");
    dfsGraph.addEdge("B", "C");
    dfsGraph.addEdge("B", "C");
    dfsGraph.addEdge("B", "C");
    dfsGraph.addEdge("B", "D");
    dfsGraph.addEdge("B", "D");
    dfsGraph.addEdge("B", "D");
    dfsGraph.addEdge("B", "E");
    dfsGraph.addEdge("B", "E");
    dfsGraph.addEdge("C", "D");
    dfsGraph.addEdge("C", "D");
    dfsGraph.addEdge("C", "D");
    dfsGraph.addEdge("C", "D");
    dfsGraph.addEdge("C", "D");
    dfsGraph.addEdge("C", "E");
    dfsGraph.addEdge("C", "E");
    dfsGraph.addEdge("C", "E");
    dfsGraph.addEdge("D", "E");
    dfsGraph.addEdge("D", "E");
    dfsGraph.addEdge("D", "E");
    dfsGraph.addEdge("D", "E");
    cout<<"DFS traversal:"<<endl;
    dfsGraph.dfs("A");
    cout<<"BFS traversal:"<<endl;
    dfsGraph.BFS("A");
    int check = 0;

    for(int i = 0 ; i < 5; i++){
        if(dfsGraph.DFStraversal[i] != dfsGraph.BFStraversal[i]) {check = 1;}
    }

    REQUIRE(check == 0);
}

/**
 * Test to check if the shortest path is correct
 */

TEST_CASE("SHORTEST PATH TEST") {
    Graph dfsGraph;
    dfsGraph.addEdge("A", "B");
    dfsGraph.addEdge("A", "B");
    dfsGraph.addEdge("A", "B");
    dfsGraph.addEdge("A", "B");
    dfsGraph.addEdge("A", "B");
    dfsGraph.addEdge("A", "C");
    dfsGraph.addEdge("A", "C");
    dfsGraph.addEdge("A", "C");
    dfsGraph.addEdge("A", "E");
    dfsGraph.addEdge("B", "C");
    dfsGraph.addEdge("B", "C");
    dfsGraph.addEdge("B", "C");
    dfsGraph.addEdge("B", "D");
    dfsGraph.addEdge("B", "D");
    dfsGraph.addEdge("B", "D");
    dfsGraph.addEdge("B", "E");
    dfsGraph.addEdge("B", "E");
    dfsGraph.addEdge("C", "D");
    dfsGraph.addEdge("C", "D");
    dfsGraph.addEdge("C", "D");
    dfsGraph.addEdge("C", "D");
    dfsGraph.addEdge("C", "D");
    dfsGraph.addEdge("C", "E");
    dfsGraph.addEdge("C", "E");
    dfsGraph.addEdge("C", "E");
    dfsGraph.addEdge("D", "E");
    dfsGraph.addEdge("D", "E");
    dfsGraph.addEdge("D", "E");
    dfsGraph.addEdge("D", "E");
    cout<<"Shortest Path:"<<endl;
    dfsGraph.shortestPath("A");

    REQUIRE(dfsGraph.shrt["A"] == 0);
    
    REQUIRE(dfsGraph.shrt["B"] == 3);

    REQUIRE(dfsGraph.shrt["C"] == 3);

    REQUIRE(dfsGraph.shrt["D"] == 5);

    REQUIRE(dfsGraph.shrt["E"] == 1);
       
}

/**
 * Test to check if Kosaraju finds the correct
 * connected components of the graph
*/
TEST_CASE("KOSARAJU CHECK") {
    Graph dfsGraph;
    dfsGraph.addEdge("A", "B");
    dfsGraph.addEdge("A", "B");
    dfsGraph.addEdge("A", "B");
    dfsGraph.addEdge("A", "B");
    dfsGraph.addEdge("A", "B");
    dfsGraph.addEdge("A", "C");
    dfsGraph.addEdge("A", "C");
    dfsGraph.addEdge("A", "C");
    dfsGraph.addEdge("A", "E");
    dfsGraph.addEdge("B", "C");
    dfsGraph.addEdge("B", "C");
    dfsGraph.addEdge("B", "C");
    dfsGraph.addEdge("B", "D");
    dfsGraph.addEdge("B", "D");
    dfsGraph.addEdge("B", "D");
    dfsGraph.addEdge("B", "E");
    dfsGraph.addEdge("B", "E");
    dfsGraph.addEdge("C", "D");
    dfsGraph.addEdge("C", "D");
    dfsGraph.addEdge("C", "D");
    dfsGraph.addEdge("C", "D");
    dfsGraph.addEdge("C", "D");
    dfsGraph.addEdge("C", "E");
    dfsGraph.addEdge("C", "E");
    dfsGraph.addEdge("C", "E");
    dfsGraph.addEdge("D", "E");
    dfsGraph.addEdge("D", "E");
    dfsGraph.addEdge("D", "E");
    dfsGraph.addEdge("D", "E");
    dfsGraph.addEdge("Z", "Y");

    dfsGraph.Kosaraju();
    REQUIRE(dfsGraph.kosahelp["Z"] == dfsGraph.kosahelp["Y"]);
    REQUIRE(dfsGraph.kosahelp["A"] == dfsGraph.kosahelp["B"]);
    REQUIRE(dfsGraph.kosahelp["C"] == dfsGraph.kosahelp["B"]);
    REQUIRE(dfsGraph.kosahelp["C"] == dfsGraph.kosahelp["D"]);
    REQUIRE(dfsGraph.kosahelp["D"] == dfsGraph.kosahelp["E"]);
}

/**
 * This is the test case to check kosaraju with 
 * large data set
 */
TEST_CASE("LARGE KOSARAJU CHECK") {
    Graph kgraph;
    kgraph.addEdge("A","B");
    kgraph.addEdge("B","C");
    kgraph.addEdge("D","B");
    kgraph.addEdge("A","E");
    kgraph.addEdge("A","F");
    kgraph.addEdge("A","G");
    kgraph.addEdge("A","H");
    kgraph.addEdge("A","I");
    kgraph.addEdge("A","J");
    kgraph.addEdge("A","K");
    kgraph.addEdge("L","M");
    kgraph.addEdge("L","N");
    kgraph.addEdge("L","O");
    kgraph.addEdge("L","P");
    kgraph.addEdge("L","Q");
    kgraph.addEdge("L","R");
    kgraph.addEdge("L","S");
    kgraph.addEdge("L","T");
    kgraph.Kosaraju();
    REQUIRE(kgraph.kosahelp["A"] == kgraph.kosahelp["B"]);
    REQUIRE(kgraph.kosahelp["A"] == kgraph.kosahelp["C"]);
    REQUIRE(kgraph.kosahelp["A"] == kgraph.kosahelp["D"]);
    REQUIRE(kgraph.kosahelp["A"] == kgraph.kosahelp["E"]);
    REQUIRE(kgraph.kosahelp["A"] == kgraph.kosahelp["F"]);
    REQUIRE(kgraph.kosahelp["A"] == kgraph.kosahelp["G"]);
    REQUIRE(kgraph.kosahelp["A"] == kgraph.kosahelp["H"]);
    REQUIRE(kgraph.kosahelp["A"] == kgraph.kosahelp["I"]);
    REQUIRE(kgraph.kosahelp["A"] == kgraph.kosahelp["J"]);
    REQUIRE(kgraph.kosahelp["A"] == kgraph.kosahelp["K"]);
    REQUIRE(kgraph.kosahelp["L"] == kgraph.kosahelp["M"]);
    REQUIRE(kgraph.kosahelp["L"] == kgraph.kosahelp["N"]);
    REQUIRE(kgraph.kosahelp["L"] == kgraph.kosahelp["O"]);
    REQUIRE(kgraph.kosahelp["L"] == kgraph.kosahelp["P"]);
    REQUIRE(kgraph.kosahelp["L"] == kgraph.kosahelp["Q"]);
    REQUIRE(kgraph.kosahelp["L"] == kgraph.kosahelp["R"]);
    REQUIRE(kgraph.kosahelp["L"] == kgraph.kosahelp["S"]);
    REQUIRE(kgraph.kosahelp["L"] == kgraph.kosahelp["T"]);
}

/**
 * This is a test to check BFS in large dataset
 */

TEST_CASE("LARGE DATASET BFS") {
    Graph kgraph;
    kgraph.addEdge("A","B");
    kgraph.addEdge("A","C");
    kgraph.addEdge("A","D");
    kgraph.addEdge("A","E");
    kgraph.addEdge("A","F");
    kgraph.addEdge("A","G");
    kgraph.addEdge("A","H");
    kgraph.addEdge("A","I");
    kgraph.addEdge("A","J");
    kgraph.addEdge("A","K");
    kgraph.addEdge("A","L");
    kgraph.addEdge("A","M");
    kgraph.addEdge("A","N");
    kgraph.addEdge("A","O");
    kgraph.addEdge("A","P");
    kgraph.addEdge("A","Q");
    kgraph.addEdge("A","R");
    kgraph.addEdge("A","S");
    kgraph.addEdge("A","T");
    kgraph.BFS("A");

    string checkarray[] = {"A", "B", "C", "D", "E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T"};
    int check = 0;

    for(int i = 0 ; i < 20; i++){
        if(kgraph.BFStraversal[i] != checkarray[i]) {check = 1;}
    }

    REQUIRE(check == 0);

}
/**
 * This is a dfs on a larger dataset
 */
TEST_CASE("DFS ON LARGER DATASET") {
    Graph kgraph;
    kgraph.addEdge("A","B");
    kgraph.addEdge("A","C");
    kgraph.addEdge("A","D");
    kgraph.addEdge("A","E");
    kgraph.addEdge("A","F");
    kgraph.addEdge("A","G");
    kgraph.addEdge("A","H");
    kgraph.addEdge("A","I");
    kgraph.addEdge("A","J");
    kgraph.addEdge("A","K");
    kgraph.addEdge("A","L");
    kgraph.addEdge("A","M");
    kgraph.addEdge("A","N");
    kgraph.addEdge("A","O");
    kgraph.addEdge("A","P");
    kgraph.addEdge("A","Q");
    kgraph.addEdge("A","R");
    kgraph.addEdge("A","S");
    kgraph.addEdge("A","T");
    kgraph.dfs("A");

    string checkarray[] = {"A", "B", "C", "D", "E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T"};
    int check = 0;

    for(int i = 0 ; i < 20; i++){
        if(kgraph.DFStraversal[i] != checkarray[i]) {check = 1;}
    }

    REQUIRE(check == 0);
}
/**
 * This is the test to check the shortest path algorithm 
 * on larger dataset
*/
TEST_CASE("SHORTEST PATH ON LARGE DATASET") {
    Graph kgraph;
    kgraph.addEdge("A","B");
    kgraph.addEdge("A","C");
    kgraph.addEdge("A","D");
    kgraph.addEdge("A","E");
    kgraph.addEdge("A","F");
    kgraph.addEdge("A","G");
    kgraph.addEdge("A","H");
    kgraph.addEdge("A","I");
    kgraph.addEdge("A","J");
    kgraph.addEdge("A","K");
    kgraph.addEdge("A","L");
    kgraph.addEdge("A","M");
    kgraph.addEdge("A","N");
    kgraph.addEdge("A","O");
    kgraph.addEdge("A","P");
    kgraph.addEdge("A","Q");
    kgraph.addEdge("A","R");
    kgraph.addEdge("A","S");
    kgraph.addEdge("A","T");
    kgraph.addEdge("A","B");
    kgraph.addEdge("A","C");
    kgraph.addEdge("A","D");
    kgraph.addEdge("A","E");
    kgraph.addEdge("A","F");
    kgraph.addEdge("A","G");
    kgraph.addEdge("A","H");
    kgraph.addEdge("A","I");
    kgraph.addEdge("A","J");
    kgraph.addEdge("A","K");
    kgraph.addEdge("A","L");
    kgraph.addEdge("A","M");
    kgraph.addEdge("A","N");
    kgraph.addEdge("A","O");
    kgraph.addEdge("A","P");
    kgraph.addEdge("A","Q");
    kgraph.addEdge("A","R");
    kgraph.addEdge("A","S");
    kgraph.addEdge("A","T");
    kgraph.addEdge("A","L");
    kgraph.addEdge("A","M");
    kgraph.addEdge("A","N");
    kgraph.addEdge("A","O");
    kgraph.addEdge("A","P");
    kgraph.addEdge("A","Q");
    kgraph.addEdge("A","R");
    kgraph.addEdge("A","S");
    kgraph.addEdge("A","T");
    kgraph.addEdge("A","L");
    kgraph.addEdge("A","M");
    kgraph.addEdge("A","N");
    kgraph.addEdge("A","O");
    kgraph.addEdge("A","P");
    kgraph.addEdge("A","Q");
    kgraph.addEdge("A","R");
    kgraph.addEdge("A","S");
    kgraph.addEdge("A","T");
    kgraph.shortestPath("A");

    REQUIRE(kgraph.shrt["A"] == 0);
    REQUIRE(kgraph.shrt["B"] == 2);
    REQUIRE(kgraph.shrt["C"] == 2);
    REQUIRE(kgraph.shrt["D"] == 2);
    REQUIRE(kgraph.shrt["E"] == 2);
    REQUIRE(kgraph.shrt["F"] == 2);
    REQUIRE(kgraph.shrt["G"] == 2);
    REQUIRE(kgraph.shrt["H"] == 2);
    REQUIRE(kgraph.shrt["I"] == 2);
    REQUIRE(kgraph.shrt["J"] == 2);
    REQUIRE(kgraph.shrt["K"] == 2);
    REQUIRE(kgraph.shrt["L"] == 4);
    REQUIRE(kgraph.shrt["M"] == 4);
    REQUIRE(kgraph.shrt["N"] == 4);
    REQUIRE(kgraph.shrt["O"] == 4);
    REQUIRE(kgraph.shrt["P"] == 4);
    REQUIRE(kgraph.shrt["Q"] == 4);
    REQUIRE(kgraph.shrt["R"] == 4);
    REQUIRE(kgraph.shrt["S"] == 4);
    REQUIRE(kgraph.shrt["T"] == 4);

}

/**
 * This test is used to check BFS traversal 
 * over a disjoint graph
*/
TEST_CASE("CHECKING BFS ON DISJOINT GRAPH") {
    Graph kgraph;
    kgraph.addEdge("A","B");
    kgraph.addEdge("A","C");
    kgraph.addEdge("A","D");
    kgraph.addEdge("A","E");
    kgraph.addEdge("A","F");
    kgraph.addEdge("A","G");
    kgraph.addEdge("A","H");
    kgraph.addEdge("A","I");
    kgraph.addEdge("A","J");
    kgraph.addEdge("A","K");
    kgraph.addEdge("L","M");
    kgraph.addEdge("L","N");
    kgraph.addEdge("L","O");
    kgraph.addEdge("L","P");
    kgraph.addEdge("L","Q");
    kgraph.addEdge("L","R");
    kgraph.addEdge("L","S");
    kgraph.addEdge("L","T");
    kgraph.BFS("A");
    string checkarray[] = {"A", "B", "C", "D", "E","F","G","H","I","J","K"};
    int check = 0;

    for(int i = 0 ; i < 11; i++){
        if(kgraph.BFStraversal[i] != checkarray[i]) {check = 1;}
    }

    REQUIRE(check == 0);
}

/**
 * This test is used to check if DFS works on disjoint graph 
*/
TEST_CASE("DFS ON LARGE DATASET") {
    Graph kgraph;
    kgraph.addEdge("A","B");
    kgraph.addEdge("A","C");
    kgraph.addEdge("A","D");
    kgraph.addEdge("A","E");
    kgraph.addEdge("A","F");
    kgraph.addEdge("A","G");
    kgraph.addEdge("A","H");
    kgraph.addEdge("A","I");
    kgraph.addEdge("A","J");
    kgraph.addEdge("A","K");
    kgraph.addEdge("L","M");
    kgraph.addEdge("L","N");
    kgraph.addEdge("L","O");
    kgraph.addEdge("L","P");
    kgraph.addEdge("L","Q");
    kgraph.addEdge("L","R");
    kgraph.addEdge("L","S");
    kgraph.addEdge("L","T");
    kgraph.dfs("A");

    string checkarray[] = {"A", "B", "C", "D", "E","F","G","H","I","J","K"};
    int check = 0;

    for(int i = 0 ; i < 11; i++){
        if(kgraph.DFStraversal[i] != checkarray[i]) {check = 1;}
    }

    REQUIRE(check == 0);
}

/**
 * This test is used to check if the csv file is being read correctly
 * and the artists are being added correctly to the graph generated
 */

TEST_CASE("UNIQUE ARTIST CHECK") {
    
    int expected_size = graph.adjList_.size();
    // for(auto const &pair : graph.adjList_){
    //    cout<<pair.first<<endl;
    // }
    REQUIRE(expected_size == 4);
} 
/**
 * This test is used to check if the csv file is being read correctly
 * and check if all the artists added are the correct artists as in the 
 * csv file
 */
TEST_CASE("CORRECT ARTIST CHECK") {
    string art1, art2, art3, art4;
    art1 = "Ant";
    art2 = "Andy Farley";
    art3 = "Vince Watson";
    art4 = "Ben Sims";
    if(graph.adjList_.find(art1) == graph.adjList_.end())
        {FAIL("Ant not found");}
    
    if(graph.adjList_.find(art2) == graph.adjList_.end())
        {FAIL("Andy Farley not found");}

    if(graph.adjList_.find(art3) == graph.adjList_.end())
        {FAIL("Vince Watson not found");}

    if(graph.adjList_.find(art4) == graph.adjList_.end())
        {FAIL("Ben Sims not found");}
    
}


