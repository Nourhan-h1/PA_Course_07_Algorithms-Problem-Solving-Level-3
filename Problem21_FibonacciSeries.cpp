// problem_21_fibonacciSeries.cpp 


#include <iostream> 
#include <vector> 
#include <iomanip>

using namespace std;

int readPositiveNumber(string message)
{
    int number;
	cout << message;
    cin >> number;

	return number;
}

vector<int> getFibonacciSeries(int numberOfTerms)
{
    vector<int> fibonacciSeries;

    if (numberOfTerms <= 0) return fibonacciSeries;

    if (numberOfTerms == 1) {
        fibonacciSeries.push_back(1);
        return fibonacciSeries;
    }

	fibonacciSeries.push_back(1);
    fibonacciSeries.push_back(1);
    
    for (short i = 0; i < numberOfTerms - 2; i++)
    {
        fibonacciSeries.push_back(fibonacciSeries.at(i) + fibonacciSeries.at(i + 1));
    }
    
	return fibonacciSeries;
}

void printVectorElements(const vector<int>& vElements)
{ 
	for (const int& value : vElements)
	{
		cout << setw(3) << value << "   ";
	}
}

int main() {
    int numberOfTerms = readPositiveNumber("How long do you want the Fibonacci series to be? ");

    vector<int> fibonacciSeries = getFibonacciSeries(numberOfTerms);

    cout << "\nFibonacci Series:\n\n";
    printVectorElements(fibonacciSeries);

    return 0;
}
