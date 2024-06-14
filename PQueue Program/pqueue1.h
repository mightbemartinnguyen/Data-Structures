// FILE: pqueue1.h
//
// Updated by Howard Miller on 3/18/23.
// Copyright © 2019, 2020, 2021, 2023 Howard Miller. All rights reserved.
//
// This assignment is worth 10 points on Canvas.
// CLASS PROVIDED: PriorityQueue (a priority queue of items)
//
// TYPEDEF for the PriorityQueue class:
// typedef _____ Item
// The type Item is the data type of the items in the Priority Queue.
// It may be any of the C++ built-in types (int, char, etc.), or a class
// with a default constructor, a copy constructor, and assignment operator.
//
// CONSTRUCTOR for the PriorityQueue class:
// PriorityQueue( )
// Postcondition: The PriorityQueue has been initialized with no Items.
//
// MODIFICATION MEMBER FUNCTIONS for the PriorityQueue class:
// void insert(const Item& entry, unsigned int priority)
// Postcondition: A new copy of entry has been inserted with the specified
// priority.
//
// Item get_front( )
// Precondition: there is at a list (check the head_ptr).
// Postcondition: The highest priority item has been returned and has been
// removed from the PriorityQueue. (If several items have equal priority,
// then the one that entered first will come out first.)
//
// CONSTANT MEMBER FUNCTIONS for the PriorityQueue class:
// size_t size( ) const
// Postcondition: Return value is the total number of items in the
// PriorityQueue. Used by the tester, Not in your code.
//
// bool is_empty( ) const
// Postcondition: Return value is true if the PriorityQueue is empty.
// Used by the tester, Not in your code.
//
// VALUE SEMANTICS for the PriorityQueue class:
// Assignments and the copy constructor may be used with
// PriorityQueue objects
#ifndef PQUEUE_H
#define PQUEUE_H
#include <stdlib.h> // Provides size_t
template<typename Item>
struct Node; // This will be completely defined below.

template<typename Item>
class PriorityQueue
{
public:
	PriorityQueue();
	PriorityQueue(const PriorityQueue& source);
	~PriorityQueue();
	void operator =(const PriorityQueue& source);
	size_t size() const;
	void insert(const Item& entry, unsigned int priority);
	Item get_front();
	bool is_empty() const { return head_ptr == nullptr; }
private:
	// Note: head_ptr is the head pointer for a linked list that
	// contains the items along with their priorities. These nodes are
	// kept in order from highest priority (at the head of the list)
	// to lowest priority (at the tail of the list).
	// The data type Node is completely defined below.
	Node<Item>* head_ptr = reinterpret_cast <Node<Item>*>(0xBAD10000); // Make it easy to find uninitialized ptr
};

template<typename Item>
struct Node
{ // Node for a linked list
	unsigned int priority;
	Item data;
	Node<Item>* link = reinterpret_cast <Node<Item>*>(0x12345678); // Make it easy to find uninitialized ptr
};
// Structs in C++ are by default public, but can have private section too
// Structs in C++ are the same as class, except they default to public
#include "pqueue1.tpp.h"
#endif