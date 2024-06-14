#include "node2.h"
#include "sequence4.h"
#include <iostream>
#include <cassert>

namespace main_savitch_6B {
    template <class Item>
    sequence<Item>::sequence() {
        head_ptr = nullptr;
        tail_ptr = nullptr;
        cursor = nullptr;
        precursor = nullptr;
        size_t many_nodes = 0;
    }
   
    template <class Item>
    sequence<Item>::sequence(const sequence& source)
    {
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        node<Item>* newhead;
        newhead = source.head_ptr;
        precursor = head_ptr;
        many_nodes = source.many_nodes;

        if (source.cursor == nullptr) {
            cursor = nullptr;
            precursor = nullptr;
        }
        else if (source.precursor == nullptr) {
            cursor = head_ptr;
            precursor = nullptr;
        }
        else {
            while (newhead != source.precursor) {
                newhead = newhead->link();
                precursor = precursor->link();
            }
            cursor = precursor->link();
        }
    }


    template <class Item>
    sequence<Item>::~sequence() {
        while (head_ptr != nullptr) {
            node<Item>* remove_ptr;
            remove_ptr = head_ptr;
            head_ptr = head_ptr->link();
            delete remove_ptr;
        }
    }

    template <class Item>
    void sequence<Item>::start() {
        cursor = head_ptr;
        precursor = nullptr;
    }

    template <class Item>
    void sequence<Item>::advance() {
        assert(is_item());
        precursor = cursor;
        cursor = cursor->link();
        if (cursor == nullptr) {
            precursor = nullptr;
        }
    }

    template <class Item>
    void sequence<Item>::insert(const Item& entry){
        if (cursor == nullptr || precursor == nullptr) {
            head_ptr = new node<Item>(entry, head_ptr);
            cursor = head_ptr;
            precursor = nullptr;
            many_nodes++;
        }
        else if (head_ptr == nullptr) { 
            tail_ptr = head_ptr;
            many_nodes++;
        }
        else {
            node<Item>* insert_ptr;
            insert_ptr = new node<Item>;
            insert_ptr->set_data(entry);
            insert_ptr->set_link(precursor->link());
            precursor->set_link(insert_ptr);
            cursor = precursor->link();
            many_nodes++;
        }
    }
    
    template <class Item>
    void sequence<Item>::attach(const Item& entry)
    {
        node<Item>* insert_ptr;
        insert_ptr = new node<Item>;
        insert_ptr->set_data(entry);

        if (head_ptr == nullptr)
        {
            head_ptr = new node<Item>(entry, head_ptr);
            tail_ptr = head_ptr;
            cursor = head_ptr;
            precursor = nullptr;
            many_nodes++;
        }
        else if (cursor == nullptr || cursor == tail_ptr)
        {
            insert_ptr->set_link(tail_ptr->link());
            tail_ptr->set_link(insert_ptr);
            precursor = tail_ptr;
            tail_ptr = tail_ptr->link();
            cursor = tail_ptr;
            many_nodes++;
        }
        else
        {
            insert_ptr->set_link(cursor->link());
            cursor->set_link(insert_ptr);
            precursor = cursor;
            cursor = cursor->link();
            many_nodes++;
        }
    }

    template <class Item>
    void sequence<Item>::operator =(const sequence& source)
    {
        if (this == &source)
            return;

        many_nodes = source.many_nodes;
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        node<Item>* newhead;
        newhead = source.head_ptr;
        precursor = head_ptr;

        if (source.cursor == nullptr) {
            cursor = nullptr;
            precursor = nullptr;
        }
        else if (source.precursor == nullptr) {
            cursor = head_ptr;
            precursor = nullptr;
        }
        else {
            while (newhead != source.precursor) {
                newhead = newhead->link();
                precursor = precursor->link();
            }
            cursor = precursor->link();
        }
    }

    template <class Item>
    void sequence<Item>::remove_current()
    {
        assert(is_item());
        if (precursor == nullptr) {
            node<Item>* remove_ptr;
            remove_ptr = head_ptr;
            head_ptr = head_ptr->link();
            delete remove_ptr;
            cursor = head_ptr;
        }
        else {
            cursor = cursor->link();
            node<Item>* remove_ptr;
            remove_ptr = precursor->link();
            precursor->set_link(remove_ptr->link());
            delete remove_ptr;
        }
        many_nodes--;
    }

    template <class Item>
     Item sequence<Item>::current() const {
        assert(is_item());
        return cursor->data();
    }
}
