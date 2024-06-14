#include "node1.h"
#include "sequence3.h"
#include <iostream>
#include <cassert>

namespace main_savitch_5 {
    sequence::sequence() {
        head_ptr = nullptr;
        tail_ptr = nullptr;
        cursor = nullptr;
        precursor = nullptr;
        many_nodes = 0;
    }

    sequence::sequence(const sequence& source)
    {
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        node* newhead;
        newhead = source.head_ptr;
        precursor = head_ptr;
        many_nodes = source.many_nodes;

        if (source.cursor == nullptr) {  //If source.cursor is nullptr (i.e., the cursor is at the end of the list). If so, the new object's cursor and precursor members are both set to nullptr.
            cursor = nullptr;
            precursor = nullptr;
        }
        else if (source.precursor == nullptr) { //if source.precursor is nullptr (i.e., the cursor is at the beginning of the list), the new object's cursor is set to the head of the list and precursor is set to nullptr.
            cursor = head_ptr;
            precursor = nullptr;
        }
        else {
            while (newhead != source.precursor) { //the code uses a loop to find the corresponding node in the new object 
                newhead = newhead->link();        // by traversing the linked list from newhead (which starts at the head of the new list) until it reaches the node pointed to by source.precursor
                precursor = precursor->link();    //At the same time, it traverses the new object's list using precursor until it reaches the  corresponding node.
            }                                     //Once this is done, the new object's cursor is set to the node following precursor.
            cursor = precursor->link();
        }
    }


    sequence::~sequence() {
        while (head_ptr != nullptr) {
            node* remove_ptr;
            remove_ptr = head_ptr;
            head_ptr = head_ptr->link();
            delete remove_ptr;
        }
    }

    void sequence::start() {
        cursor = head_ptr;
        precursor = nullptr;
    }


    void sequence::advance() {
        assert(is_item());
        precursor = cursor;
        cursor = cursor->link();
        if (cursor == nullptr) {
            precursor = nullptr;
        }
    }

    void sequence::insert(const value_type& entry) {
        if (cursor == nullptr || precursor == nullptr) {  // checks if the cursor is nullptr or if the precursor is nullptr, either empty or the cursor is at the beginning of the list. 
            head_ptr = new node(entry, head_ptr); //the function creates a new node with entry as its data and sets the head_ptr to point to it
            cursor = head_ptr;  //The cursor is set to point to the new node, 
            precursor = nullptr;
            many_nodes++;
        }
        else if (head_ptr == nullptr) {  //Note that if the head_ptr is initially nullptr, the function sets the tail_ptr to 
            tail_ptr = head_ptr;         //head_ptr but does not actually insert a new node with entry.
            many_nodes++;
        }
        else {   //If the list is not empty and the cursor is not at the beginning of the list, 
            node* insert_ptr;
            insert_ptr = new node;    // the function creates a new node with entry as its data,
            insert_ptr->set_data(entry);  
            insert_ptr->set_link(precursor->link());  //sets its link to point to the node that the precursor is currently pointing to. 
            precursor->set_link(insert_ptr);    
            cursor = precursor->link();     //It then sets the precursor's link to point to the new node, and sets the cursor to point to the new node.
            many_nodes++;
        }
    }

    void sequence::attach(const value_type& entry)
    {
        node* insert_ptr;                //The function first creates a new node with entry as its data, and sets its link to nullptr.
        insert_ptr = new node;           
        insert_ptr->set_data(entry);     

        if (head_ptr == nullptr)        //If the list is empty (i.e., head_ptr is nullptr),
        {
            head_ptr = new node(entry, head_ptr);   //the function sets head_ptr to point to the new node, and sets tail_ptr, cursor, and precursor to point to it as well. 
            tail_ptr = head_ptr;
            cursor = head_ptr;
            precursor = nullptr;
            many_nodes++;
        }
        else if (cursor == nullptr || cursor == tail_ptr)   //If the cursor is at the end of the list (i.e., cursor is nullptr or cursor is equal to tail_ptr),
        {
            insert_ptr->set_link(tail_ptr->link());  //the function sets the new node's link to point to tail_ptr's link, and sets tail_ptr's link to point to the new node
            tail_ptr->set_link(insert_ptr);
            precursor = tail_ptr;        //The function then updates precursor to point to tail_ptr, and sets tail_ptr and cursor to point to the new node. 
            tail_ptr = tail_ptr->link();
            cursor = tail_ptr;
            many_nodes++;
        }
        else
        {
            insert_ptr->set_link(cursor->link());  //If the cursor is not at the end of the list, the function sets the new node's link to point to the node that the cursor is currently pointing to,
            cursor->set_link(insert_ptr);          //and sets the cursor's link to point to the new node. 
            precursor = cursor;                    //The function then updates precursor to point to cursor, and sets cursor to point to the new node. 
            cursor = cursor->link();
            many_nodes++;
        }
    }


    void sequence::operator =(const sequence& source)
    {
        if (this == &source)   //self assignment
            return;

        //If the current object is not the same as the source object, the function proceeds to copy the data from the source object to the current object.  
        many_nodes = source.many_nodes; //First, it sets the many_nodes variable of the current object to the same value as that of the source object. 
        list_copy(source.head_ptr, head_ptr, tail_ptr); //Then, it calls the list_copy function to copy the nodes from the source list to the current list, 
        node* newhead;                                  //and sets the head_ptrand tail_ptr variables of the current object to point to the beginningand end of the new list, respectively.
        newhead = source.head_ptr; 
        precursor = head_ptr;          //Next, the function updates the cursor and precursor pointers of the current object to match those of the source object. 

        if (source.cursor == nullptr) {
            cursor = nullptr;
            precursor = nullptr;
        }
        else if (source.precursor == nullptr) {
            cursor = head_ptr;
            precursor = nullptr;
        }
        else {
            while (newhead != source.precursor) {   //Otherwise, the function uses a loop to find the corresponding node in the current object's list for the source.cursor and source.precursor nodes. 
                newhead = newhead->link();
                precursor = precursor->link();
            }
            cursor = precursor->link();   //Finally, the function sets the cursor pointer of the current object to point to the same node as the source.cursor node.
        }
    }


    void sequence::remove_current()
    {
        assert(is_item());
        if (precursor == nullptr    ) {   //If the cursor pointer is pointing to a valid node, the function proceeds to remove that node from the sequence. 
            node* remove_ptr;
            remove_ptr = head_ptr;
            head_ptr = head_ptr->link();
            delete remove_ptr;
            cursor = head_ptr;
        }
        else {
            cursor = cursor->link();  //If the precursor pointer is not nullptr, it means that the cursor pointer is pointing to a node other than the first node in the sequence. 
            node* remove_ptr;
            remove_ptr = precursor->link();
            precursor->set_link(remove_ptr->link());
            delete remove_ptr;
        }
        many_nodes--;
    }


    value_type sequence::current() const {
        assert(is_item());
        return cursor->data();
    }
}
