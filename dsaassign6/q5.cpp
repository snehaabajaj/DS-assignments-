#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insertLast(int x) {
        Node* n = new Node{x, NULL};

        if (head == NULL) {
            head = n;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = n;
    }

    // Function to check if list is circular
    bool isCircular() {
        if (head == NULL) return true;   // Empty list considered circular

        Node* temp = head->next;

        while (temp != NULL && temp != head)
            temp = temp->next;

        return (temp == head);
    }
};

int main() {
    LinkedList ll;

    // Example input: 2 -> 4 -> 6 -> 7 -> 5
    ll.insertLast(2);
    ll.insertLast(4);
    ll.insertLast(6);
    ll.insertLast(7);
    ll.insertLast(5);

    // Make it circular manually (optional)
    // ll.head->next->next->next->next->next = ll.head;  // Uncomment to test circular case

    if (ll.isCircular())
        cout << "Circular Linked List";
    else
        cout << "Not Circular Linked List";

    return 0;
}
