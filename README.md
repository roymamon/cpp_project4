email:mamon8521@gmail.com

K-nary Tree with C++ and SFML


This project implements a generic K-nary tree in C++ with support for various data types, including `double`, `std::string`, and `Complex` numbers. It includes functionality to visualize the tree using the SFML library and provides several traversal methods such as pre-order, post-order, in-order, BFS, DFS
Features

Generic K-nary Tree: Supports different types of data 
Traversal Methods: Includes pre-order, post-order, in-order, BFS, DFS.
SFML Visualization: Visualizes the tree structure using SFML.
Custom Complex Number Class: Provides operations for complex numbers (addition, subtraction, multiplication, division).


`Complex.hpp`: Header file for the `Complex` class, which represents complex numbers and includes arithmetic operations and comparison operators.
`node.hpp`: Header file for the `Node` class, which represents a node in the tree.
`tree.hpp`: Header file for the `Tree` class, which represents the K-nary tree and includes methods for adding nodes, traversing the tree, and drawing the tree using SFML.
`Demo.cpp`: Demo application to showcase the usage of the `Tree` and `Complex` classes.
`Test.cpp`: Unit tests for the `Tree` and `Complex` classes using assertions.
`Makefile`: Makefile for building the project and running the tests.

   

To run the demo application, execute the following command:
make
./demo
./test

