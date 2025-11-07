#include <iostream>
#include <queue>
using namespace std;

class StackUsingOneQueue {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < (int)q.size()-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Popped: " << q.front() << "\n";
        q.pop();
    }

    void top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top: " << q.front() << "\n";
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    StackUsingOneQueue st;
    st.push(10);
    st.push(20);
    st.top();
    st.pop();
    st.top();
    return 0;
}
