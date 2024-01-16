#ifndef LAB_H
#define LAB_H

#include <iostream>

template <typename T>
struct Node 
{
    T data;
    Node* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList 
{
private:
    Node<T>* head;
    Node<T>* tail;
public:
    LinkedList();
    ~LinkedList();

    void AddToHead(const T& value);
    void AddToTail(const T& value);
    void DeleteFromHead();
    void DeleteFromTail();
    void DeleteAll();
    void Show();
};

#endif 
