#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be positive.\n";
        return 0;
    }

    int* arr = new int[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int smallestIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[smallestIndex]) {
                smallestIndex = j;
            }
        }
        int temporary = arr[i];
        arr[i] = arr[smallestIndex];
        arr[smallestIndex] = temporary;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i == n - 1 ? '\n' : ' ');
    }

    delete[] arr;
    return 0;
}

// Sorts the array by repeatedly selecting the smallest remaining element.
// Time complexity: O(n^2), Space complexity: O(n)
