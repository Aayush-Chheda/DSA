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

void recover_array(int a[], int n) {

    int b[n], x = 0, y = n-1;
    rep(i,0,n){
        if(i % 2 == 0){
            b[y] = a[n-i-1]; 
            y--;
        }
        else{
            b[x] = a[n-i-1];
            x++;
        }
    }
    rep(i,0,n)
        a[i] = b[i];
}

int main() {

    int n; cin >> n;
    int a[n];

    rep(i,0,n)
        cin >> a[i];

    recover_array(a, n);
    for(int i: a)
        cout << i << ' ';
    cout << endl;
}