#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this -> data = data;
        this -> next = nullptr;
    }
};

class LinkedList
{
    public:
    Node* head;

    LinkedList()
    {
        this -> head = nullptr;
    }

    void append(int data)
    {
        Node* newNode = new Node(data);

        if(head == nullptr)
        {
            head = newNode;
            return;
        }

        Node* current = head;
        while(current -> next != nullptr)
        {
            current = current -> next;
        }
        current -> next = newNode;
    }

    void display(){
        Node* current = head;
        while(current -> next != nullptr)
        {   
            cout << current -> data << endl;
            current = current -> next;
        }
        cout << current -> data << endl;
    }
    void reverse() {
    if (head == nullptr || head->next == nullptr) {
        return; 
    }

    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next; 

        current->next = prev; 

        prev = current; 
        current = next; 
    }

    head = prev; 
    }   

};



int main(){
    LinkedList list;
    list.append(2);
    list.append(6);
    list.append(7);
    list.append(8);
    list.append(9);
    list.append(10);

    list.reverse();

    list.display();

    return 0;
}