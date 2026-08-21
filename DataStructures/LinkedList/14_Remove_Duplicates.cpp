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

void removeDuplicates(Node* head) {
    while (head != nullptr && head->next != nullptr) {
        if (head->data == head->next->data) {
            Node* duplicate = head->next;
            head->next = duplicate->next;
            delete duplicate;
        } else {
            head = head->next;
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

    cout << "Enter number of nodes in the sorted list: ";
    cin >> n;

    cout << "Enter sorted node values: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        append(head, value);
    }

    removeDuplicates(head);

    cout << "List after removing duplicates: ";
    display(head);

    deleteList(head);
    return 0;
}

// Time complexity: O(n) for a sorted linked list.
// Space complexity: O(1).
