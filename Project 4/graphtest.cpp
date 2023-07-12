#include <iostream>
#include <fstream>
#include <string>
#include "Graph.h"

int main(){
    Graph myGraph;

    std::string cmd;
    int v1;
    int v2;
    double weight;
    bool flag;
    int count;
    while(std::cin >> cmd){
        if(cmd == "load"){
            std::ifstream fin("paperCollabWeighted.txt");

            while(fin >> v1 >> v2 >> weight){
                //std::cout<<addWord<<std::endl;
                myGraph.insert(v1, v2, weight);
                
            }
            std::cout<<"success"<<std::endl;
        }
        
        else if(cmd == "i"){
            std::cin >> v1 >> v2 >> weight;
            count = myGraph.insert(v1, v2, weight);
            if(count == 0){
                std::cout<<"success"<<std::endl;
            }else if(count == 1) {
                std::cout<<"failure"<<std::endl;
            }

        }

        else if(cmd == "p"){
            std::cin >> v1;
            myGraph.print(v1);

            //std::cout<<"print1"<<std::endl;

        }
        
        else if(cmd == "d"){
            std::cin >> v1;
            count = myGraph.erase(v1);
            if(count == 0){
                std::cout<<"success"<<std::endl;
            }else if(count == 1) {
                std::cout<<"failure"<<std::endl;
            }


        }
        
        
        
        else if(cmd == "mst"){
            std::cin >> v1;
            if(myGraph.mst(v1) != -1){
                std::cout<<myGraph.mst(v1)<<std::endl;
            }else{
                std::cout<<"failure"<<std::endl;
            }
        }
        
        
        else if(cmd == "size"){
            myGraph.size();
        }
        
        else if(cmd == "exit"){
            
            return 0;
        }

        else if(cmd == "print"){
            myGraph.printEdges();
        }

        else if(cmd == "sort"){
            //myGraph.sortEdgeVector();
            //myGraph.printEdges();
        }
    }
}

