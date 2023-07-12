#include <iostream>
#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList(){
    head = nullptr;
    tail = nullptr;
    numElements = 0;
};

DoublyLinkedList::~DoublyLinkedList(){
    while(head != nullptr){ 
        Node* tempNode = head; 
        head = head -> next; 
        delete tempNode; 
    }
    head = nullptr;
    tail = nullptr;
};

void DoublyLinkedList::push_front(std::string url){
    Node* newNode = new Node;
    if(head == nullptr){
        tail = head = newNode;
        newNode -> data = url;
    }else{
        newNode -> next = head;
        head -> previous = newNode;
        head = newNode;
        newNode -> data = url;
    }
    std::cout << "success" <<std::endl;
    numElements++;
};

void DoublyLinkedList::push_back(std::string url){
    Node* newNode = new Node;
    if(tail == nullptr){
        tail = head = newNode;
        newNode -> data = url;
    }else{
        newNode -> previous = tail;
        tail -> next = newNode;
        tail = newNode;
        newNode -> data = url;
    }
    std::cout << "success" <<std::endl;
    numElements++;
};

void DoublyLinkedList::pop_front(int push){
    if (head == nullptr){
         std::cout << "failure" << std::endl;
    }else{
        Node* temp = head;
        head = head -> next;
        if (head == nullptr){
            tail = nullptr;
        }
        else {
            head -> previous = nullptr;
            delete temp;
            temp = nullptr;
        }
        numElements--;
        std::cout << "success" << std::endl;
    }
};

void DoublyLinkedList::pop_back(int push){
    if (tail == nullptr){
         std::cout << "failure" << std::endl;
    }else{
        Node* temp = tail;
        tail = tail -> previous;

        if (tail == nullptr){
            head = nullptr;
        }
        else {
            tail -> next = nullptr;
            delete temp;
            temp = nullptr;
        }
        
        numElements--;
        std::cout << "success" << std::endl;
        
    }
};

void DoublyLinkedList::clear(){
    tail = nullptr; 
    while(head != nullptr){ 
        Node* tempNode = head; 
        head = head -> next; 
        delete tempNode; 
        tempNode = nullptr;
    }
    numElements = 0;
    std::cout << "success" << std::endl;
};

void DoublyLinkedList::size(){
    std::cout << "size is " << numElements << std::endl;
};

void DoublyLinkedList::empty(){
    if (numElements == 0){
        std::cout << "empty 1" << std::endl;
    }else{
        std::cout << "empty 0" << std::endl;
    }
};

void DoublyLinkedList::find(std::string url){
    int length = url.length();
    if(head == nullptr){
        std::cout << "not found " << url << std::endl;
        return;
    }else{
        Node *tempNode = tail;
        for(int i=0; i<numElements; i++){
            if((tempNode -> data).substr(0,length) == url){
                std::cout << "found " << tempNode -> data << std::endl;
                return;
            }
            tempNode = tempNode -> previous;
        }
        std::cout << "not found " << url << std::endl;
    }
};

void DoublyLinkedList::print(){
    if (head != nullptr){
        Node *tempNode = tail;
        for(int i=0; i<numElements; i++){
            std::cout << tempNode -> data << std::endl;
            tempNode = tempNode -> previous;
        }
    }
};
