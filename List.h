#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

class Node {
public:
    int data; 
    Node* next; 
    Node(int data) { 
        this->data = data;
        this->next = nullptr;
    }
};

class List {
    friend class Stack; 
    Node* head; 
    List() { 
        this->head = nullptr;
    }
    void addFirst(int data) {
        Node* newNode = new Node(data); 
        newNode->next = head; 
        head = newNode; 
    }
    void addLast(int data) {
        Node* newNode = new Node(data); 
        if (head == nullptr) { 
            head = newNode; 
        }
        else { 
            Node* temp = head;
            while (temp->next != nullptr) { 
                temp = temp->next;
            }
            temp->next = newNode; 
        }
    }
    void printList() {
        Node* temp = head;
        while (temp != nullptr) { 
            cout << temp->data << " "; 
            temp = temp->next;
        }
        cout << endl;
    }
};

#endif
