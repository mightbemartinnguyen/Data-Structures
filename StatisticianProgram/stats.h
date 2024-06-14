#pragma once
#ifndef STATS_H     // Prevent duplicate definition
#define STATS_H
#include <iostream>
namespace main_savitch_2C
{
    class statistician
    {
    public:
        // CONSTRUCTOR
        statistician();
        // MODIFICATION MEMBER FUNCTIONS
        void next(double r);
        void reset();
        // CONSTANT MEMBER FUNCTIONS
        int length() const;
        double sum() const;
        double mean() const;
        double minimum() const;
        double maximum() const;
        // FRIEND FUNCTIONS
        friend statistician operator +
            (const statistician& s1, const statistician& s2);
        friend statistician operator *
            (double scale, const statistician& s);
    private:
        int count;       // How many numbers in the sequence
        double total;    // The sum of all the numbers in the sequence
        double tinyest;  // The smallest number in the sequence
        double largest;  // The largest number in the sequence
    };
    // NON-MEMBER functions for the statistician class
    bool operator ==(const statistician& s1, const statistician& s2);
}
#endif