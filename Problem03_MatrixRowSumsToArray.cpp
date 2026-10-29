

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

int RowSum(const int matrix[3][3], short RowIndex, short Cols)
{
    int sum = 0;
    for (short j = 0; j < Cols; j++)
    {
        sum += matrix[RowIndex][j];
    }
    return sum;
}

void SumMatrixRowsInArray(int rowSums[3], const int matrix[3][3], short Rows, short Cols)
{

    for (short i = 0; i < Rows; i++)
    {
        rowSums[i] = RowSum(matrix, i, Cols);
    }

}


void PrintRowSums(int rowSums[3], const int matrix[3][3], short Rows, short Cols)
{
  
    for (short i = 0; i < Rows; i++)
    {
        cout << "Row " << i + 1 << " = " << rowSums[i] << "\n";
    }
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int randomNumber[3][3];
	int rowSums[3];

    FillRandomMatrix(randomNumber, 3, 3);

    cout << "The 3x3 random matrix is:\n\n";
    PrintTheRandomMatrix(randomNumber, 3, 3);
    SumMatrixRowsInArray(rowSums, randomNumber, 3, 3);

    cout << "\n\nThe following are the sums of each row in the matrix:\n\n";
    PrintRowSums(rowSums, randomNumber, 3, 3);

    return 0;
}