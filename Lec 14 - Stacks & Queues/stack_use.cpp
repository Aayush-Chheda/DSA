#include <bits/stdc++.h>
#include "StackArray.cpp"
#include "StackLinkedList.cpp"

using namespace std;

int main(){

    StackLinkedList<int> s; 
    s.push(5); s.push(4);
    s.push(3); s.push(2); 
    s.push(1); s.push(0);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop(); s.pop(); s.pop();
    cout << s.top() << endl;
    s.pop(); s.pop(); s.pop();
}
