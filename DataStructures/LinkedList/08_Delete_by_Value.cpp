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

bool deleteByValue(Node*& head, int value) {
    if (head == nullptr) {
        return false;
    }

    if (head->data == value) {
        Node* temporary = head;
        head = head->next;
        delete temporary;
        return true;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    if (current->next == nullptr) {
        return false;
    }

    Node* temporary = current->next;
    current->next = temporary->next;
    delete temporary;
    return true;
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
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

    int value;
    cout << "Enter value to delete: ";
    cin >> value;

    if (deleteByValue(head, value)) {
        cout << "After deleting the first occurrence: ";
        display(head);
    } else {
        cout << "Value not found." << endl;
    }

    deleteList(head);
    return 0;
}

// Time complexity: O(n) in the worst case.
// Space complexity: O(1).
