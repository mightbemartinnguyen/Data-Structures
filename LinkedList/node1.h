#pragma once
#ifndef MAIN_SAVITCH_NODE1_H  
#define MAIN_SAVITCH_NODE1_H
namespace main_savitch_5
{
	class node
	{
	public:
		// TYPEDEF
		typedef double value_type;
		// CONSTRUCTOR
		node(const value_type& init_data = value_type(),
			node* init_link = nullptr)
		{
			data_field = init_data; link_field = init_link;
		}
		// Member functions to set the data and link fields:
		void set_data(const value_type& new_data) { data_field = new_data; }
		void set_link(node* new_link) { link_field = new_link; }
		// Constant member function to retrieve the current data:
		value_type data() const { return data_field; }
		// Two slightly different member functions to retreive the current link
		const node* link() const { return link_field; }
		node* link() { return link_field; }
	private:
		value_type data_field;
		node* link_field;
	};
	// Helper functions for managing a linked list
	//  These functions are provided for your use.
	void list_piece(const node* start_ptr, const node* end_ptr, node*&
		p_head_ptr, node*& p_tail_ptr);
	void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr);
} // End of namespace
#endif