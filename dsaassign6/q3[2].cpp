#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLL {
public:
    Node* head;

    CircularLL() {
        head = NULL;
    }

    void insertLast(int x) {
        Node* n = new Node{x, NULL};
        if (head == NULL) {
            head = n;
            n->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = n;
        n->next = head;
    }

    int size() {
        if (head == NULL) return 0;

        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);

        return count;
    }
};

int main() {
    CircularLL cll;

    cll.insertLast(5);
    cll.insertLast(15);
    cll.insertLast(25);
    cll.insertLast(35);

    cout << "Size of Circular Linked List: " << cll.size() << endl;

    return 0;
}
