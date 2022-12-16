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

int getMinHealth(int **a, int n, int m, int i, int j, vector<vector<int>> &dp){

    if(i > n-1 or j > m-1)
        return INT_MAX;

    if(i == n-1 and j == m-1)
        return 1;

    if(dp[i][j] != -1)
        return dp[i][j];

    int op1 = getMinHealth(a, n, m, i+1, j, dp);
    int op2 = getMinHealth(a, n, m, i, j+1, dp);
    int mh = min(op1, op2) - a[i][j];

    return dp[i][j] = (mh > 0) ? mh : 1;
}

int getMinHealthIter(int **a, int n, int m){

    vector<vector<int>> dp(n, vector<int>(m, 1));

    rep(j,1,m){
        dp[0][j] = dp[0][j-1] - a[0][j];
        if(dp[0][j] < 0)
            dp[0][j] = 1;
    }
}

int main() {

    int n, m;
    cin >> n >> m;
    int **a = new int*[n];

    forn(n)
        a[i] = new int[m];

    vector<vector<int>> dp(n, vector<int>(m, -1));

    rep(i,0,n)
        rep(j,0,m)
            cin >> a[i][j];

    dp[n-1][m-1] = 1;
    
    for(int j=m-2; j>-1; j--){
        dp[n-1][j] = dp[n-1][j+1] - a[n-1][j];
        if(dp[n-1][j] < 1)
            dp[n-1][j] = 1;
    }

    for(int i=n-2; i>-1; i--){
        dp[i][m-1] = dp[i+1][m-1] - a[i][m-1];
        if(dp[i][m-1] < 1)
            dp[i][m-1] = 1;
    }
    
    for(int i=n-2; i>-1; i--)
        for(int j=m-2; j>-1; j--) {
            dp[i][j] = min(dp[i+1][j], dp[i][j+1]) - a[i][j];
            if(dp[i][j] < 1)
                dp[i][j] = 1;
        }

    cout << dp[0][0] << endl;
    // cout << getMinHealth(a, n, m, 0, 0, dp);    
}   