// Martin Nguyen    CIST004B    2/23/2023
#include "sequence2.h"
#include "cassert"

namespace main_savitch_4
{
    sequence::sequence(size_t initial_capacity) {
        data = new value_type[initial_capacity];
        capacity = initial_capacity;
        used = 0;
        current_index = 0;
}
   
    sequence::sequence(const sequence& source) {
        data = new value_type[source.capacity];
        capacity = source.capacity;
        used = source.used;
        current_index = source.current_index;
        for (size_t i = 0; i < used; i++) {
            data[i] = source.data[i];
        }
    }

    
    sequence::~sequence() {
        delete[] data;
    }

    
    void sequence::resize(size_t new_capacity) {
        if (new_capacity > used) {
            capacity = new_capacity;
        }
        value_type* newData = new value_type[capacity];
        for (size_t i = 0; i < used; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
     
    }
    
    void sequence::start() {
        if (size() > 0) {
            current_index = 0;
        }
    }


    void sequence::advance() {
        assert(is_item());
        if (current_index < used) {
            current_index++;
        }
    }


    
    void sequence::insert(const value_type& entry) {
        if (used == capacity) {
            resize((capacity *static_cast<size_t>(1.5)) + 1);
        }
        
        if (!is_item()) {
            current_index = 0;
        }
        for (size_t i = used; i > current_index; --i)
            data[i] = data[i - 1];
        data[current_index] = entry;
        used++;
    }


    void sequence::attach(const value_type& entry) {
        if (used == capacity) {
            resize((capacity * static_cast<size_t>(1.5)) + 1);
        }

        if (!is_item()) {
            current_index = used - 1;
        }
        for (size_t i = used; i > current_index + 1; --i) {
            data[i] = data[i - 1];
        }
        current_index++;
        data[current_index] = entry;
        used++;
    }

    void sequence::remove_current() {
        assert(is_item());
        for (size_t i = current_index; i < used - 1; ++i) {
            data[i] = data[i + 1];
        }
        used--;
    }

    
    void sequence::operator =(const sequence& source) {
        if (this == &source)
            return;
       
        capacity = source.capacity;
        delete[] data;
        data = new value_type[capacity];
        used = source.used;
        current_index = source.current_index;
        for (int i = 0; i < used; i++) {
            data[i] = source.data[i];
        }
           

    }
 

    size_t sequence::size() const {
        return used;
    }

    size_t sequence::max_size() const {
        return capacity;
    }

    bool sequence::is_item() const {
        return (current_index >= 0 && current_index < used);
    }
    sequence::value_type sequence::current() const {
        assert(is_item());
        return data[current_index];
    }
}