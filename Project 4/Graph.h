#include <iostream>
#include <string>
#include <vector>
#include "Edge.h"
#include "PriorityQueue.h"


class Graph {
    private:
        int numElements;
        //std::vector<Vertex> graph
        std::vector<std::vector<Edge>> graph;
        //int *degreeArr;
        int const CAPACITY = 23134;
        //std::vector<Edge> edges;
        std::vector<Node> nodes;
        std::vector<Node> nodes2;
        PriorityQueue queue;



    public:
        Graph();
        ~Graph();
        int insert(int v1, int v2, double weight);
        void print(int v1);
        double getWeight(int v1, int v2);
        std::vector<int> getAdjacent(int v1);
        int findVertex(int v1);
        void printEdges();
        int erase(int v1);
        int mst(int x);
        int getIndex(int a, int b);
        int getNodeIndex(int x);
        //bool connected(int v1, int v2);

        void size();
        //std::vector<Edge> sortEdgeVector();

};