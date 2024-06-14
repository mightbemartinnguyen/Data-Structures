#pragma once
#ifndef MAIN_SAVITCH_SEQUENCE3_H
#define MAIN_SAVITCH_SEQUENCE3_H
#include "node1.h"  // Provides node class
#include <cstdlib> // Provides size_t
namespace main_savitch_5 {
	// TYPEDEF
	typedef double value_type;
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
		void insert(const value_type& entry);
		void attach(const value_type& entry);
		void operator =(const sequence& source);
		void remove_current();
		// CONSTANT MEMBER FUNCTIONS
		size_t size() const { return many_nodes; }
		bool is_item() const { return (cursor != nullptr); }
		value_type current() const;
	private:
		node* head_ptr;
		node* tail_ptr;
		node* cursor;
		node* precursor;
		size_t many_nodes; //number of nodes on the list
	};
} // End of namespace
#endif