#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Error: Stack is empty" << endl;
            return -1; 
        }
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Error: Stack is empty" << endl;
            return -1; 
        }
        return top->data;
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(6);
    stack.push(8);


    cout << "Top element: " << stack.peek() << endl;

    cout << "Popped elements: ";
    while (!stack.isEmpty()) {
        cout << stack.pop() << " ";
    }

    return 0;
}

