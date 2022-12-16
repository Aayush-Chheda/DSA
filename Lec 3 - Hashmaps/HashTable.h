#include<string>

using namespace std;

template <typename V>
class hashTableNode{
public:
    string key;
    V val;
    hashTableNode* next;

    hashTableNode(string key, V val){
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~hashTableNode(){
        delete next;
    }
};

template <typename V>
class hashTable{
    hashTableNode<V>** buckets;
    int sz, bucketsz;

public:
    hashTable(){
        sz = 0;
        bucketsz = 5;
        buckets = new hashTableNode<V>*[bucketsz];
        for(int i=0; i<bucketsz; i++)
            buckets[i] = NULL;
    }

    ~hashTable(){
        for(int i=0; i<bucketsz; i++)
            delete buckets[i];
        delete [] buckets;
    }

    int size(){
        return sz;
    }

    void insert(string key, V val){
        int index = getBucketIndex(key);
        hashTableNode<V>* head = buckets[index];
        while(head != NULL){
            if(head->key == key){
                head->key = val;
                return;
            }
            head = head->next;
        }
        hashTableNode<V>* newNode = new hashTableNode<V>(key, val);
        head = buckets[index];
        buckets[index] = newNode;
        newNode->next = head;
        sz++;
        double loadFactor = (double) sz / bucketsz;
        if(loadFactor > 0.7)
            rehash();
    }

    double getLoadFactor(){
        return (double) sz / bucketsz;
    }
 
    V getVal(string key){
        int index = getBucketIndex(key);
        hashTableNode<V>* head = buckets[index];
        while(head != NULL){
            if(head->key == key)
                return head->val;
            head = head->next;
        }
        return 0;
    }

    V deleteKey(string key){
        int index = getBucketIndex(key);
        hashTableNode<V> *head = buckets[index], *prev = NULL;
        
        while(head != NULL){
            if(head->key == key){
                if(prev == NULL)
                    buckets[index] = head->next;
                else
                    prev->next = head->next;
                head->next = NULL;
                V value = head->val;
                delete head;
                sz--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }   

private:
    int getBucketIndex(string key){
        int hashCode = 0, p = 1, n = key.size();
        for(int i=n-1; i>-1; i--){
            hashCode += (key[i] * p);
            hashCode %= bucketsz;
            p *= 37; p %= bucketsz;
        }
        return hashCode;
    }

    void rehash(){
        int tempsz = bucketsz;
        bucketsz *= 2;
        hashTableNode<V>** temp = buckets;
        buckets = new hashTableNode<V>*[bucketsz];

        for(int i=0; i<bucketsz; i++)
            buckets[i] = NULL;

        sz = 0;
        for(int i=0; i<tempsz; i++){
            hashTableNode<V>* head = temp[i];
            while(head != NULL){
                insert(head->key, head->val);
                head = head->next;
            }
            delete head;
        }
        delete [] temp;
    }
};