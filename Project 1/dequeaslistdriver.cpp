#include <iostream>
#include <string>
#include "deque.h"


int main() {
    std::string input_string;
    std::string temp;

    std::string url;
    int params;

    getline(std::cin,input_string);
    params = stoi(input_string.substr(2));
    Deque deque(params);
    std::cout << "success" << std::endl;
    
    while (!std::cin.eof()) {
        getline(std::cin, input_string);
        temp = input_string.substr(0, 4);
        if(temp == "push" || temp == "find"){
            if(temp == "push" && input_string.substr(0, 10) == "push_front"){
                url = input_string.substr(11);
                deque.push_front(url);
            }else if(temp == "push" && input_string.substr(0, 9) == "push_back"){
                url = input_string.substr(10);
                deque.push_back(url);
            }else if(temp == "find"){
                url = input_string.substr(5);
                deque.find(url);
            }
        }else{
            if(input_string == "pop_front"){
                deque.pop_front(0);
            }else if(input_string == "pop_back"){
                deque.pop_back(0);
        
            }else if(input_string == "clear"){
                deque.clear();
              
            }else if(input_string == "size"){
                deque.size();
             
            }else if(input_string == "front"){
                deque.front();
           
            }else if(input_string == "back"){
                deque.back();
             
            }else if(input_string == "empty"){
                deque.empty();
          
            }else if(input_string == "print"){
                deque.print();
            }else if(input_string == "exit"){
                return 0;
            }
        }

    }
    
    return 0;
}
