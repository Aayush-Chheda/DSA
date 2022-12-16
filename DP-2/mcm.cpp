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

int MCM(int a[], int s, int e, vector<vector<int>> &dp){

    if(e - s < 2)
        return 0;

    if(dp[s][e] != -1)
        return dp[s][e];
    
    int ans = INT_MAX;
    rep(i,s+1,e)
        ans = min(ans, MCM(a, s, i, dp) + MCM(a, i, e, dp) + a[s] * a[i] * a[e]);
    return dp[s][e] = ans;
}

int main() {

    int n; cin >> n;
    int a[n];
    forn(n) cin >> a[i];

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << MCM(a, 0, n-1, dp) << endl;
}