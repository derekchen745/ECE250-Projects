#include <iostream>
#include <string>
#include <vector>
#include "PriorityQueue.h"

Node::Node(int vertex, int key, int parent){
    this->vertex = vertex;
    this->key = key;
    this->parent = parent;
    // vertex = vertex;
    // key = key;
    // parent = parent;
}

Node::~Node(){}

PriorityQueue::PriorityQueue(){
    //queue.resize(23134);
}

PriorityQueue::~PriorityQueue(){}

void PriorityQueue::insert(Node newNode){
    queue.push_back(newNode);
}

int PriorityQueue::maximum(){
    int max = -1;
    int maxIndex = 0;
    for(int i=0; i<queue.size(); i++){
        //std::cout<<"KEY IN REGULAR MAX: "<<queue[i].key<<std::endl;
        //std::cout<<"MAX: "<<max<<std::endl;
        if(queue[i].key > max){
            max = queue[i].key;
            maxIndex = i;
        }
    }
    return queue[maxIndex].vertex;;
}

int PriorityQueue::extractMaximum(){
    int max = -100;
    int maxIndex = 0;
    int x = 0;
    for(int i=0; i<queue.size(); i++){
        //std::cout<<"KEY IN EXTRACT MAX: "<<queue[i].key<<std::endl;
        //std::cout<<"MAX: "<<max<<std::endl;
        if(queue[i].key > max){
            max = queue[i].key;
            maxIndex = i;
        }
    }
    x = queue[maxIndex].vertex;
    queue.erase(queue.begin() + maxIndex);
    return x;
}

bool PriorityQueue::search(int x){
    for(int i=0; i<queue.size(); i++){
        if(queue[i].vertex == x){
            return true;
        }
    }
    return false;
}

int PriorityQueue::searchIndex(int x){
    for(int i=0; i<queue.size(); i++){
        if(queue[i].vertex == x){
            return i;
        }
    }
    return 0;
}