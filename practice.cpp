#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define m7 1000000007
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a; i<b; i++)
#define forn(n) for(int i=0; i<n; i++)

void fastIO(){ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }

bool pof2(int n){ if(n & n-1) return false; return true; }

void insertionSort(int a[], int n){
    rep(i,1,n){
        int j = i-1, key = a[i];
        while(j > -1 and key < a[j]) {
            a[j+1] = a[j];
            j--;
        }
        a[++j] = key;
    }
}

void selectionSort(int a[], int n){
    rep(i,0,n){
        int mn = min_element(a+i,a+n) - a;
        swap(a[i], a[mn]);
    }
}

void merge(int a[], int l, int r, int mid, int n){
    int b[n];
    int i=l, j=mid+1, k=l;

    while(i < mid+1 && j < r+1){
        if(a[i] > a[j])
            b[k++] = a[j++];
        else
            b[k++] = a[i++];
    }

    while(i < mid+1)
        b[k++] = a[i++];

    while(j < r+1)
        b[k++] = a[j++];

    rep(z,l,r+1) 
        a[z] = b[z];
}

void mergeSort(int a[], int l, int r, int n){
    if(l >= r)
        return;
    int mid = l + (r - l) / 2;
    mergeSort(a, l, mid, n);
    mergeSort(a, mid+1, r, n);
    merge(a, l, r, mid, n);
}

// Optimized Version
void bubbleSort(int a[], int n){
    rep(i,0,n-1) {
        bool swapped = false;
        rep(j,0,n-i-1)
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                swapped = true;
            }
        if(!swapped)
            break;
    }
}

int main() {

/*
    char c[6] = "hello";
    cin >> c; // Only Possible in case of Char arrays
    cin.getline(c, 6); // cin does not read spaces, tabs or newline
    cin.getline(c, 6, 'o'); // use delimiter instead of default delimiter '\n'
*/

/*
    int p = 1;
    forn(10){
        p *= 37;
        p %= 5;
    }
    cout << p << endl;

    p = 1;
    forn(10)
        p *= (37 % 5);
    cout << p % 5 << endl;
*/
    
/*
    HashTable<int> ht;
    ht.insert("abc", -5);
    ht.insert("def", 3);
    cout << ht.getLoadFactor() << endl;
    ht.insert("efg", 2);
    cout << ht.getLoadFactor() << endl;
    ht.insert("pqr", 11);
    cout << ht.getLoadFactor() << endl;

    cout << endl;
    cout << ht.size() << endl;
    cout << ht.search("pqr") << endl;
    cout << ht.remove("efg") << endl;
    cout << ht.size() << endl;
*/

/*
    char c[] = "abc";
    cout << sizeof(c) << endl;
*/

// Dynamic Memory Allocation
    // int n; cin >> n;
    // int* a = new int[n];
    
    // delete [] a; // array deletion

    // // 2D Array allocation
    // int** b = new int*[n];
    // for(int i=0; i<n; i++)
    //     b[i] = new int[n];

    // for(int i=0; i<n; i++)
    //     delete [] b[i];

    // delete [] b;

    int a = rand() % 3;
    int b = rand() % 3;
    cout << (a + b) % 3 << endl;
}

// inline functions  
inline int maxof2(int a, int b) {
    return a > b ? a : b;
}