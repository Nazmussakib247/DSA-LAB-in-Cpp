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

    for (int left = 0, right = n - 1; left < right; ++left, --right) {
        int temporary = arr[left];
        arr[left] = arr[right];
        arr[right] = temporary;
    }

    cout << "Reversed array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i == n - 1 ? '\n' : ' ');
    }

    delete[] arr;
    return 0;
}

// Reverses an array in place by swapping matching elements from both ends.
// Time complexity: O(n), Space complexity: O(n)
