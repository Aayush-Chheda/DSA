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

    int t;
    cin >> t;

    while(t--){

        int n, m; 
        cin >> n >> m;
        int a[n][m];
        rep(i,0,n)
            rep(j,0,m)
                cin >> a[i][j];

        int ns, ne, ms, me;
        ns = ms = 0, ne = n, me = m;
        int x, y; x = y = 0;

        int cnt = 0; 
        while(ns < ne && ms < me){
            while(y < me) {
                cout << a[x][y] << ' ';
                y++;
            }
            y--;
            x++;
            while(x < ne){
                cout << a[x][y] << ' ';
                x++;
            }
            x--;
            y--;
            ne--, me--;
            while(y > ms-1 && ns < ne){
                cout << a[x][y] << ' ';
                y--;
            }
            y++;
            x--;
            while(x > ns && ms < me){
                cout << a[x][y] << ' ';
                x--;
            }
            ns++, ms++;
            x = ns, y = ms;
        }

        cout << endl;
    }
}