#include<bits/stdc++.h>
#include "HashTable.h"

using namespace std;

int main(){

    hashTable<int> ht;
    ht.insert("abc", -5);
    ht.insert("def", 3);
    cout << ht.getLoadFactor() << endl;
    ht.insert("efg", 2);
    cout << ht.getLoadFactor() << endl;
    ht.insert("pqr", 11);
    cout << ht.getLoadFactor() << endl;

    cout << endl;
    cout << ht.size() << endl;
    cout << ht.getVal("pqr") << endl;
    cout << ht.deleteKey("efg") << endl;
    cout << ht.size() << endl;
}