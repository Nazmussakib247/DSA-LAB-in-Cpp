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

bool insertAtPosition(Node*& head, int value, int position) {
    if (position < 1) {
        return false;
    }

    if (position == 1) {
        head = new Node{value, head};
        return true;
    }

    Node* current = head;
    for (int i = 1; current != nullptr && i < position - 1; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        return false;
    }

    Node* newNode = new Node{value, current->next};
    current->next = newNode;
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

    int value, position;
    cout << "Enter value and 1-based position: ";
    cin >> value >> position;

    if (insertAtPosition(head, value, position)) {
        cout << "Updated linked list: ";
        display(head);
    } else {
        cout << "Invalid position." << endl;
    }

    deleteList(head);
    return 0;
}

// Time complexity: O(n) to locate the insertion position.
// Space complexity: O(1) for the new node.
