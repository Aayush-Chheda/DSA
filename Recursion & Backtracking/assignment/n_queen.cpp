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

bool checkSquare(vector<vector<bool>> &v, int r, int c) {
    int n = v.size();
    forn(r)
        if(v[i][c])
            return false;
    for(int i=r-1, j=c-1; i>-1 and j>-1; i--, j--)
        if(v[i][j])
            return false;
    for(int i=r-1, j=c+1; i>-1 and j<n; i--, j++)
        if(v[i][j])
            return false;
    return true;
}

void NQueen(vector<vector<bool>> &v, int i, int&n) {

    if(i == n){
        rep(x,0,n)
            rep(y,0,n)
                cout << v[x][y] << ' ';
        cout << endl;
        return;
    }

    rep(j,0,n){
        if(checkSquare(v, i, j)){
            v[i][j] = true;
            NQueen(v, i+1, n);
            v[i][j] = false;
        }
    }
}

int main() {

    int n; cin >> n;
    vector<vector<bool>> v(n, vector<bool>(n, false));
    NQueen(v, 0, n);
}