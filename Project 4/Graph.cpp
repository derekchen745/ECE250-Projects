#include <iostream>
#include <string>
#include <vector>
#include "Graph.h"
#include "IllegalException.h"



Graph::Graph(){
    // for(int i=0; i<23132; i++){
    //     graph[i] = 0;
    // }
    graph.resize(CAPACITY);
    //nodes.resize(CAPACITY);
    //nodes2.resize(CAPACITY);
    numElements = 0;
}


Graph::~Graph(){}

int Graph::insert(int v1, int v2, double weight){
    int vecLength = 0;
    //Check illegal argument
    if(v1 <= 0 || v1 > 23133 || v2 <= 0 || v2 > 23133 || weight < 0 || weight > 1){
        try {
            throw illegal_exception();
        }catch (illegal_exception ie) {
            ie.printExplaination();
            return 2;
        }
    }

    if(v1 == v2){
        return 1;
    }

    //Check if edge has already been inserted into the graph
    if(graph[v1].empty() == false){
        vecLength = graph[v1].size();
        for(int i=0; i<vecLength; i++){
            // if(v1 == graph[v1][i].start){
            //         //std::cout<<"ALRWADY HERE"<<std::endl;
            //         return 1;
            //     
            // }
            if(v1 == graph[v1][i].start && v2 == graph[v1][i].end){
                return 1;
            }
        }
    }

    Edge newEdge = Edge(v1, v2, weight);
    if(graph[v1].empty() && findVertex(v1) == -1){
        numElements++;
        Node newNode1 = Node(v1, -1, 0);
        nodes.push_back(newNode1);
    }
    if(graph[v2].empty() && findVertex(v2) == -1){
        numElements++;
        Node newNode2 = Node(v2, -1, 0);
        nodes.push_back(newNode2);
    }
    //std::cout<<"INSERTED"<<std::endl;
    graph[v1].push_back(newEdge);
    graph[v2].push_back(newEdge);

    // bool flag1 = true;
    // bool flag2 = true;
    // for(int i=0; i<nodes.size(); i++){
    //     if(nodes[i].vertex == v1){
    //         flag1 = false;
    //     }
    //     if(nodes[i].vertex == v2){
    //         flag2 = false;
    //     }
    // }
    // if(flag1 == true){
    //     Node newNode1 = Node(v1, -1, 0);
    //     nodes.push_back(newNode1);
    // }
    // if(flag2 == true){
    //     Node newNode2 = Node(v2, -1, 0);
    //     nodes.push_back(newNode2);
    // }
    return 0;
}

double Graph::getWeight(int v1, int v2){
    int x = 0;
    x = graph[v1][v2].weight;
    return x;

}

std::vector<int> Graph::getAdjacent(int v1){
    std::vector<int> adjacent;
    for (int i = 0; i < graph[v1].size(); i++){
        if (v1 == graph[v1][i].start){   
            //std::cout<<"PUSHBACK"<<std::endl;  
            adjacent.push_back(graph[v1][i].end);
           
        } 
    }
    return adjacent;
}

int Graph::findVertex(int v1){
    for(int i=0; i<nodes.size(); i++){
        if(nodes[i].vertex == v1){
            return i;
        }
    }
    return -1;
}

void Graph::print(int v1){
    if(v1 <= 0 || v1 > 23133){
        try {
            throw illegal_exception();
        }catch (illegal_exception ie) {
            ie.printExplaination();
            return;
        }
    }
    for (int i = 0; i < graph[v1].size(); ++i){
        if (v1 == graph[v1][i].start){     
            std::cout<<graph[v1][i].end<<" ";      
        }
    }
    std::cout<<std::endl;
}

void Graph::printEdges(){

    for (int i = 0; i < nodes.size(); ++i){
           
        std::cout<<nodes[i].vertex<<" ";  
        std::cout<<std::endl;    
        
        //std::cout<<graph[v1][i].end<< " ";   
    }
    
}



