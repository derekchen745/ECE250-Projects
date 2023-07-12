#include <iostream>
#include <cmath>
#include "openht.h"

OpenHashTable::OpenHashTable(int size){
    maxSize = size;
    numElements = 0;
    hashtable.resize(size);
};

OpenHashTable::~OpenHashTable(){
    hashtable.clear();
};

void OpenHashTable::insert(int SN, std::string lastName){
    bool flag = true;
    int traverse = SN % maxSize;
    int increment = int(floor(SN / maxSize)) % maxSize;
    int start = traverse;
    if(increment % 2 == 0){
        increment += 1;
    }
    if(hashtable[traverse].studentNumber == 0){//spot is empty
        flag = true;
        traverse = (traverse + increment) % maxSize;
        while(hashtable[start].studentNumber != hashtable[traverse].studentNumber){
            if(hashtable[traverse].studentNumber == SN){
                flag = false;
                break;
            }
            traverse = (traverse + increment) % maxSize;
        }
        if(flag == true) traverse = start;
    }else if(hashtable[traverse].studentNumber != 0){//spot is taken
        if(numElements == maxSize){
            flag = false;
        }else{
            while (hashtable[traverse].studentNumber != 0){//looking for empty spot
                //std::cout<<hashtable[traverse].studentNumber <<std::endl;
                if(hashtable[traverse].studentNumber ==  SN){//dupe
                    flag = false;
                    break;
                }
                traverse = (traverse + increment) % maxSize;
            }
            if(hashtable[traverse].studentNumber !=  SN){
                flag = true;
                //std::cout<< hashtable[traverse].studentNumber << " and " << hashtable[traverse].lastName <<std::endl;
            }
        }
    }
    if(flag == true){
        hashtable[traverse].studentNumber = SN;
        hashtable[traverse].lastName = lastName;
        numElements ++;
        std::cout<<"success"<<std::endl;
    }else{
        std::cout<<"failure"<<std::endl;
    }
}

void OpenHashTable::search(int SN){
    bool flag = false;
    int traverse = SN % maxSize;
    int increment = int(floor(SN / maxSize)) % maxSize;
    if(increment % 2 == 0){
        increment += 1;
    }
    int start = traverse;
    if(hashtable[traverse].studentNumber == SN){
        flag = true;
    }else{
        traverse = (traverse + increment) % maxSize;
        while(hashtable[traverse].studentNumber != hashtable[start].studentNumber){
            if(hashtable[traverse].studentNumber == SN){
                flag = true;
                break;
            }
            traverse = (traverse + increment) % maxSize;
        }
    }  
    if(flag == true){
        std::cout<<"found "<<hashtable[traverse].lastName<<" in "<<traverse<<std::endl;
    }else{
        std::cout<<"not found"<<std::endl;
    }
    
}

void OpenHashTable::deleteKey(int SN){
    bool flag = false;
    int traverse = SN % maxSize;
    int increment = int(floor(SN / maxSize)) % maxSize;
    if(increment % 2 == 0){
        increment += 1;
    }
    int start = traverse;
    if(hashtable[traverse].studentNumber == SN){
        flag = true;
    }else{
        traverse = (traverse + increment) % maxSize;
        while(hashtable[start].studentNumber != hashtable[traverse].studentNumber){
            if(hashtable[traverse].studentNumber == SN){
                flag = true;
                break;
            }
            traverse = (traverse + increment) % maxSize;
        }
    }
    if(flag == true){
        hashtable[traverse].studentNumber = 0;
        hashtable[traverse].lastName = "";
        numElements --;
        std::cout<<"success"<<std::endl;
    }else{
        std::cout<<"failure"<<std::endl;
    }
}
