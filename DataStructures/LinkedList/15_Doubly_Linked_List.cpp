#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* previous;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    newNode->previous = current;
}

void displayForward(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void displayBackward(Node* head) {
    if (head == nullptr) {
        return;
    }

    while (head->next != nullptr) {
        head = head->next;
    }

    while (head != nullptr) {
        cout << head->data << " ";
        head = head->previous;
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

    cout << "Forward traversal: ";
    displayForward(head);

    cout << "Backward traversal: ";
    displayBackward(head);

    deleteList(head);
    return 0;
}

// Time complexity: O(n) for each full traversal.
// Space complexity: O(n) for the doubly linked list.
