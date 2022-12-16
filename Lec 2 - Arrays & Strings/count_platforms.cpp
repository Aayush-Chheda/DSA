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
    vector<pi> v(n);

    forn(n)
        cin >> v[i].ff;
    forn(n)
        cin >> v[i].ss;

    sort(v.begin(), v.end());

    // best method
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(v[0].ss);
    int ans = 1;
    rep(i,1,n){
        if(v[i].ff > pq.top())
            pq.pop();
        pq.push(v[i].ss);
        ans = max(ans, (int)pq.size());
    }

    cout << ans << endl;

    // One More method - combining both arrays and sorting, after that 1 single scan.
}