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

int main() {

    int n; cin >> n;
    
    int a[n*n], j=0, st;
    bool b = false;
    rep(i,0,n*n){
        if(i % n == 0){
            b = !b;
            st = b ? n*j : n*(n-j);
            if(b) j++;
        }
        a[st++] = i+1;
    }

    int k=0;
    rep(i,0,n){
        rep(j,0,n){
           cout << a[k] << ' ';
           k++; 
        }
        cout << endl;
    }
}