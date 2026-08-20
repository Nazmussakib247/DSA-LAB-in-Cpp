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

    int uniqueCount = 0;
    for (int i = 0; i < n; ++i) {
        bool alreadyPresent = false;
        for (int j = 0; j < uniqueCount; ++j) {
            if (arr[j] == arr[i]) {
                alreadyPresent = true;
                break;
            }
        }
        if (!alreadyPresent) {
            arr[uniqueCount++] = arr[i];
        }
    }

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < uniqueCount; ++i) {
        cout << arr[i] << (i == uniqueCount - 1 ? '\n' : ' ');
    }

    delete[] arr;
    return 0;
}

// Keeps the first occurrence of each value and preserves the original order.
// Time complexity: O(n^2), Space complexity: O(n)
