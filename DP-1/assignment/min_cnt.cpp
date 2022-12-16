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

    fastIO();

    int dp[100010];
    fill(dp, dp+100010, INT_MAX);
    dp[0] = 0;

    for(int i=1; i<100010; i++)
        for(int j=1; j*j<=i; j++)
            dp[i] = min(dp[i], 1 + dp[i-j*j]);

    int n; cin >> n;
    cout << dp[n] << endl;
}