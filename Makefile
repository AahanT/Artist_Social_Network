test : tests.o graph.o main.o catch.o
	g++ --std=c++11 create_graph/tests/test.cpp create_graph/graph.cpp -o test

tests.o : create_graph/tests/test.cpp graph.o catch.o
	g++ --std=c++11 -c create_graph/tests/test.cpp create_graph/graph.cpp  

graph.o : create_graph/graph.h create_graph/graph.cpp	
	g++ --std=c++11 -c create_graph/graph.cpp

catch.o : create_graph/tests/catch.hpp create_graph/tests/catchmain.cpp
	g++ --std=c++11 -c create_graph/tests/catchmain.cpp

main.o : create_graph/main.cpp create_graph/graph.h create_graph/graph.cpp	
	g++ --std=c++11 -c create_graph/main.cpp