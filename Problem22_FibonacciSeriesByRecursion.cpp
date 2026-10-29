// Problem 22 - Fibonacci Series by Recursion
//
// Prints the first 10 Fibonacci numbers. Each call calculates the next number
// from the previous two (prev1, prev2), prints it, then calls itself with a
// smaller counter until the counter reaches 0.
//
// Example Output:
//   Fibonacci Series using Recursion:
//
//    1     1     2     3     5     8    13    21    34    55

// problem_22_fibonacciSeriesByRecursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

void printFibonacciUsingRecursion(short number, int prev1, int prev2)
{
    int febNumber = 0;
    if (number > 0)
    {
         febNumber = prev1 + prev2;

         prev2 = prev1;
         prev1 = febNumber;

         cout << setw(2) << febNumber << "    ";
         printFibonacciUsingRecursion(number - 1, prev1, prev2);
    }
    
}

int main()
{
    cout << "Fibonacci Series using Recursion:\n\n";

    printFibonacciUsingRecursion(10, 0, 1);
    return 0;
}
