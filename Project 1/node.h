#include <iostream>

class Node {
    private:
        std::string data;
        Node* next;
        Node* previous;
    
    public:
        Node();
        ~Node();
        friend class Deque;
        friend class DoublyLinkedList;
        
    
};