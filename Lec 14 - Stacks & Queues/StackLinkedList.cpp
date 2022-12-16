#include <iostream>
#include "Node.cpp"

using namespace std;

template<typename T>
class StackLinkedList{
    Node<T>* head = 0;
    int sz = 0;

    public:
    
    int size(){
        return sz;
    }

    bool isEmpty(){
        return sz == 0;
    }

    void push(T val){
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
        sz++;
    }

    T pop(){
        if(isEmpty()){
            cout << "Stack is Empty" << endl;
            return 0;
        }
        T val = head->data;
        Node<T>* delNode = head;
        head = head->next;
        delete delNode;
        sz--;
        return val;
    }

    T top(){
        if(isEmpty()){
            cout << "Stack is Empty" << endl;
            return 0;
        }
        return head->data;
    }
};
