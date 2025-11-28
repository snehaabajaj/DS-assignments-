#include <iostream>
#include <queue>
using namespace std;

class StackOneQ {
    queue<int> q;
public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    void top() {
        if (q.empty())
            cout << "Stack is Empty!\n";
        else
            cout << "Top element: " << q.front() << endl;
    }
};

int main() {
    StackOneQ s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.top();
    s.pop();
    s.top();
}
