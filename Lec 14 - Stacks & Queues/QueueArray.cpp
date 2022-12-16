#include <iostream>

using namespace std;

template<typename T>
class QueueArray{
    T* data;
    int capacity = 5;
    int l, r, sz;

    public:
    QueueArray(){
        data = new T[capacity];
        l = r = sz = 0;
    }

    bool empty(){
        return sz == 0;
    }

    int size(){
        return sz;
    }

    void enqueue(T val){
        if(sz == capacity){
            T* newData = new T[2*capacity];
            for(int i=0, j=l; i<sz; i++, j=(j+1)%capacity)
                newData[i] = data[j];
            l = 0, r = sz;
            capacity *= 2;
            delete [] data;
            data = newData;
        }
        data[r] = val;
        r = (r + 1) % capacity;
        sz++;
    }

    T front(){
        if(empty()){
            cout << "Queue is Empty" << endl;
            return 0;
        }
        return data[l];
    }

    T dequeue(){
        if(empty()){
            cout << "Queue is Empty" << endl;
            return 0;
        }
        T val = data[l];
        l = (l + 1) % capacity;
        sz--;
        return val;
    }

    void print(){
        for(int i=0, j=l; i<sz; i++, j=(j+1)%capacity)
            cout << data[j] << ' ';
        cout << endl;
    }
};