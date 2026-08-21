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
        newNode->next = head;
        return;
    }

    Node* current = head;
    while (current->next != head) {
        current = current->next;
    }

    current->next = newNode;
    newNode->next = head;
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "The circular list is empty." << endl;
        return;
    }

    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);

    cout << endl;
}

void deleteList(Node*& head) {
    if (head == nullptr) {
        return;
    }

    Node* current = head->next;
    while (current != head) {
        Node* temporary = current;
        current = current->next;
        delete temporary;
    }

    delete head;
    head = nullptr;
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

    cout << "Circular linked list: ";
    display(head);

    deleteList(head);
    return 0;
}

// Time complexity: O(n) for appending and traversal.
// Space complexity: O(n) for storing the circular list.
