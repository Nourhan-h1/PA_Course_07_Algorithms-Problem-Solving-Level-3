// Problem 16 - Sparse Matrix Check
//
// A matrix is sparse when it has more zeros than non-zero elements
// (zeroCount > nonZeroCount). Reuses countNumberInMatrix to count the zeros.
// The matrix is hard-coded in main().

// problem_16_check_matrix_isSparce.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip>

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


bool isSparseMatrix(const int matrix[3][3], short rows, short cols)
{
    int matrixSize = rows * cols;
    int zeroCount = countNumberInMatrix(matrix, rows, cols, 0); 
    int nonZeroCount = matrixSize - zeroCount;

    return (zeroCount > nonZeroCount);
}

int main()
{
    int matrix1[3][3] = { {0, 0, 0}, {0, 0, 1}, {0, 0, 9} };

    cout << "\nMatrix 1:\n\n";
    printMatrix(matrix1, 3, 3);

    if (isSparseMatrix(matrix1, 3, 3))
        cout << "\nYes: It is Sparse\n";
    else
        cout << "\nNo: It's NOT Sparse\n";

    return 0;
}
