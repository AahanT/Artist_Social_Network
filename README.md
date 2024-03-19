# Artist Social Network

Aahan Thapliyal, Arya Nallanthighall

Have you ever wondered if two seemingly unrelated artists have collaborated? What about if two artists are connected through a mutual collaboration, what interesting possibilities of unlikely musical social networks exist? For example, how many degrees of separation exist between Kanye West and The Beatles? Even more unexpected, what about Kanye and Beethoven? In our implementation of this artist social network we were able to answer these questions.

We used Spotify for Developers to create a dataset given a large spotify playlists, maybe around 10,000 songs. Using this tool, we created a CSV formatted file and create a graph out of this. In order to make sure that there is not a case where one artist gets multiple nodes, we will only create a node if that artist has been seen.

The artists in the data collected are stored as a node in the graph. The edges are treated as collaborations, i.e. if two artists have a song together, they get an edge. If two artists have done 4 songs together, they get an edge with a weight of four. This provides the graph sufficient weighting for Dijkstra's shortest path algorithm.

The Major data for this graph is included in output.csv.zip. If you want to run this, this requires a lot of storage on your computer. A viable alternative is creating your own graph to motivate to yourself that all methods can work. This block is commented out in main.cpp, provided as an example in the case that you want to run a leaner graph. 

The Algorithms that are provided in this project are BFS , DFS, BFSSearch,  Dijkstra's Shortest Path, and Kosaraju's algorithm for strongly connected components. These are all graph member variables, readable in graph.h and graph.cpp. At any time, you can call printList() or printNeighbors(artists) to get the entire graph data structure and the Neighbor artists to the given artist. You can also use viz() to visualize the connections of an artist.

## Running 

To create the **csv** file needed to generate the graph, 
1. Download **.xml** file with the songs and the artists
2. Open **scraper.py** and change `masters2.xml` to `path/to/your/file/name.xml`
3. Run **scraper.py** by entering `python scraper.py` in the terminal
4. Run **finalscraper.py** by entering `python finalscraper.py` in the terminal
5. Move the **cleaned.csv** file into ***create_graph*** folder

To get results from the graph generated from the data,
1. Enter the functions that you want to run in main() function and save the file
2. To run the **main.cpp** file, enter `g++ --std=c++11 graph.cpp -o graph` in the terminal
3. Enter `./graph` to run the main file

### Optional

You can also visualize the connections of each node in the graph. To do this we first need to install the graphviz library this can be done using the following command
```
	pip install graphviz
```
If you dont have **pip** installed then follow the instructions at https://pip.pypa.io/en/stable/installation/ 

We can then visualize the nodes by
1. Instert the line `graph.viz()` before the main() function ends in **main.cpp**
2. Run the **main.cpp** file, by entering `g++ --std=c++11 graph.cpp -o graph` in the terminal
3. Enter `./graph` to run the main file
4. Change the `dot_file_path` in **visualize_graph.py** 
5. Run **visualize_graph.py** by running `python visualize_graph.py` in the terminal

You can also test if the graph works fine by running the makefile. This can be done by entering the following in the terminal:
```
	make test
	./test
```


// ** Discussion of Test Suite