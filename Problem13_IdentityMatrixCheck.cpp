// Problem 13 - Identity Matrix Check
//
// A matrix is an identity matrix when every element on the main diagonal is 1
// and every other element is 0. The matrix is hard-coded in main().

// problem_13_matrix_is_identity_or_not.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

bool isIdentityMatrix(const int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            if (i == j && matrix[i][j] != 1)
            {
                return false;
            }
            else if (i != j && matrix[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    //int Matrix1[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int matrix1[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };

    cout << "Matrix 1:\n";
    printMatrix(matrix1, 3, 3);

    if (isIdentityMatrix(matrix1, 3, 3))
    {
        cout << "\nThe matrix is an identity matrix.\n";
    }
    else
    {
        cout << "\nThe matrix is NOT an identity matrix.\n";
    }

    return 0;
}
