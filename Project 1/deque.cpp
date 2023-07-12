#include <iostream>
#include "deque.h"

Deque::Deque(int size){
    maxSize = size;
    head = nullptr;
    tail = nullptr;
};

Deque::~Deque(){
    while(head != nullptr){ 
        Node* tempNode = head; 
        head = head -> next; 
        delete tempNode; 
    }
    head = nullptr;
    tail = nullptr;
};

//Command push_front: Adds element to the front of the deque
void Deque::push_front(std::string url){
    Node* newNode = new Node;
    if(head == nullptr){
        tail = head = newNode;
        newNode -> data = url;
    }else{
        if (numElements == maxSize){
            pop_back(1);
        }
        newNode -> next = head;
        head -> previous = newNode;
        head = newNode;
        newNode -> data = url;
    }
    std::cout << "success" <<std::endl;
    numElements++;
};

//Command push_back: Adds element to the end of the deque
void Deque::push_back(std::string url){
    Node* newNode = new Node;
    if(head == NULL){
        tail = head = newNode;
        newNode -> data = url;
    }else{
        if(numElements == maxSize){
            pop_front(1);
        }
        newNode -> previous = tail;
        tail -> next = newNode;
        tail = newNode;
        newNode -> data = url;
    }
    std::cout << "success" <<std::endl;
    numElements++;
};

//Command pop_front: Removes the first element in the deque and destroys it
void Deque::pop_front(int push){
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
        
         if(push == 0){
            std::cout << "success" << std::endl;
        }
        
    }
};

//Command pop_back: Removes the last element in the deque and destroys it
void Deque::pop_back(int push){
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
        
        if(push == 0){
            std::cout << "success" << std::endl;
        }
        
    }
};


//Command front: Returns the first element in the deque
void Deque::front(){
    if (head != nullptr){
        std::cout << "front is " << head -> data << std::endl;
    }else{
        std::cout << "failure" << std::endl;
    }
};

//Command back: Returns the last element in the deque
void Deque::back(){
    if (tail != nullptr){
        std::cout << "back is " << tail -> data << std::endl;
    }else{
        std::cout << "failure" << std::endl;
    }
};