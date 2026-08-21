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

Node* mergeSortedLists(Node* first, Node* second) {
    Node dummy{0, nullptr};
    Node* tail = &dummy;

    while (first != nullptr && second != nullptr) {
        if (first->data <= second->data) {
            tail->next = first;
            first = first->next;
        } else {
            tail->next = second;
            second = second->next;
        }
        tail = tail->next;
    }

    tail->next = (first != nullptr) ? first : second;
    return dummy.next;
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
    Node* first = nullptr;
    Node* second = nullptr;
    int n1, n2;

    cout << "Enter number of nodes in first sorted list: ";
    cin >> n1;
    cout << "Enter first sorted list values: ";
    for (int i = 0; i < n1; i++) {
        int value;
        cin >> value;
        append(first, value);
    }

    cout << "Enter number of nodes in second sorted list: ";
    cin >> n2;
    cout << "Enter second sorted list values: ";
    for (int i = 0; i < n2; i++) {
        int value;
        cin >> value;
        append(second, value);
    }

    Node* merged = mergeSortedLists(first, second);
    cout << "Merged sorted list: ";
    display(merged);

    deleteList(merged);
    return 0;
}

// Time complexity: O(n + m), where n and m are the list sizes.
// Space complexity: O(1), excluding the existing list nodes.
