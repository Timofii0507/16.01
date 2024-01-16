#include "lab.h"

using namespace std;

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList() 
{
    DeleteAll();
}

template <typename T>
void LinkedList<T>::AddToHead(const T& value) 
{
    Node<T>* newNode = new Node<T>(value);
    if (!head) 
    {
        head = tail = newNode;
    }
    {
        newNode->next = head;
        head = newNode;
    }
}

template <typename T>
void LinkedList<T>::AddToTail(const T& value) 
{
    Node<T>* newNode = new Node<T>(value);
    if (!head) 
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void LinkedList<T>::DeleteFromHead() 
{
    if (head) 
    {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void LinkedList<T>::DeleteFromTail() 
{
    if (head) 
    {
        if (head == tail) 
        {
            delete head;
            head = tail = nullptr;
        }
        else 
        {
            Node<T>* temp = head;
            while (temp->next != tail) 
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
    }
}

template <typename T>
void LinkedList<T>::DeleteAll() 
{
    while (head)
    {
        DeleteFromHead();
    }
}

template <typename T>
void LinkedList<T>::Show() 
{
    Node<T>* current = head;
    while (current) 
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template class LinkedList<int>;  