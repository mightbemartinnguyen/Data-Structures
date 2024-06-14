// Martin Nguyen    CIST039     2/18/2023

#pragma once
#ifndef MAIN_SAVITCH_SEQUENCE_H
#define MAIN_SAVITCH_SEQUENCE_H
#include <cstdlib>  // Provides size_t
#include <array>
namespace main_savitch_3
{
    class sequence
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef double value_type;
        static const size_t CAPACITY = 30;
        // CONSTRUCTOR
        sequence();
        // MODIFICATION MEMBER FUNCTIONS
        void start();
        void advance();
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current();
        // CONSTANT MEMBER FUNCTIONS
        size_t size() const;
        bool is_item() const;
        value_type current() const;
    private:
        //        value_type data[CAPACITY];
        std::array <value_type, CAPACITY> data;
        size_t used;
        size_t current_index;
    };
}
#endif