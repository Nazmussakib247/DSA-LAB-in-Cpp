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

void sortList(Node* head) {
    for (Node* current = head; current != nullptr; current = current->next) {
        for (Node* nextNode = current->next; nextNode != nullptr; nextNode = nextNode->next) {
            if (current->data > nextNode->data) {
                swap(current->data, nextNode->data);
            }
        }
    }
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

    sortList(head);

    cout << "Sorted linked list: ";
    display(head);

    deleteList(head);
    return 0;
}

// Time complexity: O(n^2) using a simple comparison-based approach.
// Space complexity: O(1).
