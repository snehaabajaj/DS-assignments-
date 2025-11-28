#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int items[SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear == SIZE - 1);
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is Full!\n";
        } else {
            if (front == -1) front = 0;
            items[++rear] = element;
            cout << "Inserted: " << element << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
        } else {
            cout << "Deleted: " << items[front++] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++)
                cout << items[i] << " ";
            cout << endl;
        }
    }

    void peek() {
        if (isEmpty())
            cout << "Queue is Empty!\n";
        else
            cout << "Front element: " << items[front] << endl;
    }
};

int main() {
    Queue q;
    int choice, val;
    while (true) {
        cout << "\n--- SIMPLE QUEUE MENU ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            q.enqueue(val);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}
