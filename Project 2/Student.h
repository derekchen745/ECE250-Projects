#include <iostream>
#include <vector>
#include <string>

class Student{
    private:
        int studentNumber;
        std::string lastName;
        
    public:
        Student();
        ~Student();
        friend class OpenHashTable;
};