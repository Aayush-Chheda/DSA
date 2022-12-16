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

int knapsack(vector<int> &w, vector<int> &v, int n, int i, int l, vector<vector<int>> &dp){
    if(i == n)
        return 0;
    
    if(dp[i][l] != -1)
        return dp[i][l];

    int a1 = 0;
    if(l - w[i] > -1)
        a1 = knapsack(w, v, n, i+1, l-w[i], dp) + v[i];
    int a2 = knapsack(w, v, n, i+1, l, dp);
    return dp[i][l] = max(a1, a2);
}

int main() {

    int n;
    cin >> n;

    vector<int> w(n), v(n);
    forn(n)
        cin >> w[i];
    forn(n)
        cin >> v[i];
    int l; cin >> l;

    vector<vector<int>> dp(21, vector<int>(101, -1));
    knapsack(w, v, n, 0, l, dp);
    cout << dp[0][l] << endl;
}