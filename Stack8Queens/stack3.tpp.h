// FILE: Stack3.tpp.h
// TEMPLATE CLASS IMPLEMENTED: Stack<Item> (see Stack1.h for documentation)
// This file is included in the header file, and not compiled separately.
// INVARIANT for the Stack class:
//   1. The number of items in the Stack is in the member variable used.
//   2. The actual items of the Stack are stored in a partially-filled
//      array data[0]..data[used-1]. The Stack elements appear from the
//      bottom (at data[0]) to the top (at data[used-1]).

#include <cassert>  // Provides assert
#include "stack3.h"

namespace main_savitch_7A
{
	template <class Item>
	Stack<Item>::Stack() {
		stackPtr = nullptr;
		used = 0;
	}

	template <class Item>
	Stack<Item>::~Stack() {
		while (stackPtr != nullptr) {
			Node <Item>* removePtr;
			removePtr = stackPtr;
			stackPtr = stackPtr->link;
			delete removePtr;
		}
	}
	
	template <class Item>
	void Stack<Item>::push(const Item& entry)
	// Library facilities used: cassert
	{
		Node <Item>* temp = new Node <Item>;
		temp->data = entry;
		temp->link = stackPtr;
		stackPtr = temp;
		++used;
		return;
	}
	
	template <class Item>
	Item Stack<Item>::pop( )
	// Library facilities used: cassert
	{
		assert(size() > 0);
		Item value = stackPtr->data;
		Node <Item>* temp;
		temp = stackPtr;
		stackPtr = temp->link;
		delete temp;
		--used;
		return value;

	}
	
	template <class Item>
	Item Stack<Item>::top( ) const
	// Library facilities used: cassert
	{
		assert(size() > 0);
		return stackPtr->data;

	}
	

	template <class Item>
	Item Stack<Item>::peek(size_t index)
	// Library facilities used: cassert
	{
		assert(size() >= index && index > 0);
		Node <Item>* temp = new Node <Item>;
		temp = stackPtr;
		while (index > 1) {
			temp = temp->link;
			index--; 
		}
		return temp->data;
	}
}
