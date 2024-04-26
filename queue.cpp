#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> inbox;  
    stack<int> outbox; 


    void transferInboxToOutbox() {
        while (!inbox.empty()) {
            outbox.push(inbox.top());
            inbox.pop();
        }
    }

public:

    void enqueue(int x) {
        inbox.push(x);
    }


    int dequeue() {
        if (outbox.empty()) {
            transferInboxToOutbox();
        }
        int front = outbox.top();
        outbox.pop();
        return front;
    }


    bool isEmpty() {
        return inbox.empty() && outbox.empty();
    }
};

int main() {
    MyQueue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(6);

    cout << "Dequeue: " << q.dequeue() << endl; 
    cout << "Dequeue: " << q.dequeue() << endl; 

    q.enqueue(4);
    q.enqueue(5);

    while (!q.isEmpty()) {
        cout << "Dequeue: " << q.dequeue() << endl; 
    }

    return 0;
}
