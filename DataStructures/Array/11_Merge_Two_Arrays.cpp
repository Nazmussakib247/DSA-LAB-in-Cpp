#include <iostream>
using namespace std;

void printArray(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << (i == size - 1 ? '\n' : ' ');
    }
}

int main() {
    int firstSize, secondSize;
    cout << "Enter the size of the first array: ";
    cin >> firstSize;
    cout << "Enter the size of the second array: ";
    cin >> secondSize;

    if (firstSize < 0 || secondSize < 0) {
        cout << "Array sizes cannot be negative.\n";
        return 0;
    }

    int* first = new int[firstSize];
    int* second = new int[secondSize];
    int* merged = new int[firstSize + secondSize];

    cout << "Enter the first array: ";
    for (int i = 0; i < firstSize; ++i) {
        cin >> first[i];
        merged[i] = first[i];
    }

    cout << "Enter the second array: ";
    for (int i = 0; i < secondSize; ++i) {
        cin >> second[i];
        merged[firstSize + i] = second[i];
    }

    cout << "Merged array: ";
    if (firstSize + secondSize == 0) {
        cout << "(empty)\n";
    } else {
        printArray(merged, firstSize + secondSize);
    }

    delete[] first;
    delete[] second;
    delete[] merged;
    return 0;
}

// Combines two arrays by placing the second array after the first array.
// Time complexity: O(n + m), Space complexity: O(n + m)
