#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

int search(Node* head, int target) {
    int position = 1;

    while (head != nullptr) {
        if (head->data == target) {
            return position;
        }
        head = head->next;
        position++;
    }

    return -1;
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temporary = head;
        head = head->next;
        delete temporary;
    }
}

int main() {
    Node* head = nullptr;
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        append(head, value);
    }

    int target;
    cout << "Enter value to search: ";
    cin >> target;

    int position = search(head, target);
    if (position == -1) {
        cout << "Value not found." << endl;
    } else {
        cout << "Value found at position " << position << "." << endl;
    }

    deleteList(head);
    return 0;
}

// Time complexity: O(n) in the worst case.
// Space complexity: O(1).
