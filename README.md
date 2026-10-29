# Algorithms & Problem Solving - Level 3

**Course 07 | Programming Advices | Dr. Mohamed Abu-Hadhoud**

C++ solutions to the 51 problems and 2 projects of the *Algorithms & Problem Solving Level 3* course, organized as one source file per problem and one folder per project.

| Problems | Projects | Language | Environment |
| :---: | :---: | :---: | :---: |
| 51 | 2 | C++ | Visual Studio, Windows console |

## Contents

- [About the course](#about-the-course)
- [Learning topics](#learning-topics)
- [Progress summary](#progress-summary)
- [Repository structure](#repository-structure)
- [Problems index](#problems-index)
- [Projects](#projects)
- [Building and running](#building-and-running)

## About the course

This course is part of the C++ track taught by Dr. Mohamed Abu-Hadhoud on the Programming Advices platform. This repository holds my solutions to its problems and projects. Every problem is a standalone console program with its own `main()` function.

The previous course in my learning path is in [PA_Course_05_Algorithms-Problem-Solving-](https://github.com/Nourhan-h1/PA_Course_05_Algorithms-Problem-Solving-).

## Learning topics

The topics below are the ones the solutions in this repository actually use.

| Topic | Problems | What the solutions cover |
| :--- | :---: | :--- |
| Matrices (2D arrays) | 01-20 | Filling, printing and analysing 3x3 matrices: row/column sums, transpose, element-wise multiplication, comparison, special matrix types, searching, min/max and intersection. |
| Series and recursion | 21-22 | The Fibonacci series built with a loop and a vector, then with a recursive function. |
| Characters and letter case | 23-34 | Per-character processing with `<cctype>`: first letters, converting and inverting case, counting letters, and working with vowels. |
| Words and strings | 35-44 | A `find()`/`substr()`/`erase()` tokenizer, `vector<string>`, trimming, joining (with overloading), reversing, replacing words and removing punctuation. |
| Records and files | 45-51 | A client `struct`, converting records to delimited lines and back, and file operations with `fstream`: add, list, find, delete and update. |
| Console applications | Projects 01-02 | Menu-driven programs built with `enum`s, a `struct`, functions, a nested menu and file persistence. |

## Progress summary

| Item | Count |
| :--- | :---: |
| Problem solutions | 51 |
| Projects | 2 |

## Repository structure

```text
Course_07_Algorithms_Problem_Solving_Level_3/
|-- README.md
|-- .gitignore
|-- Course_07_Projects.slnx          Visual Studio solution for the two projects
|-- Problems/
|   |-- Problem01_RandomMatrix.cpp
|   |-- Problem02_SumOfMatrixRows.cpp
|   |-- ...                          (51 files: Problem01 ... Problem51)
|   `-- Problem51_UpdateClientByAccountNumber.cpp
`-- Projects/
    |-- Project01_BankSystem/
    |   |-- Project01_BankSystem.cpp
    |   |-- Project01_BankSystem.vcxproj
    |   `-- Project01_BankSystem.vcxproj.filters
    `-- Project02_BankSystemExtension/
        |-- Project02_BankSystemExtension.cpp
        |-- Project02_BankSystemExtension.vcxproj
        `-- Project02_BankSystemExtension.vcxproj.filters
```

## Problems index

Titles and descriptions are based on what each program does. Click a file name to open the source.

### Matrices (2D arrays) (Problems 01-20)

| # | Problem | Description | Source |
| :---: | :--- | :--- | :--- |
| 01 | Random Matrix | Fills a 3x3 matrix with random numbers (1-100) and prints it. | [Problem01_RandomMatrix.cpp](Problems/Problem01_RandomMatrix.cpp) |
| 02 | Sum of Matrix Rows | Prints the sum of each row of a random 3x3 matrix. | [Problem02_SumOfMatrixRows.cpp](Problems/Problem02_SumOfMatrixRows.cpp) |
| 03 | Matrix Row Sums to 1D Array | Stores the sum of each row in a one-dimensional array and prints it. | [Problem03_MatrixRowSumsToArray.cpp](Problems/Problem03_MatrixRowSumsToArray.cpp) |
| 04 | Sum of Matrix Columns | Prints the sum of each column of a random 3x3 matrix. | [Problem04_SumOfMatrixColumns.cpp](Problems/Problem04_SumOfMatrixColumns.cpp) |
| 05 | Matrix Column Sums to 1D Array | Stores the sum of each column in a one-dimensional array and prints it. | [Problem05_MatrixColumnSumsToArray.cpp](Problems/Problem05_MatrixColumnSumsToArray.cpp) |
| 06 | Ordered Matrix | Fills a 3x3 matrix with the numbers 1 to 9 in order. | [Problem06_OrderedMatrix.cpp](Problems/Problem06_OrderedMatrix.cpp) |
| 07 | Transpose Matrix | Prints an ordered 3x3 matrix and its transpose. | [Problem07_TransposeMatrix.cpp](Problems/Problem07_TransposeMatrix.cpp) |
| 08 | Multiply Two Random Matrices | Multiplies two random matrices element by element and prints the result. | [Problem08_MultiplyTwoRandomMatrices.cpp](Problems/Problem08_MultiplyTwoRandomMatrices.cpp) |
| 09 | Print Middle Row and Column | Prints the middle row and the middle column of a random matrix. | [Problem09_PrintMiddleRowAndColumn.cpp](Problems/Problem09_PrintMiddleRowAndColumn.cpp) |
| 10 | Sum of Matrix Elements | Calculates the sum of all elements in a random matrix. | [Problem10_SumOfMatrixElements.cpp](Problems/Problem10_SumOfMatrixElements.cpp) |
| 11 | Compare Matrices by Sum | Checks whether two random matrices have the same sum of elements. | [Problem11_CompareMatricesBySum.cpp](Problems/Problem11_CompareMatricesBySum.cpp) |
| 12 | Compare Typical Matrices | Checks whether two random matrices are identical, element by element. | [Problem12_CompareTypicalMatrices.cpp](Problems/Problem12_CompareTypicalMatrices.cpp) |
| 13 | Identity Matrix Check | Checks whether a matrix is an identity matrix. | [Problem13_IdentityMatrixCheck.cpp](Problems/Problem13_IdentityMatrixCheck.cpp) |
| 14 | Scalar Matrix Check | Checks whether a matrix is a scalar matrix. | [Problem14_ScalarMatrixCheck.cpp](Problems/Problem14_ScalarMatrixCheck.cpp) |
| 15 | Count Number in Matrix | Counts how many times a number entered by the user appears in a matrix. | [Problem15_CountNumberInMatrix.cpp](Problems/Problem15_CountNumberInMatrix.cpp) |
| 16 | Sparse Matrix Check | Checks whether a matrix is sparse (more zeros than non-zero elements). | [Problem16_SparseMatrixCheck.cpp](Problems/Problem16_SparseMatrixCheck.cpp) |
| 17 | Check Number Exists in Matrix | Checks whether a number entered by the user exists in a random matrix. | [Problem17_CheckNumberExistsInMatrix.cpp](Problems/Problem17_CheckNumberExistsInMatrix.cpp) |
| 18 | Intersected Numbers in Matrices | Prints the numbers that appear in both of two random matrices. | [Problem18_IntersectedNumbersInMatrices.cpp](Problems/Problem18_IntersectedNumbersInMatrices.cpp) |
| 19 | Min and Max in Matrix | Finds the minimum and maximum numbers in a random matrix. | [Problem19_MinAndMaxInMatrix.cpp](Problems/Problem19_MinAndMaxInMatrix.cpp) |
| 20 | Palindrome Matrix Check | Checks whether every row of a random matrix reads the same in both directions. | [Problem20_PalindromeMatrixCheck.cpp](Problems/Problem20_PalindromeMatrixCheck.cpp) |

### Series and recursion (Problems 21-22)

| # | Problem | Description | Source |
| :---: | :--- | :--- | :--- |
| 21 | Fibonacci Series | Prints a Fibonacci series of the length chosen by the user (loop and vector). | [Problem21_FibonacciSeries.cpp](Problems/Problem21_FibonacciSeries.cpp) |
| 22 | Fibonacci Series by Recursion | Prints the first 10 Fibonacci numbers using a recursive function. | [Problem22_FibonacciSeriesByRecursion.cpp](Problems/Problem22_FibonacciSeriesByRecursion.cpp) |

### Characters and letter case (Problems 23-34)

| # | Problem | Description | Source |
| :---: | :--- | :--- | :--- |
| 23 | First Letter of Each Word | Prints the first letter of every word in a string. | [Problem23_FirstLetterOfEachWord.cpp](Problems/Problem23_FirstLetterOfEachWord.cpp) |
| 24 | Uppercase First Letter of Each Word | Converts the first letter of every word to uppercase. | [Problem24_UppercaseFirstLetterOfEachWord.cpp](Problems/Problem24_UppercaseFirstLetterOfEachWord.cpp) |
| 25 | Lowercase First Letter of Each Word | Converts the first letter of every word to lowercase. | [Problem25_LowercaseFirstLetterOfEachWord.cpp](Problems/Problem25_LowercaseFirstLetterOfEachWord.cpp) |
| 26 | Upper and Lower All Letters | Converts a whole string to uppercase and to lowercase. | [Problem26_UpperAndLowerAllLetters.cpp](Problems/Problem26_UpperAndLowerAllLetters.cpp) |
| 27 | Invert Character Case | Inverts the case of a single character. | [Problem27_InvertCharacterCase.cpp](Problems/Problem27_InvertCharacterCase.cpp) |
| 28 | Invert Case of All Letters | Inverts the case of every letter in a string. | [Problem28_InvertAllLettersCase.cpp](Problems/Problem28_InvertAllLettersCase.cpp) |
| 29 | Count Small and Capital Letters | Prints the string length and the number of small and capital letters. | [Problem29_CountSmallAndCapitalLetters.cpp](Problems/Problem29_CountSmallAndCapitalLetters.cpp) |
| 30 | Count Character in Text | Counts how many times a given character appears in a text. | [Problem30_CountCharacterInText.cpp](Problems/Problem30_CountCharacterInText.cpp) |
| 31 | Count Letter (Match Case or Not) | Counts a letter in a text, with and without case sensitivity. | [Problem31_CountLetterMatchCase.cpp](Problems/Problem31_CountLetterMatchCase.cpp) |
| 32 | Vowel Check | Checks whether a character is a vowel. | [Problem32_VowelCheck.cpp](Problems/Problem32_VowelCheck.cpp) |
| 33 | Count Vowels in Text | Counts the vowels in a text. | [Problem33_CountVowelsInText.cpp](Problems/Problem33_CountVowelsInText.cpp) |
| 34 | Print Vowels in Text | Prints every vowel found in a text. | [Problem34_PrintVowelsInText.cpp](Problems/Problem34_PrintVowelsInText.cpp) |

### Words and strings (Problems 35-44)

| # | Problem | Description | Source |
| :---: | :--- | :--- | :--- |
| 35 | Print All Words in Text | Splits a text on spaces and prints each word on its own line. | [Problem35_PrintAllWordsInText.cpp](Problems/Problem35_PrintAllWordsInText.cpp) |
| 36 | Count Words in Text | Counts the number of words in a text. | [Problem36_CountWordsInText.cpp](Problems/Problem36_CountWordsInText.cpp) |
| 37 | Split Words into Vector | Splits a text into a vector of words using a delimiter. | [Problem37_SplitWordsIntoVector.cpp](Problems/Problem37_SplitWordsIntoVector.cpp) |
| 38 | Trim Left, Right and Both | Removes leading, trailing, or both leading and trailing spaces. | [Problem38_TrimLeftRightAll.cpp](Problems/Problem38_TrimLeftRightAll.cpp) |
| 39 | Join Vector with Delimiter | Joins the words of a vector into one string with a delimiter. | [Problem39_JoinVectorWithDelimiter.cpp](Problems/Problem39_JoinVectorWithDelimiter.cpp) |
| 40 | Join Overloading | Overloaded join function that works with a vector or an array of strings. | [Problem40_JoinOverloading.cpp](Problems/Problem40_JoinOverloading.cpp) |
| 41 | Reverse Words in Text | Reverses the order of the words in a text. | [Problem41_ReverseWordsInText.cpp](Problems/Problem41_ReverseWordsInText.cpp) |
| 42 | Replace Word in Text | Replaces a word in a text with another word. | [Problem42_ReplaceWordInText.cpp](Problems/Problem42_ReplaceWordInText.cpp) |
| 43 | Replace Word (Match Case or Not) | Replaces a word with or without case sensitivity. | [Problem43_ReplaceWordMatchCase.cpp](Problems/Problem43_ReplaceWordMatchCase.cpp) |
| 44 | Remove Punctuations | Removes all punctuation characters from a text. | [Problem44_RemovePunctuations.cpp](Problems/Problem44_RemovePunctuations.cpp) |

### Records and files (Problems 45-51)

| # | Problem | Description | Source |
| :---: | :--- | :--- | :--- |
| 45 | Client Record to Line | Reads a client record and converts it to a single delimited line. | [Problem45_ClientRecordToLine.cpp](Problems/Problem45_ClientRecordToLine.cpp) |
| 46 | Line to Client Record | Converts a delimited line back into a client record and prints it. | [Problem46_LineToClientRecord.cpp](Problems/Problem46_LineToClientRecord.cpp) |
| 47 | Add Clients to File | Reads clients from the user and appends them to a text file. | [Problem47_AddClientsToFile.cpp](Problems/Problem47_AddClientsToFile.cpp) |
| 48 | Show All Clients from File | Loads the clients file and prints all clients in a table. | [Problem48_ShowAllClientsFromFile.cpp](Problems/Problem48_ShowAllClientsFromFile.cpp) |
| 49 | Find Client by Account Number | Searches the clients file for an account number and prints the client. | [Problem49_FindClientByAccountNumber.cpp](Problems/Problem49_FindClientByAccountNumber.cpp) |
| 50 | Delete Client by Account Number | Deletes a client by account number and rewrites the file. | [Problem50_DeleteClientByAccountNumber.cpp](Problems/Problem50_DeleteClientByAccountNumber.cpp) |
| 51 | Update Client by Account Number | Updates a client's data by account number and rewrites the file. | [Problem51_UpdateClientByAccountNumber.cpp](Problems/Problem51_UpdateClientByAccountNumber.cpp) |

## Projects

### Project 01 - Bank System

A console application for managing bank clients.

- Main menu: show client list, add, delete, update, find, exit.
- Adding a client is rejected when the account number already exists.
- Deleting and updating ask for confirmation first.
- Clients are saved in `Clients.txt`, one line per client, with fields separated by `#//#`.

Source: [Project01_BankSystem](Projects/Project01_BankSystem/) - [Project01_BankSystem.cpp](Projects/Project01_BankSystem/Project01_BankSystem.cpp)

### Project 02 - Bank System Extension

Extends Project 01 with a transaction menu.

- Everything from Project 01.
- Transaction menu: deposit, withdraw, show total balances, back to the main menu.
- Deposits and withdrawals ask for an existing account number and a confirmation; a withdrawal larger than the balance is refused.
- Empty records are skipped when the clients file is loaded.

Source: [Project02_BankSystemExtension](Projects/Project02_BankSystemExtension/) - [Project02_BankSystemExtension.cpp](Projects/Project02_BankSystemExtension/Project02_BankSystemExtension.cpp)

## Building and running

**Visual Studio (Windows).** Open `Course_07_Projects.slnx` to build the two projects (configured for C++20). A single problem can be built by adding its `.cpp` file to any empty console project.

**Command line.** Each problem is an independent program, so compile them one at a time:

```bash
g++ -std=c++20 Problems/Problem22_FibonacciSeriesByRecursion.cpp -o problem22
./problem22
```

Notes:

- Problems 47-51 and both projects call `system("cls")` and/or `system("pause>0")`, which are Windows console commands, so they behave as intended in a Windows terminal.
- The client programs read and write `Clients.txt` in the folder they run from. The file is created when the first client is added, and it is not tracked by Git.

## Closing

This repository is part of my ongoing C++ learning journey.

Maintained by [Nourhan-h1](https://github.com/Nourhan-h1).
