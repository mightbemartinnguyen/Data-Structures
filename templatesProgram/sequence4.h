#pragma once
#ifndef MAIN_SAVITCH_SEQUENCE3_H
#define MAIN_SAVITCH_SEQUENCE3_H
#include "node2.h"  // Provides node class
#include <cstdlib> // Provides size_t
namespace main_savitch_6B {
	template <class Item>
	// TYPEDEF
	class sequence
	{
	public:
		// CONSTRUCTORS and DESTRUCTOR
		sequence();
		sequence(const sequence& source);
		~sequence();
		// MODIFICATION MEMBER FUNCTIONS
		void start();
		void advance();
		void insert(const Item& entry);
		void attach(const Item& entry);
		void operator =(const sequence& source);
		void remove_current();
		// CONSTANT MEMBER FUNCTIONS
		size_t size() const { return many_nodes; }
		bool is_item() const { return (cursor != nullptr); }
		Item current() const;
	private:
		node <Item>* head_ptr;
		node <Item>* tail_ptr;
		node<Item>* cursor;
		node<Item>* precursor;
		size_t many_nodes; //number of nodes on the list
	};
} // End of namespace
#include "sequence4.tpp.h"  
#endif

