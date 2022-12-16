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

void merge(int a[], int l, int mid, int r, int &n){
    int b[n];
    int i = l, j = mid+1, k = l;
    while(i < mid+1 and j < r+1){
        if(a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while(i < mid+1)
        b[k++] = a[i++];

    while(j < r+1)
        b[k++] = a[j++];

    for(int k=l; k<r+1; k++)
        a[k] = b[k];
}

void mergeSort(int a[], int l, int r, int &n){
    if(l < r){
        int mid = l + (r - l) / 2;
        mergeSort(a, l, mid, n);
        mergeSort(a, mid+1, r, n);
        merge(a, l, mid, r, n);
    }
}

int main() {

    int n; cin >> n;
    int a[n];
    forn(n) cin >> a[i];

    mergeSort(a, 0, n-1, n);

    forn(n)
        cout << a[i] << ' ';
}