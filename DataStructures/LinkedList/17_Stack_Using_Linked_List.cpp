#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node*& top, int value) {
    top = new Node{value, top};
}

bool pop(Node*& top, int& removedValue) {
    if (top == nullptr) {
        return false;
    }

    Node* temporary = top;
    removedValue = top->data;
    top = top->next;
    delete temporary;
    return true;
}

bool peek(Node* top, int& topValue) {
    if (top == nullptr) {
        return false;
    }

    topValue = top->data;
    return true;
}

void display(Node* top) {
    while (top != nullptr) {
        cout << top->data << " ";
        top = top->next;
    }
    cout << endl;
}

void deleteStack(Node*& top) {
    while (top != nullptr) {
        Node* temporary = top;
        top = top->next;
        delete temporary;
    }
}

int main() {
    Node* top = nullptr;
    int n;

    cout << "Enter number of values to push: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        push(top, value);
    }

    cout << "Stack from top to bottom: ";
    display(top);

    int topValue;
    if (peek(top, topValue)) {
        cout << "Top value: " << topValue << endl;
    }

    int removedValue;
    if (pop(top, removedValue)) {
        cout << "Popped value: " << removedValue << endl;
        cout << "Stack after pop: ";
        display(top);
    }

    deleteStack(top);
    return 0;
}

// Time complexity: O(1) for push, pop, and peek.
// Space complexity: O(n) for the stack nodes.
