#include <iostream>
#include "node.h"

Node:: Node(){
    data = "";
    next = nullptr;
    previous = nullptr;
};

Node:: ~Node(){
    next = nullptr;
    previous = nullptr;
}