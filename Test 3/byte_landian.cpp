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

int byte_landian(int n, map<int, int> &dp){

    if(n < 5)
        return n;

    if(dp[n])
        return dp[n];

    int n2 = byte_landian(n/2, dp);
    int n3 = byte_landian(n/3, dp);
    int n4 = byte_landian(n/4, dp);
    int coins = max(n, n2 + n3 + n4);

    return dp[n] = coins;
}

int main() {

    int n; cin >> n;
    map<int, int> dp;
    cout << byte_landian(n, dp) << endl;
}