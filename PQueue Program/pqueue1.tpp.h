#include "pqueue1.h"
#include "cassert"
#include <iostream>

template <class Item>
PriorityQueue<Item>::PriorityQueue() {
    head_ptr = nullptr;
}



template <class Item>
PriorityQueue<Item>::PriorityQueue(const PriorityQueue& source) {
    head_ptr = nullptr;

    Node<Item>* sourcePtr = source.head_ptr;       
    Node<Item>* tailPtr = nullptr;

    while (sourcePtr != nullptr) {
        Node<Item>* newPtr = new Node<Item>;
        newPtr->data = sourcePtr->data;
        newPtr->priority = sourcePtr->priority;
        newPtr->link = nullptr;

        if (tailPtr == nullptr) {
            head_ptr = newPtr;
        }
        else {
            tailPtr->link = newPtr;
        }

        tailPtr = newPtr;
        sourcePtr = sourcePtr->link;
    }
}



template <class Item>
PriorityQueue<Item>::~PriorityQueue() {
    while (head_ptr != nullptr) {
        Node<Item>* remove = head_ptr;
        head_ptr = head_ptr->link;
        delete remove;
    }
}



template<typename Item>
void PriorityQueue<Item>::operator=(const PriorityQueue& source) {
    if (this == &source) 
        return;

    while (head_ptr != nullptr) {
        Node<Item>* remove = head_ptr;
        head_ptr = head_ptr->link;
        delete remove;
    }

    Node <Item>* sourcePtr = source.head_ptr;
    Node<Item>* newHead = nullptr;


    while (sourcePtr != nullptr) {
        Node<Item>* newNode = new Node<Item>;
        newNode->data = sourcePtr->data;
        newNode->priority = sourcePtr->priority;
        newNode->link = nullptr;
        

        if (newHead == nullptr) {
            head_ptr = newNode;
        } else {
            newHead->link = newNode;
        }
        newHead = newNode;

        sourcePtr = sourcePtr->link;
    }
}

template <class Item>
size_t PriorityQueue<Item>::size() const {
    size_t count = 0;
    Node<Item>* currentIndex = head_ptr;
    
    while (currentIndex != nullptr) {
        currentIndex = currentIndex->link;
        count++;
    }
    return count;
}



template <class Item>
void PriorityQueue<Item>::insert(const Item& entry, unsigned int priority) {
    Node<Item>* newNode = new Node<Item>;
    newNode->data = entry;
    newNode->priority = priority;
        
    if (head_ptr == nullptr || priority > head_ptr->priority) {
        newNode->link = head_ptr;
        head_ptr = newNode;
    }
    else {
        Node<Item>* current = head_ptr;
        while (current->link != nullptr && priority <= current->link->priority) {
            current = current->link;
        }
        newNode->link = current->link;
        current->link = newNode;
    }
}



template <class Item>
Item PriorityQueue<Item>::get_front() {         
    assert(head_ptr != nullptr);

    Node<Item>* remove = head_ptr;
    head_ptr = head_ptr->link;
    Item data = remove->data;
   
    delete remove;
    return data;
}


