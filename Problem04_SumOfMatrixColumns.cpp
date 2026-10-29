// problem_04_Sum of Matrix Colms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillRandomMatrix(int matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintTheRandomMatrix(const int matrix[3][3], short Rows, short Cols)
{
   
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << matrix[i][j] << "   ";
        }
        cout << "\n";
    }
}

// const ensures read-only access to prevent accidental data modification
int ColumnSum(const int matrix[3][3], short ColIndex, short Rows)
{
    int sum = 0;
    for (short i = 0; i < Rows; i++)
    {
        sum += matrix[i][ColIndex];
    }
    return sum;
}


void PrintColumnSums(const int matrix[3][3], short Rows, short Cols)
{
    
    for (short j = 0; j < Cols; j++)
    {
        cout << "Column " << j + 1 << " = " << ColumnSum(matrix, j, Rows) << "\n";
    }
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int randomNumber[3][3];

    FillRandomMatrix(randomNumber, 3, 3);

    cout << "The 3x3 random matrix is:\n\n";
    PrintTheRandomMatrix(randomNumber, 3, 3);

    cout << "\n\nThe following are the sums of each column in the matrix:\n\n";
    PrintColumnSums(randomNumber, 3, 3);

    return 0;
}
