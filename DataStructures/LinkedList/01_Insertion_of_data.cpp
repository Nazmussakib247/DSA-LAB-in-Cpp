#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {

    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();

    first->data = 10;
    second->data = 20;
    third->data = 30;

    first->next = second;
    second->next = third;
    third->next = nullptr;

    Node* head = first;

    cout << head->data << endl;
    cout << head->next->data << endl;
    cout << head->next->next->data << endl;

    return 0;
}