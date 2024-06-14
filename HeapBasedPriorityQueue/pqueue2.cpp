// FILE: pqueue2.cxx
// IMPLEMENTS: PriorityQueue (See pqueue2.h for documentation.)
// IMPLEMENTED BY: Martin Nguyen
//
// NOTE: You will need -lm at the end of your compile line to pick up
// the math library!

// INVARIANT for the PriorityQueue Class:
//   1. The member variable many_items is the number of items in the
//      PriorityQueue.
//   2. The items themselves are stored in the member variable heap,
//      which is a partially filled array organized to follow the usual
//      heap storage rules from Chapter 11 of the class notes.
// NOTE: Private helper functions are implemented at the bottom of this
// file along with their precondition/postcondition contracts.

#include <cassert>    // Provides assert function
#include <iomanip>    // Provides setw
#include <iostream>   // Provides cin, cout
#include <cmath>      // Provides log2
#include "pqueue2.h"
using namespace std;

PriorityQueue::PriorityQueue() {
    many_items = 0;
}

void PriorityQueue::insert(const Item& entry, unsigned int priority) {
    size_t new_index = many_items;
    heap[new_index].data = entry;
    heap[new_index].priority = priority;
    many_items++;

    while (new_index > 0 && parent_priority(new_index) < priority) {
        swap_with_parent(new_index);
        new_index = parent_index(new_index);
    }
}

PriorityQueue::Item PriorityQueue::get_front()
{
    assert(!is_empty());
    Item front = heap[0].data;
    heap[0] = heap[many_items - 1];
    unsigned int newPriority = heap[many_items - 1].priority;
    unsigned int currentIndex = 0;
    while ((currentIndex < many_items) && !is_leaf(currentIndex) && big_child_priority(currentIndex) > newPriority)
    {
        unsigned int bigchildIndex = big_child_index(currentIndex);
        swap_with_parent(bigchildIndex);
        currentIndex = bigchildIndex;
    }
    many_items--;
    return front;
}

bool PriorityQueue::is_leaf(size_t i) const
// Precondition: (i < many_items)
// Postcondition: If heap[i] has no children in the heap, then the function
// returns true. Otherwise the function returns false.
{
    assert(i < many_items);
    return (2 * i + 1 >= many_items);
}

size_t PriorityQueue::parent_index(size_t i) const
// Precondition: (i > 0) && (i < many_items)
// Postcondition: The return value is the index of the parent of heap[i].
{
    assert((i > 0) && (i < many_items));
    return (i - 1) / 2;
}

unsigned int PriorityQueue::parent_priority(size_t i) const
// Precondition: (i > 0) && (i < many_items)
// Postcondition: The return value is the priority of the parent of heap[i].
{
    assert((i > 0) && (i < many_items));
    size_t parentIndex = (i - 1) / 2;
    return heap[parentIndex].priority;
}

size_t PriorityQueue::big_child_index(size_t i) const
// Precondition: !is_leaf(i)
// Postcondition: The return value is the index of one of heap[i]'s children.
// This is the child with the larger priority.
{
    assert(!is_leaf(i));
    size_t leftChild = 2*i+1;
    size_t rightChild = 2*i+2;

    if (rightChild >= many_items || heap[leftChild].priority > heap[rightChild].priority) {
        return leftChild;
    }
    return rightChild;
}

unsigned int PriorityQueue::big_child_priority(size_t i) const
// Precondition: !is_leaf(i)
// Postcondition: The return value heap[big_child_index(i)].priority
{
    assert(!is_leaf(i)); 
    return heap[big_child_index(i)].priority;
}

void PriorityQueue::swap_with_parent(size_t i)
// Precondition: (i > 0) && (i < many_items)
// Postcondition: heap[i] has been swapped with heap[parent_index(i)]
{
    assert(i > 0 && i < many_items); 
    OneItemInfo temp = heap[i];
    heap[i] = heap[parent_index(i)];
    heap[parent_index(i)] = temp;
}

