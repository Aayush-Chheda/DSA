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
    
    int n;
    cin >> n;

    int a[n][n];

    rep(i,0,n)
        rep(j,0,n)
            cin >> a[i][j];

    rep(i,0,n)
        rep(j,i+1,n)
            swap(a[i][j], a[j][i]);

    rep(j,0,n)
        rep(i,0,n/2)
            swap(a[i][j], a[n-i-1][j]);

    rep(i,0,n){
        rep(j,0,n)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}