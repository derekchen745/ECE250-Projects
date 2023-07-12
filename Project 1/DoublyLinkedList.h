#include <iostream>
#include "node.h"

class DoublyLinkedList {
    protected:
    Node* head;
    Node* tail; 
    int numElements; 

    public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    
    void push_front(std::string url);

    void push_back(std::string url);

    void pop_front(int push);

    void pop_back(int push);
    //Command clear: Removes and destroys all elements in the DLL
    void clear();

    //Command size: Returns the number of elements in the DLL
    void size();

    //Command empty: Checks if the DLL is empty
    void empty();

    //Command find: Checks if a given element is in the DLL
    void find(std::string url);

    //Command print: Prints all elements in the DLL starting from the back
    void print();

    
};