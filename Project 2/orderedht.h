#include <iostream>
#include <vector>
#include <string>
#include "List.h"

class OrderedHashTable{
    
private:
    std::vector<List> hashtable;
    int numChains;
    Node* current;
    
public:
    OrderedHashTable(int size);

    ~OrderedHashTable();

    void insert(int SN, std::string lastName);

    void search(int SN);

    void deleteKey(int SN);

    void print(int i);
};