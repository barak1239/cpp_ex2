ex1- graphs and algorithms.
This project implements a Graph class and various graph algorithms using C++.
The Graph class represents a graph using an adjacency matrix, and the Algorithms class provides implementations of common graph algorithms such as connectivity check, shortest path, cycle detection, and bipartite graph check.
In this project we have:
  Graph representation using an adjacency matrix
  Support for directed and undirected graphs
  Loading a graph from an adjacency matrix
  Printing the graph representation
  Retrieving the number of vertices and edges in the graph
  Checking if the graph is directed or undirected
  Obtaining the transposed graph
  Graph algorithms:
  Connectivity check: Determines if the graph is connected
  Shortest path: Finds the shortest path between two vertices using Dijkstra's algorithm
  Cycle detection: Checks if the graph contains a cycle
  Bipartite graph check: Determines if the graph is bipartite and returns the bipartition of vertices
  Negative cycle detection: Detects the presence of a negative cycle in the graph.


  Implementation
The project consists of the following main components: 
  Graph.hpp and Graph.cpp: Implement the Graph class with methods for loading, printing, and manipulating the graph.
  Algorithms.hpp and Algorithms.cpp: Implement the Algorithms class with various graph algorithms.
  By using algorithms that will help us like breadth-first search (BFS), depth-first search (DFS), Dijkstra's algorithm, and graph coloring we get to good implementations that are easy to understand.
  I didn't do using namespace std; as it is considered bad practice.
  Usage
To use the Graph and Algorithms classes in your own code, follow these steps:
  Include the necessary header files: "Graph.hpp" and "Algorithms.hpp".
  Create an instance of the Graph class and load the graph using the loadGraph method, passing an adjacency matrix as input.
  Call the desired methods of the Graph class to retrieve information about the graph, such as the number of vertices, number of edges, or the transposed graph.
  Use the static methods of the Algorithms class to perform graph algorithms on the loaded graph, such as connectivity check, shortest path, cycle detection, or bipartite graph check.


ex2:
This project involved enhancing the Graph class by implementing various operators to perform operations on graphs represented by adjacency matrices.
New Operators
The following operators have been added to the Graph class:
Arithmetic Operators

Addition Operator (+): Performs element-wise addition of the adjacency matrices of two graphs. The graphs must have the same number of vertices; otherwise, an invalid_argument exception is thrown.
Addition Assignment Operator (+=): Performs element-wise addition of the adjacency matrix of one graph with another, modifying the current graph.
Subtraction Operator (-): Performs element-wise subtraction of the adjacency matrices of two graphs. The graphs must have the same number of vertices; otherwise, an invalid_argument exception is thrown.
Subtraction Assignment Operator (-=): Performs element-wise subtraction of the adjacency matrix of one graph from another, modifying the current graph.
Unary Plus Operator (+): Returns a copy of the current graph.
Unary Minus Operator (-): Returns a new graph with the negated weights of the current graph's adjacency matrix.

Comparison Operators

Greater Than (>), Greater Than or Equal To (>=), Less Than (<), Less Than or Equal To (<=), Equal To (==), Not Equal To (!=): These operators compare the graphs based on their edge counts as of today until labs they will be corrected accordingly.

Scalar Multiplication Operators

Scalar Multiplication Operator (*): Multiplies the weights of the current graph's adjacency matrix by a scalar value and returns a new graph.
Scalar Multiplication Assignment Operator (*=): Multiplies the weights of the current graph's adjacency matrix by a scalar value, modifying the current graph.

Graph Multiplication Operator

Graph Multiplication Operator (*): Performs matrix multiplication between the adjacency matrices of two graphs, returning a new graph. The number of columns in the first graph must be equal to the number of rows in the second graph; otherwise, an invalid_argument exception is thrown.

Scalar Division Assignment Operator

Scalar Division Assignment Operator (/=): Divides the weights of the current graph's adjacency matrix by a scalar value, modifying the current graph. Division by zero is not allowed and will throw an invalid_argument exception.

Output Operator

Output Operator (<<): Overloads the output stream operator to print the graph's information (number of vertices and edges) and its adjacency matrix.