// problem_15_count_number_in_matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

void printMatrix(const int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << setw(2) << matrix[i][j] << "    ";
        }
        cout << "\n";
    }
}

int countNumberInMatrix(const int matrix[3][3], short rows, short cols, int numberToCount)
{
    int count = 0;

    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (matrix[i][j] == numberToCount)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int matrix1[3][3] = { {9, 1, 12}, {0, 9, 1}, {0, 9, 9} };

    cout << "\nMatrix 1:\n\n";
    printMatrix(matrix1, 3, 3);

    int numberToCount;
    cout << "\nEnter the number to count in the matrix: ";
    cin >> numberToCount;

    int count = countNumberInMatrix(matrix1, 3, 3, numberToCount);
    cout << "\nNumber " << numberToCount << " count in the matrix: " << count << "\n";

    return 0;
}

