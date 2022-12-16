#include <iostream>
#include "Node.cpp"

using namespace std;

template<typename T>
class QueueLinkedList{
    Node<T> *start, *rear;
    int sz = 0;

    public:
    QueueLinkedList(){
        start = rear = 0;
    }

    bool empty(){
        return sz == 0;
    }

    int size(){
        return sz;
    }

    void enqueue(T val){
        if(start == 0 and rear == 0)
            start = rear = new Node<T>(val);
        else{
            rear->next = new Node<T>(val);
            rear = rear->next;
        }
        sz++;
    }

    T dequeue(){
        if(empty()){
            cout << "Queue is Empty" << endl;
            return 0;
        }
        T val = start->data;
        Node<T>* delNode = start;
        start = start->next;
        delete delNode;
        sz--;
        return val;
    }

    T front(){
        if(empty()){
            cout << "Queue is Empty" << endl;
            return 0;
        }
        return start->data;
    }

    void print(){
        Node<T>* temp = start;
        while(temp){
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;
    }
};