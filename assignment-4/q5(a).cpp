#include <iostream>
#include <queue>
using namespace std;

class StackUsingTwoQueues {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Popped: " << q1.front() << "\n";
        q1.pop();
    }

    void top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top: " << q1.front() << "\n";
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    StackUsingTwoQueues st;
    st.push(10);
    st.push(20);
    st.top();
    st.pop();
    st.top();
    return 0;
}
