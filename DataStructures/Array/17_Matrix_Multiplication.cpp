#include <iostream>
using namespace std;

int main() {
    int firstRows, firstColumns, secondRows, secondColumns;
    cout << "Enter rows and columns of the first matrix: ";
    cin >> firstRows >> firstColumns;
    cout << "Enter rows and columns of the second matrix: ";
    cin >> secondRows >> secondColumns;

    if (firstRows <= 0 || firstColumns <= 0 || secondRows <= 0 || secondColumns <= 0) {
        cout << "Matrix dimensions must be positive.\n";
        return 0;
    }
    if (firstColumns != secondRows) {
        cout << "Multiplication is not possible: columns of the first matrix "
             << "must equal rows of the second matrix.\n";
        return 0;
    }

    int** first = new int*[firstRows];
    int** second = new int*[secondRows];
    int** product = new int*[firstRows];
    for (int i = 0; i < firstRows; ++i) {
        first[i] = new int[firstColumns];
        product[i] = new int[secondColumns]{};
    }
    for (int i = 0; i < secondRows; ++i) {
        second[i] = new int[secondColumns];
    }

    cout << "Enter the first matrix:\n";
    for (int i = 0; i < firstRows; ++i) {
        for (int j = 0; j < firstColumns; ++j) {
            cin >> first[i][j];
        }
    }

    cout << "Enter the second matrix:\n";
    for (int i = 0; i < secondRows; ++i) {
        for (int j = 0; j < secondColumns; ++j) {
            cin >> second[i][j];
        }
    }

    for (int i = 0; i < firstRows; ++i) {
        for (int j = 0; j < secondColumns; ++j) {
            for (int k = 0; k < firstColumns; ++k) {
                product[i][j] += first[i][k] * second[k][j];
            }
        }
    }

    cout << "Product matrix:\n";
    for (int i = 0; i < firstRows; ++i) {
        for (int j = 0; j < secondColumns; ++j) {
            cout << product[i][j]
                 << (j == secondColumns - 1 ? '\n' : ' ');
        }
    }

    for (int i = 0; i < firstRows; ++i) {
        delete[] first[i];
        delete[] product[i];
    }
    for (int i = 0; i < secondRows; ++i) {
        delete[] second[i];
    }
    delete[] first;
    delete[] second;
    delete[] product;
    return 0;
}

// Multiplies compatible matrices using the standard three-loop algorithm.
// Time complexity: O(firstRows * firstColumns * secondColumns), Space complexity: O(firstRows * secondColumns)
