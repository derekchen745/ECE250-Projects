#include <iostream>
#include <vector>
#include <string>
#include "Student.h"

class OpenHashTable{
    private:
        std::vector<Student> hashtable;
        int maxSize;
        int numElements;
        
    public:
        OpenHashTable(int size);

        ~OpenHashTable();

        void insert(int SN, std::string lastName);

        void search(int SN);

        void deleteKey(int SN);

};

