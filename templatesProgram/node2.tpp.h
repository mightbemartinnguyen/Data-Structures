#pragma once
// FILE: node2.template
//
//  Updated by Howard Miller on 3/01/23.
//  Copyright � 2019, 2020, 2021, 2023 Howard Miller. All rights reserved.
//
// IMPLEMENTS: The functions of the node template class and the
// linked list toolkit (see node2.h for documentation).
//
// NOTE:
//   Since node is a template class, this file is included in node2.h.
//   Therefore, we should not put any using directives in this file.
//
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.

#include <cassert>    // Provides assert
#include <cstdlib>    // Provides nullptr and size_t

namespace main_savitch_6B
{
	// Helper Functions for working with lists:

	template <class Item>
	void list_piece(
		const node<Item>* start_ptr, const node<Item>* end_ptr,
		node<Item>*& p_head_ptr, node<Item>*& p_tail_ptr
	)
		// Precondition: start_ptr and end_ptr are pointers to nodes on the same
		// linked list, with the start_ptr node at or before the end_ptr node.
		// Postcondition: head_ptr and tail_ptr are the head and tail pointers
		// for a new list that contains the items from start_ptr up to but
		// not including end_ptr.  The end_ptr may also be nullptr, in which case
		// the new list contains elements from start_ptr to the end of the list.
	{
		p_head_ptr = nullptr;
		p_tail_ptr = nullptr;

		// Handle the case of the empty list.
		if (start_ptr == end_ptr)
			return;

		// Make the head node for the newly created list, and put data in it.
		p_head_ptr = new node<Item>(start_ptr->data(), nullptr);
		p_tail_ptr = p_head_ptr;

		// Copy the rest of the nodes one at a time, adding at the tail of new list.
		start_ptr = start_ptr->link();
		while (start_ptr != end_ptr)
		{
			// Create new node and add to end of list
			p_tail_ptr->set_link(new node<Item>(start_ptr->data(), p_tail_ptr->link()));
			// traverse the list
			p_tail_ptr = p_tail_ptr->link();
			start_ptr = start_ptr->link();
		}
	}

	template <class Item>
	void list_copy(const node<Item>* source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr)
		// Precondition: source_ptr pointers to the first node in the original
		// liked list.  head_ptr and tail_ptr are pointers references to nodes
		// on the same linked list.
		// Postcondition: head_ptr and tail_ptr are the head and tail pointers
		// for a new list that contains the all the items from source_ptr list.
		// The head_ptr and tail_ptr will also be nullptr when the source_ptr list
		// was empty.
	{
		head_ptr = nullptr;
		tail_ptr = nullptr;

		// Handle the case of the empty list
		if (source_ptr == nullptr)
			return;

		// Make the head node for the newly created list, and put data in it
		head_ptr = new node<Item>(source_ptr->data(), head_ptr);
		tail_ptr = head_ptr;

		// Copy rest of the nodes one at a time, adding at the tail of new list
		source_ptr = source_ptr->link();
		while (source_ptr != nullptr)
		{
			// Create new node and add to end of list
			tail_ptr->set_link(new node<Item>(source_ptr->data(), tail_ptr->link()));
			// Traverse List
			tail_ptr = tail_ptr->link();
			source_ptr = source_ptr->link();
		}
	}

} // End of namespace
