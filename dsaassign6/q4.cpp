#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

class DoublyLL {
public:
    Node* head;

    DoublyLL() {
        head = NULL;
    }

    void insertLast(char x) {
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

    bool isPalindrome() {
        if (head == NULL || head->next == NULL)
            return true;

        Node* left = head;
        Node* right = head;

        // move right to last node
        while (right->next != NULL)
            right = right->next;

        // compare from both ends
        while (left != right && left->prev != right) {
            if (left->data != right->data)
                return false;

            left = left->next;
            right = right->prev;
        }

        return true;
    }
};

int main() {
    DoublyLL dll;

    // Example input: "MADAM"
    dll.insertLast('M');
    dll.insertLast('A');
    dll.insertLast('D');
    dll.insertLast('A');
    dll.insertLast('M');

    if (dll.isPalindrome())
        cout << "True";
    else
        cout << "False";

    return 0;
}
