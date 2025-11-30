#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
};

// --------------------------
// Doubly Linked List
// --------------------------
class DoublyLL {
public:
    Node* head;
    DoublyLL() { head = NULL; }

    void insertFirst(int x) {
        Node* n = new Node{x, head, NULL};
        if (head != NULL) head->prev = n;
        head = n;
    }

    void insertLast(int x) {
        Node* n = new Node{x, NULL, NULL};
        if (head == NULL) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    void insertAfter(int key, int x) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Node not found\n"; return; }

        Node* n = new Node{x, temp->next, temp};
        if (temp->next) temp->next->prev = n;
        temp->next = n;
    }

    void insertBefore(int key, int x) {
        if (!head) return;
        if (head->data == key) {
            insertFirst(x);
            return;
        }
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Node not found\n"; return; }

        Node* n = new Node{x, temp, temp->prev};
        temp->prev->next = n;
        temp->prev = n;
    }

    void deleteNode(int key) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Node not found\n"; return; }

        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;

        if (temp->next) temp->next->prev = temp->prev;

        delete temp;
        cout << "Node deleted.\n";
    }

    void search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key) {
                cout << "Found\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Not Found\n";
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// --------------------------
// Circular Linked List
// --------------------------
class CircularLL {
public:
    Node* head;
    CircularLL() { head = NULL; }

    void insertFirst(int x) {
        Node* n = new Node{x, NULL, NULL};
        if (head == NULL) {
            n->next = n;
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;

        n->next = head;
        temp->next = n;
        head = n;
    }

    void insertLast(int x) {
        Node* n = new Node{x, NULL, NULL};
        if (head == NULL) {
            n->next = n;
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;

        temp->next = n;
        n->next = head;
    }

    void insertAfter(int key, int x) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* n = new Node{x, temp->next, NULL};
                temp->next = n;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found\n";
    }

    void insertBefore(int key, int x) {
        if (!head) return;

        if (head->data == key) {
            insertFirst(x);
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        do {
            prev = temp;
            temp = temp->next;
        } while (temp != head && temp->data != key);

        if (temp == head) {
            cout << "Node not found\n";
            return;
        }

        Node* n = new Node{x, temp, NULL};
        prev->next = n;
    }

    void deleteNode(int key) {
        if (!head) return;

        Node *temp = head, *prev = NULL;

        if (head->data == key) {
            if (head->next == head) {
                delete head;
                head = NULL;
                return;
            }
            Node* last = head;
            while (last->next != head) last = last->next;

            last->next = head->next;
            temp = head;
            head = head->next;
            delete temp;
            return;
        }

        do {
            prev = temp;
            temp = temp->next;
        } while (temp != head && temp->data != key);

        if (temp == head) {
            cout << "Node not found\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    void search(int key) {
        if (!head) { cout << "Not Found\n"; return; }

        Node* temp = head;
        do {
            if (temp->data == key) {
                cout << "Found\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Not Found\n";
    }

    void display() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

// --------------------------
// MAIN MENU
// --------------------------
int main() {
    DoublyLL dll;
    CircularLL cll;

    int choice, listType;
    while (1) {
        cout << "\n1. Doubly Linked List\n2. Circular Linked List\n3. Exit\nEnter: ";
        cin >> listType;

        if (listType == 3) break;

        cout << "\n1.Insert First\n2.Insert Last\n3.Insert After\n4.Insert Before\n";
        cout << "5.Delete Node\n6.Search Node\n7.Display\nEnter choice: ";
        cin >> choice;

        int x, key;

        if (listType == 1) {   // Doubly LL
            switch (choice) {
                case 1: cout << "Enter value: "; cin >> x; dll.insertFirst(x); break;
                case 2: cout << "Enter value: "; cin >> x; dll.insertLast(x); break;
                case 3: cout << "Enter key & value: "; cin >> key >> x; dll.insertAfter(key, x); break;
                case 4: cout << "Enter key & value: "; cin >> key >> x; dll.insertBefore(key, x); break;
                case 5: cout << "Enter key: "; cin >> key; dll.deleteNode(key); break;
                case 6: cout << "Enter key: "; cin >> key; dll.search(key); break;
                case 7: dll.display(); break;
            }
        }

        else if (listType == 2) {   // Circular LL
            switch (choice) {
                case 1: cout << "Enter value: "; cin >> x; cll.insertFirst(x); break;
                case 2: cout << "Enter value: "; cin >> x; cll.insertLast(x); break;
                case 3: cout << "Enter key & value: "; cin >> key >> x; cll.insertAfter(key, x); break;
                case 4: cout << "Enter key & value: "; cin >> key >> x; cll.insertBefore(key, x); break;
                case 5: cout << "Enter key: "; cin >> key; cll.deleteNode(key); break;
                case 6: cout << "Enter key: "; cin >> key; cll.search(key); break;
                case 7: cll.display(); break;
            }
        }
    }
    return 0;
}
