#include <iostream>
#include <string>
#include <vector>


class Node{
    private:
        int vertex;
        int key;
        int parent;

    public:
        Node(int vertex, int key, int parent);
        ~Node();
        friend class PriorityQueue;
        friend class Graph;
};



class PriorityQueue{
    private:
        std::vector<Node> queue;

    public:
        PriorityQueue();
        ~PriorityQueue();
        void insert(Node newNode);
        int maximum();
        int extractMaximum();
        bool search(int x);
        int searchIndex(int x);
        friend class Graph;
};

