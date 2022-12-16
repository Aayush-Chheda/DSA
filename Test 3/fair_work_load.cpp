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

int fair_work_load(int a[], int n, int x, vector<vector<int>> &dp){

    if(x == 0)
        return a[n];

    if(dp[n][x] != -1)
        return dp[n][x];

    int max_work = INT_MAX;
    for(int i=x; i<n+1; i++){
        int fwl_e = a[n] - a[i-1];
        int fwl_s = fair_work_load(a, i-1, x-1, dp);
        max_work = min(max_work, max(fwl_s, fwl_e));
    }

    return dp[n][x] = max_work;
}

int main() {

    int n; cin >> n;
    int a[n] = {}; 
    forn(n) 
        cin >> a[i];
    int x; cin >> x;

    rep(i,1,n)
        a[i] += a[i-1];

    vector<vector<int>> dp(n, vector<int>(x, -1));
    cout << fair_work_load(a, n-1, x-1, dp) << endl;
}