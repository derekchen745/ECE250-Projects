#include <iostream>
#include "DoublyLinkedList.h"

class Deque: public DoublyLinkedList {

    // class variables
	private:
	int maxSize;

    // class functions
    public:
    Deque(int size);
    ~Deque();

    void push_front(std::string url);

    void push_back(std::string url);

     void pop_front(int push);

    void pop_back(int push);
    
    void front();

    void back();

};


