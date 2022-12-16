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
    int a[n];
    forn(n) cin >> a[i];

    unordered_map<int, int> ump;
    int min_dist = INT_MAX;
    forn(n) {
        if(ump.count(a[i]))
            min_dist = min(min_dist, i - ump[a[i]]);
        ump[a[i]] = i;
    }
    
    cout << min_dist << endl;
}