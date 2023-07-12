#include <iostream>
#include <vector>
#include <string>

class Node{
    private:
        int studentNumber;
        std::string lastName;
        Node* next;
        
    public:
        Node(int studentNumber, std::string lastName);
        ~Node();
        friend class List;
        friend class OrderedHashTable;
};

class List {  
    private:
        Node* head;
        int length;
        
    public:
        List();
        ~List();
        friend class OrderedHashTable;
};