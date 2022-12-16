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
    bool a[n];
    forn(n) cin >> a[i];

    int cntr = 0;
    int b[n+1] = {};

    forn(n){
        if(a[i])
            cntr++;
        else
            cntr--;
        b[i+1] = cntr;
    }

    unordered_map<int, pi> ump;
    forn(n+1){
        if(ump.count(b[i])){
            ump[b[i]].ss += i - ump[b[i]].ff;
            ump[b[i]].ff = i;
        }
        else
            ump[b[i]] = {i, 0};
        cout << ump[b[i]].ff << ' ' << ump[b[i]].ss << endl;
    }

    int max_len = 0;
    for(auto p: ump)
        max_len = max(max_len, p.ss.ss);
    cout << max_len << endl;
}