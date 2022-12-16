#include <bits/stdc++.h>
#include "QueueArray.cpp"
#include "QueueLinkedList.cpp"

using namespace std;

int main() {

    QueueLinkedList<int> q;
    q.dequeue();
    q.enqueue(3); q.enqueue(7); q.enqueue(4); 
    q.enqueue(9); q.enqueue(11); q.enqueue(50);
    q.print();
    cout << q.front() << endl;
    q.dequeue(); q.dequeue();
    q.print();
    q.enqueue(90);
    cout << q.size() << endl;
    q.print();
}