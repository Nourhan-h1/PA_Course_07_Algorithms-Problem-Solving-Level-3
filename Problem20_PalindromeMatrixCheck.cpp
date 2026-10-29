// Problem 20 - Palindrome Matrix Check
//
// A matrix is treated as a palindrome when every row reads the same forwards
// and backwards: matrix[i][j] == matrix[i][cols - 1 - j]. Only the first half
// of each row needs to be compared.

// problem_20_isPalindrome_or_not.cpp 

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int randomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

void fillRandomMatrix(int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            matrix[i][j] = randomNumber(1, 100);
        }
    }
}

void printTheRandomMatrix(const int matrix[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            //printf("%0*d    ", 2, matrix[i][j]);
            cout << setw(3) << matrix[i][j] << "    ";
        }
        cout << "\n";
    }
}

int isPalindromeMatrix(int Matrix1[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols / 2; j++)
        {
            if (Matrix1[i][j] != Matrix1[i][cols - 1 - j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    srand((unsigned)time(NULL));

    int matrix[3][3];

    fillRandomMatrix(matrix, 3, 3);
    cout << "Matrix:\n\n";
    printTheRandomMatrix(matrix, 3, 3);

    if (isPalindromeMatrix(matrix, 3, 3))
    {
        cout << "\nYes: Matrix is Palindrome\n";
    }
    else
        cout << "\nNo: Matrix is NOT Palindrome\n";
    return 0;
}
