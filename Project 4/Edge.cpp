#include <iostream>
#include <string>
#include "Edge.h"

Edge::Edge(int v1, int v2, double weight){
    start = v1;
    end = v2;
    this->weight = weight;
}

Edge::~Edge(){}