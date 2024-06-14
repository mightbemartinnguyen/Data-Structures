// RecursionProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include "rec_fun.h"

using namespace std;
using namespace std::chrono;

void triangle(ostream& outs, unsigned int m, unsigned int n) {
    if (m <= n) {
        for (unsigned int i = 0; i < m; i++) {
            outs << "*";
        }
        outs << endl;

        triangle(outs, m + 1, n);
        for (unsigned int i = 0; i < m; i++) {
            outs << "*";
        }
        outs << endl;
    }
}

void numbers(ostream& outs, const string& prefix, unsigned int levels) {
    if (levels == 0) {
        outs << prefix << endl;
        return;
    }

    for (char c = '1'; c <= '9'; c++) {
        string s = (prefix + c) + '.';
        numbers(outs, s, levels - 1);
    }
}

bool bears(int num_bears) {
    if (num_bears == 42) {
        return true;
    }
    else if (num_bears < 42) {
        return false;
    }
    else {
        if (num_bears % 2 == 0 && bears(num_bears / 2)) {
            return true;
        }

        int lastDigit = num_bears % 10;
        int secondDigit = (num_bears % 100) / 10;
        int product = lastDigit * secondDigit;
        if ((num_bears % 3 == 0 || num_bears % 4 == 0) && bears(num_bears - product)) {
            return true;
        }

        if (num_bears % 5 == 0 && bears(num_bears - 42)) {
            return true;
        }

        return false;
    }
}

int fib_recursion(int n) {
    if (n <= 1) {
        return n;
    }

    return fib_recursion(n - 1) + fib_recursion(n - 2);
}


int fib_iterative(int n) {
    if (n == 1 || n == 2)
        return 1;
    int A[2][2] = { { 1, 1 },{ 1, 0 } };
    int B[2][2] = { { 1, 1 },{ 1, 0 } };
    int temp[2][2];
    while (n >= 2) {
        for (int i = 0; i < 2; i++)
            for (int k = 0; k < 2; k++) {
                temp[i][k] = 0;
                for (int j = 0; j < 2; j++)
                    temp[i][k] += A[i][j] * B[j][k];
            }
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                B[i][j] = temp[i][j];
        n--;
    }
    return B[0][1];
}


int main() {
    triangle(cout, 3, 5);
    numbers(cout,"THERBLIG", 2);
    
    cout << boolalpha << "\n";
    cout << "Bears(250) is " << bears(250) << "\n";
    cout << "Bears(42) is " << bears(42) << "\n";
    cout << "Bears(84) is " << bears(84) << "\n";
    cout << "Bears(53) is " << bears(53) << "\n";
    cout << "Bears(41) is " << bears(41) << "\n\n";

    cout << "Sample Output" << "\n";
    cout << "Fibonacci" << "\n";
    cout << "n\tRecursive\t\ttime_r(s)\tIterative\ttime_i(s)" << "\n";

    for (int numberSec = 1; numberSec <= 45; numberSec++) {
        high_resolution_clock::time_point startRecursion = high_resolution_clock::now();
        int recursionValue = fib_recursion(numberSec);
        high_resolution_clock::time_point endRecursion = high_resolution_clock::now();
        duration<float> timeRecursion = endRecursion - startRecursion;

        high_resolution_clock::time_point startIterative = high_resolution_clock::now();
        int iterativeValue = fib_iterative(numberSec);
        high_resolution_clock::time_point endIterative = high_resolution_clock::now();
        duration<float> timeIterative = endIterative - startIterative;

        cout << fixed;
        cout << right << setw(3) << numberSec << setw(15) << recursionValue << setw(20) << setprecision(6) << timeRecursion.count() << setw(15) << iterativeValue << setw(20) << setprecision(6) << timeIterative.count() << endl;
    }
    return 0;
}