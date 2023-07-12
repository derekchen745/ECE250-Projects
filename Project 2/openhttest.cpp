#include <iostream>
#include <string>
#include <cmath>
#include "openht.h"


int main() {
    std::string command = "";
    std::string lastName;
    int studentNumber;
    int size;
    std::cin >> command;
    //std::cout<<command<<std::endl;
    std::cin >> size;
    //std::cout<<size<<std::endl;
    OpenHashTable hashtable1(size);
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
        }
	}	
    return 0;
}
