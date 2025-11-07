#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cout << "Enter string (no spaces): ";
    cin >> s;

    unordered_map<char,int> freq;
    queue<char> q;

    for (char ch : s) {
        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }
    cout << "\n";
    return 0;
}
