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

    int target;
    cout << "Enter the value to search: ";
    cin >> target;

    int firstPosition = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            firstPosition = i + 1;
            break;
        }
    }

    if (firstPosition == -1) {
        cout << target << " was not found.\n";
    } else {
        cout << target << " was found at position " << firstPosition << ".\n";
    }

    delete[] arr;
    return 0;
}

// Searches an unsorted array sequentially and reports the first one-based position.
// Time complexity: O(n), Space complexity: O(n)