int Graph::erase(int v1){
    if(v1 <= 0 || v1 > 23133){
        try {
            throw illegal_exception();
        }catch (illegal_exception ie) {
            ie.printExplaination();
            return 2;
        }
    }

    // if(graph[v1].empty()){
    //     std::cout<<"NOTFOUND"<<std::endl;
    //     return 1;
    // }

    if(graph[v1].empty() == false){
        int vecLength = graph[v1].size();
        //std::cout<<vecLength<<std::endl;
        for(int i=0; i<vecLength; i++){
            int vertex1 = graph[v1][i].end;
            //std::cout<<vertex1<<std::endl;
            if(vertex1 != v1){
                for(int j=0; j<graph[vertex1].size(); j++){
                    if(graph[vertex1][j].end == v1){
                        graph[vertex1].erase(graph[vertex1].begin() + j);
                    }
                }
            }else{
                int vertex2 = graph[v1][i].start;
                for(int j=0; j<graph[vertex2].size(); j++){
                    if(graph[vertex2][j].end == v1){
                        graph[vertex2].erase(graph[vertex2].begin() + j);
                    }
                }
            }
        }
        numElements--;
    }else if(findVertex(v1) > -1){
        nodes.erase(nodes.begin() + findVertex(v1));
        numElements--;
    }else{
        return 1;
    }


    for(int i=0; i<nodes.size() + 1; i++){
        if(nodes[i].vertex == v1){
            nodes.erase(nodes.begin() + i);
        }
    }

    graph[v1].clear();
    return 0;
}

int Graph::mst(int x){
    nodes2 = nodes;
    //std::cout<<"HELLO"<<std::endl;
    int total = 1;
    int rootIndex = -1;
    int maxVertex = 0;
    int weight = 0;
    int index = 0;
    int key = 0;
    int jay = 0;
    std::vector<int> adjacentVertices;
    for(int i=0; i<nodes2.size(); i++){
        if(nodes2[i].vertex == x){
            rootIndex = i;
        }
    }
    if(rootIndex == -1){
        return -1;
    }
    nodes2[rootIndex].key = 100;
    PriorityQueue queue;
    queue.queue = nodes2;

    // for(int i=0; i<nodes.size(); i++){
    //     queue.insert(nodes[rootIndex]);
    // }
    while(!queue.queue.empty()){
        //std::cout<<"HELLO1"<<std::endl;

        maxVertex = queue.extractMaximum();
        // if(queue.queue[queue.searchIndex(maxVertex)].key == -1){
        //     break;
        // }
        //std::cout<<"MAXVERTEX: "<< maxVertex<<std::endl;
        adjacentVertices = getAdjacent(maxVertex);
        //std::cout<<"ADJACENCY VERTEX SIZE "<<getAdjacent(maxVertex).size()<<std::endl;
        

        for(int i=0; i<adjacentVertices.size(); i++){
            //std::cout<<"HELLO2"<<std::endl;
            //bool connected1 = connected(x, maxVertex);
            int index1 = queue.searchIndex(adjacentVertices[i]);
            int pee = getIndex(maxVertex, adjacentVertices[i]);
            weight = getWeight(maxVertex, pee);
            //key = queue.queue[index].key;
            index = getNodeIndex(adjacentVertices[i]);
            key = nodes2[index].key;
            //std::cout<<"CURRENT ADJ VERTEX: "<<adjacentVertices[i]<<std::endl;
            //std::cout<<"KEY: "<<key<<std::endl;
            if(queue.search(adjacentVertices[i]) == true && weight > key){
                for(int j=0; j<nodes2.size(); j++){
                    if(nodes2[j].vertex == adjacentVertices[i]){
                        nodes2[j].key = weight; 
                        nodes2[j].parent = maxVertex;
                        //jay = j;
                        break;
                    }
                }

                queue.queue[index1].key = weight;
               
                //total++;
                // if(nodes2[jay].parent == 0){
                //     total++;
                // }
            }
        }
        jay = getNodeIndex(maxVertex);
        if(nodes2[jay].parent > 0){
            total++;
        }
        //std::cout<<"MAXVERTEX: "<< queue.maximum()<<std::endl;
        //std::cout<<queue.queue[queue.searchIndex(queue.maximum())].key<<std::endl;
        if(queue.queue[queue.searchIndex(queue.maximum())].key == -1){
            break;
        }
    }
    //queue.insert(nodes[rootIndex]);
    
 
    // for(int i=0; i<nodes2.size(); i++){
    //     std::cout<<nodes2[i].key<<std::endl;
    // }
  
    return total;
}

int Graph::getNodeIndex(int x){
    for(int i=0; i<nodes2.size(); i++){
        if(nodes2[i].vertex == x){
            return i;
        }
    }
    return 0;
}

int Graph::getIndex(int a, int b){
    for(int i=0; i<graph[a].size(); i++){
        if(graph[a][i].end == b){
            return i;
        }
    }
    return 0;
}

// bool Graph::connected(int v1, int v2){
//     bool flag = false;
//     for(int i=0; i<graph[v1].size(); i++){
//         if(graph[v1][i].end == v2){
//             flag = true;
//         }
//     }
//     for(int i=0; i<graph[v2].size(); i++){
//         if(graph[v2][i].end == v1){
//             flag = true;
//         }
//     }
//     flag = false;
//     return flag;
// }



void Graph::size(){
    std::cout<<"number of vertices is "<<numElements<<std::endl;
}