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

int waysCoinChange(int a[], int n, int i, int V, vector<vector<int>> &dp){
    if(i == n or V < 0)
        return 0;

    if(V == 0)
        return 1;

    if(dp[i][V] != -1)
        return dp[i][V];
    int a1 = waysCoinChange(a, n, i+1, V, dp);
    int a2 = waysCoinChange(a, n, i, V-a[i], dp);
    return dp[i][V] = a1 + a2;
}

int main() {

    int n; cin >> n;
    int a[n]; forn(n) cin >> a[i];
    int v; cin >> v;

    vector<vector<int>> dp(n, vector<int>(v+1, -1));
    cout << waysCoinChange(a, n, 0, v, dp) << endl;
}