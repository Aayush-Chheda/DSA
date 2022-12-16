#include <iostream>

using namespace std;

template<typename T>
class StackArray{
    T *data;
    int nextIndex = 0;
    int capacity = 5;

    public:
    StackArray(){
        data = new T[capacity];
    }

    int size(){
        return nextIndex;
    }

    bool isEmpty(){
        return nextIndex == 0;
    }

    void push(T val){
        if(nextIndex == capacity){
            T *newData = new T[2 * capacity];
            for(int i=0; i<capacity; i++)
                newData[i] = data[i];
            capacity *= 2;
            delete [] data;
            data = newData;
        }
        data[nextIndex++] = val; 
    }

    T pop(){
        if(nextIndex == 0){
            cout << "Stack is Empty" << endl;
            return 0;
        } 
        return data[--nextIndex];
    }

    T top(){
        if(nextIndex == 0){
            cout << "Stack is Empty" << endl;
            return 0;
        }
        return data[nextIndex-1];
    }
};