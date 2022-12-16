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

        int n; cin >> n;
        int a[n];
        forn(n)
            cin >> a[i];

        int p, q, r;
        p = q = 0, r = n-1;

        int i = 0;
        while(q <= r){
            if(a[q] == 0){
                swap(a[q], a[p]);
                p++, q++;
            }
            else if(a[q] == 1)
                q++;
            else {
                swap(a[q], a[r]);
                r--;
            }
        }

        for(int i: a)
            cout << i << ' ';
        cout << endl;
    }
}