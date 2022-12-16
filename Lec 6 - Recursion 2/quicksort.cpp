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

int partition(int a[], int l, int r){
    int num = a[l];
    int cnt = 0;
    rep(i,l+1,r)
        if(num >= a[i])
            cnt++;
    int k = l + cnt;
    swap(a[k], a[l]);

    int i = l, j = r-1;
    while(i < k and j > k){
        if(a[i] <= a[k])
            i++;
        if(a[j] >= a[k])
            j--;
        if(a[i] > a[k] and a[j] < a[k]){
            swap(a[i], a[j]);
            i++, j--;
        }
    }
    return k;
}

void quicksort(int a[], int l, int r){
    if(l < r){
        int i = partition(a, l, r);
        quicksort(a, l, i);
        quicksort(a, i+1, r);
    }
}

int main() {

    int n; cin >> n;
    int a[n]; 
    forn(n) cin >> a[i];

    quicksort(a, 0, n);

    forn(n) 
        cout << a[i] << ' ';
}