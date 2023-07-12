#include <iostream>
#include <string>
#include <cmath>
#include "orderedht.h"


int main() {
    std::string command = "";
    std::string lastName;
    int studentNumber;
    int size;
    int slot;
    std::cin >> command;
    //std::cout<<command<<std::endl;
    std::cin >> size;
    //std::cout<<size<<std::endl;
    OrderedHashTable hashtable1(size);
    std::cout<<"success"<<std::endl;
	while(std::cin >> command){
        //std::cout<<command<<std::endl;
        if(command == "i"){
			std::cin >> studentNumber >> lastName;
            //std::cout<<studentNumber<<std::endl;
            //std::cout<<lastName<<std::endl;
			hashtable1.insert(studentNumber, lastName);
		}else if(command == "s"){
            //std::cout<<studentNumber<<std::endl;
            std::cin >> studentNumber;
            hashtable1.search(studentNumber);
        }else if(command == "d"){
            //std::cout<<studentNumber<<std::endl;
            std::cin >> studentNumber;
            hashtable1.deleteKey(studentNumber);
        }else if(command == "p"){
            std::cin >> slot;
            hashtable1.print(slot);
        }
	}	
    return 0;
    }