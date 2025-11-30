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

    void displayWithHeadAgain() {
        if (head == NULL) return;

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << head->data;   // print head again
        cout << endl;
    }
};

int main() {
    CircularLL cll;

    // Given input: 20 → 100 → 40 → 80 → 60
    cll.insertLast(20);
    cll.insertLast(100);
    cll.insertLast(40);
    cll.insertLast(80);
    cll.insertLast(60);

    cout << "Output: ";
    cll.displayWithHeadAgain();

    return 0;
}
