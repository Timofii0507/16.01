#ifndef STACK2_H 
#define STACK2_H

#include "List.h" 

class Stack : public List { 
private:
    int size;
    int capacity;

public:
    Stack(int capacity);

    void push(int data);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
    void expand();
    void printStack();
    List* clone(); 
    List* operator+(List* other); 
    List* operator*(List* other); 
};

#endif
