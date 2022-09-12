#include<bits/stdc++.h>
using namespace std;

class Stack {
    private:
        int count;
        priority_queue<pair<int, int>> stck;
    public:
        Stack() {
            count = 0;
        }

        void push(int x) {
            stck.push({x, count});
            count++;
            cout << "Pushed value " << x << " into the Stack!" << endl;
        }

        int pop() {
            if(!stck.empty()) {
                int ans = stck.top().first;
                stck.pop();
                count--;
                cout << "Popped value " << ans << " off the Stack!" << endl;
                return ans;
            }
            else {
                cout << "Stack Empty! Returning -1" << endl;
                return -1;
            }
        }
};

int main() {
    Stack* s = new Stack();
    s->push(10);
    s->push(20);
    s->push(30);
    s->pop();
    s->push(40);
    s->pop();
    s->pop();
    s->pop();
    s->pop();
    return 0;
}
