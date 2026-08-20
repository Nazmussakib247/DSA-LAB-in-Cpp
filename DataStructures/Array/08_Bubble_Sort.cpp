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

    for (int pass = 0; pass < n - 1; ++pass) {
        bool swapped = false;
        for (int i = 0; i < n - pass - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                int temporary = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temporary;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i == n - 1 ? '\n' : ' ');
    }

    delete[] arr;
    return 0;
}

// Sorts the array in ascending order using adjacent swaps.
// Time complexity: O(n^2) worst case, O(n) best case; Space complexity: O(n)
