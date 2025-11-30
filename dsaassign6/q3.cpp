#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLL {
public:
    Node* head;

    DoublyLL() {
        head = NULL;
    }

    void insertLast(int x) {
        Node* n = new Node{x, NULL, NULL};
        if (head == NULL) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    DoublyLL dll;

    dll.insertLast(10);
    dll.insertLast(20);
    dll.insertLast(30);

    cout << "Size of Doubly Linked List: " << dll.size() << endl;

    return 0;
}
