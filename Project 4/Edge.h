#include <iostream>
#include <string>

class Edge{
    private:
        int start;
        int end;
        double weight;

    public:
        Edge(int v1, int v2, double weight);
        ~Edge();
        friend class Graph;

};