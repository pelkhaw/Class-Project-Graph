# Class-Projects
Project - Graph Data Structure and Dijkstra’s algorithm

note:the make file is for the gcc compiler in unix

This project had us implement the graph data structure. The program can be compiled with ‘make’ and although this program has many options and functions a quick proof of concept is to run it with ‘./lab6 –g 1 –h 1 –s 1 –d 5’ the program will create this graph.

https://i.imgur.com/DCG4ZOu.png

And using Dijkstra’s algorithm calculates that the shortest path between vertex 1 and 5 is 11, and prints the path. The other options for this program are as follows.

https://i.imgur.com/xE7clmc.png

Graph type 1 is the graph shown above, graph type 2 is a strongly connected graph (Every node is connected to every other node) of –n N vertices in size, and graph type 3 is a graph with every node plotted randomly on the x-y plane, that graph is also –n N vertices in size. The operations using the –h parameter are as follows: operation 1 uses Dijkstra’s algorithm to find the shortest path from the source to destination vertex, operation 2 calculates the diameter of the graph, and operation 3 calculates the shortest path, then removes the path from the graph and calculates the next shortest path until the vertices are no longer connected.

Download Project discription: https://github.com/pelkhaw/Class-Projects/files/59741/mp6.pdf
