#include <iostream>
#include <queue>
using namespace std;

void firstNonRepeating(string s) {
    queue<char> q;
    int freq[26] = {0};

    for (char ch : s) {
        freq[ch - 'a']++;
        q.push(ch);

        while (!q.empty() && freq[q.front() - 'a'] > 1)
            q.pop();

        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    cout << "Output: ";
    firstNonRepeating(s);
}
