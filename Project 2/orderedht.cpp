#include <iostream>
#include <string>
#include <cmath>
#include "orderedht.h"

OrderedHashTable::OrderedHashTable(int size){
    numChains = size;
    current = nullptr;
    hashtable.resize(size);
};

OrderedHashTable::~OrderedHashTable(){
    current = nullptr;
    hashtable.clear();
};

void OrderedHashTable::insert(int SN, std::string lastName){
    Node* newNode = new Node(SN, lastName);
    int traverse = SN % numChains;
    current = hashtable[traverse].head; 
    if(hashtable[traverse].head == nullptr){        //head is empty at given slot
        hashtable[traverse].head = newNode;
        hashtable[traverse].length ++;
        std::cout<<"success"<<std::endl;
    }else{                                          //head is not empty at given slot
        bool flag = true;
        Node* previous = hashtable[traverse].head;
        while(current != nullptr){
            if(current -> studentNumber == SN){     //check if key is already in list
                flag = false;
                break;
            }
            previous = current;
            current = current -> next;
        }
        if(flag == true){
            previous -> next = newNode;
            hashtable[traverse].length ++;
            std::cout<<"success"<<std::endl;
        }else{
            std::cout<<"failure"<<std::endl;
        }
    }
}

void OrderedHashTable::search(int SN){
    int traverse = SN % numChains;
    current = hashtable[traverse].head;
    bool flag = false;
    for(int i=0; i<hashtable[traverse].length; i++){
        if(current -> studentNumber == SN){
            flag = true;
            break;
        }
        current = current -> next;
    }
    if(flag == true){
        std::cout<<"found "<<current -> lastName<<" in "<<traverse<<std::endl;
    }else{
        std::cout<<"not found"<<std::endl;
    }
}

void OrderedHashTable::deleteKey(int SN){
    int traverse = SN % numChains;
    bool flag = false;
    current = hashtable[traverse].head;
    Node* previous = hashtable[traverse].head;
    for(int i=0; i<hashtable[traverse].length; i++){
        if (current -> studentNumber == SN){
            flag = true;
            break;
        }
        previous = current;
        current = current -> next;
    }

    if(flag == false || hashtable[traverse].head == nullptr){       //list is empty or key is not in list
        flag = false;
    }else if(flag == true && current == hashtable[traverse].head){  //key is the head of list
        if(current -> next == nullptr){                             //head is the only thing in the list
            hashtable[traverse].head = nullptr;
        }else{                                                      //head is not the only thing in the list
            hashtable[traverse].head = current -> next;
        }
    }else if(flag == true){                                         //list is not empty and key is not head
        previous -> next = current -> next;
    }

    if(flag == true){
        hashtable[traverse].length --;
        std::cout<<"success"<<std::endl;
    }else{
        std::cout<<"failure"<<std::endl;
    }
}

void OrderedHashTable::print(int slot){
    if(hashtable[slot].head == nullptr){
        std::cout<<"chain is empty"<<std::endl;
    }else{
        current = hashtable[slot].head;
        std::vector<int> sorted;
        for(int i=0; i<hashtable[slot].length; i++){
            sorted.push_back(current -> studentNumber);
            current = current -> next;
        }
        int j, k , min;
        int swap;
        for(j = 0; j < hashtable[slot].length-1; j++){
            min = j;
            for(k = j+1; k < hashtable[slot].length; k++){
                if(sorted[k] < sorted[min]){
                    min = k;
                }
                swap = sorted[j];
                sorted[j] = sorted[min];
                sorted[min] = swap;
            }
        }
        for(int i=hashtable[slot].length-1; i >= 0; i--){
            std::cout<<sorted[i]<< " ";
        }
        std::cout<<std::endl;
    }
}
