// problem_01_Random Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Generates a random number within a specific range
int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

// Filled as 'void' since the matrix is modified directly (Pass by Reference)
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

// Added 'const' to protect the matrix from accidental modification during printing
void PrintMatrix(const int matrix[3][3], short Rows, short Cols)
{
    cout << "The 3x3 random matrix is:\n\n";

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            // Cleaned up the spacing for a perfectly aligned table layout
            cout << setw(3) << matrix[i][j] << "   ";
        }
        cout << "\n";
    }
}

int main()
{
    // Seed the random number generator using the current time (called once)
    srand((unsigned)time(NULL));

    int randomNumber[3][3];

    FillRandomMatrix(randomNumber, 3, 3);
    PrintMatrix(randomNumber, 3, 3);

    return 0;
}
        