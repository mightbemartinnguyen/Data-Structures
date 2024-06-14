// Martin Nguyen    CIST039     2/18/2023
#include "sequence1.h"
#include "cassert"
namespace main_savitch_3
{
    sequence::sequence() {
        used = 0;
        current_index = 0;
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
        assert(size() < CAPACITY);
        if (!is_item()) {
            current_index = 0;
        }
        for (size_t i = used; i > current_index; --i)
            data[i] = data[i - 1];
        data[current_index] = entry;
        ++used;
    }


    void sequence::attach(const value_type& entry) {
        assert(size() < CAPACITY);
        if (!is_item()) {
            current_index = used - 1;
        }
        for (size_t i = used; i > current_index + 1; --i)
            data[i] = data[i - 1];
        ++current_index;
        data[current_index] = entry;
        ++used;
    }


    void sequence::remove_current() {
        assert(is_item());
        for (size_t i = current_index; i < used - 1; ++i)
            data[i] = data[i + 1];
        --used;
    }


    size_t sequence::size() const {
        return used;
    }


    bool sequence::is_item() const {
        return (current_index >= 0 && current_index < used);
    }


    sequence::value_type sequence::current() const {
        assert(is_item());
        return data[current_index];
    }
}