#include <iostream>
#include "List.h"

Node::Node(int studentNumber, std::string lastName){
    this->studentNumber = studentNumber;
    this->lastName = lastName;
    next = nullptr;
};

Node::~Node(){
    studentNumber = 0;
    lastName = "";
    next = nullptr;
}

List::List(){
    head = nullptr;
    length = 0;
};

List::~List(){
    while(head != nullptr){ 
        Node* tempNode = head; 
        head = head -> next; 
        delete tempNode; 
    }
    head = nullptr;
};