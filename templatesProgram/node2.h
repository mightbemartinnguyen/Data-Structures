#pragma once
// FILE: node2.h (part of the namespace main_savitch_6B)
//
//  Updated by Howard Miller on 3/01/23.
//  Copyright © 2019, 2020, 2021, 2023 Howard Miller. All rights reserved.
//
// PROVIDES: A template class for a node in a linked list, and list manipulation
// functions. The template parameter is the type of the data in each node.
// This file also defines a template class: node_iterator<Item>.
// The node_iterator is a forward iterators with two constructors:
// (1) A constructor (with a node<Item>* parameter) that attaches the iterator
// to the specified node in a linked list, and (2) a default constructor that
// creates a special iterator that marks the position that is beyond the end of a
// linked list. There is also a const_node_iterator for use with
// const node<Item>* .
//
// TYPEDEF for the node<Item> template class:
//   Each node of the list contains a piece of data and a pointer to the
//   next node. The type of the data (node<Item>::value_type) is the Item type
//   from the template parameter. The type may be any of the built-in C++ classes
//   (int, char, ...) or a class with a default constructor, an assignment
//   operator, and a test for equality (x == y).
//   There is NO more typedef!
// NOTE:
//   Many compilers require the use of the new keyword typename before using
//   the expression node<Item>::value_type. Otherwise
//   the compiler doesn't have enough information to realize that it is the
//   name of a data type.
//
// CONSTRUCTOR for the node<Item> class:
//   node(
//     const Item& init_data = Item(),
//     node* init_link = nullptr
//   )
//     Postcondition: The node contains the specified data and link.
//     NOTE: The default value for the init_data is obtained from the default
//     constructor of the Item. In the ANSI/ISO standard, this notation
//     is also allowed for the built-in types, providing a default value of
//     zero. The init_link has a default value of nullptr.
//
// NOTE about two versions of some functions:
//   The data function returns a reference to the data field of a node and
//   the link function returns a copy of the link field of a node.
//   Each of these functions comes in two versions: a const version and a
//   non-const version. If the function is activated by a const node, then the
//   compiler choses the const version (and the return value is const).
//   If the function is activated by a non-const node, then the compiler choses
//   the non-const version (and the return value will be non-const).
// EXAMPLES:
//    const node<int> *c;
//    c->link( ) activates the const version of link returning const node*
//    c->data( ) activates the const version of data returning const Item&
//    c->data( ) = 42; ... is forbidden
//    node<int> *p;
//    p->link( ) activates the non-const version of link returning node*
//    p->data( ) activates the non-const version of data returning Item&
//    p->data( ) = 42; ... actually changes the data in p's node
//
// MEMBER FUNCTIONS for the node<Item> class:
//   const Item& data( ) const <----- const version
//   and
//   Item& data( ) <----------------- non-const version
//   See the note (above) about the const version and non-const versions:
//     Postcondition: The return value is a reference to the  data from this node.
//
//   const node* link( ) const <----- const version
//   and
//   node* link( ) <----------------- non-const version
//   See the note (above) about the const version and non-const versions:
//     Postcondition: The return value is the link from this node.
//   
//   void set_data(const Item& new_data)
//     Postcondition: The node now contains the specified new data.
//   
//   void set_link(node* new_link)
//     Postcondition: The node now contains the specified new link.
//
// DYNAMIC MEMORY usage by the toolkit: 
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: the constructor, list_head_insert, list_insert, list_copy.

#ifndef MAIN_SAVITCH_NODE2_H  
#define MAIN_SAVITCH_NODE2_H
#include <cstdlib>   // Provides nullptr and size_t
#include <iterator>  // Provides iterator and forward_iterator_tag

namespace main_savitch_6B
{
	template <class Item>
	class node
	{
	public:
		// TYPEDEF
		//        typedef Item value_type;
		// CONSTRUCTOR
		node(const Item& init_data = Item(), node* init_link = nullptr)
		{
			data_field = init_data; link_field = init_link;
		}
		// MODIFICATION MEMBER FUNCTIONS
		Item& data() { return data_field; }
		node* link() { return link_field; }
		void set_data(const Item& new_data) { data_field = new_data; }
		void set_link(node* new_link) { link_field = new_link; }
		// CONST MEMBER FUNCTIONS
		const Item& data() const { return data_field; }
		const node* link() const { return link_field; }
	private:
		Item data_field;
		node* link_field;
	};


	// Helper functions for managing a linked list
	//  These functions are provided for your use.
	template <class Item>
	void list_piece(const node<Item>* start_ptr, const node<Item>* end_ptr, node<Item>*& p_head_ptr, node<Item>*& p_tail_ptr);

	template <class Item>
	void list_copy(const node<Item>* source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr);

}  // End of namespace

#include "node2.tpp.h"
#endif
