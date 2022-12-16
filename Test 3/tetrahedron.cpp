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

int count(int vertex, int steps, vector<vector<int>> &dp){
    if(steps == 0){
        if(vertex == 0)
            return 1;
        else 
            return 0;
    }
    
    if(dp[vertex][steps] != -1)
        return dp[vertex][steps];
    
    if(vertex == 0)
        return dp[0][steps] = 3ll * count(1, steps - 1, dp) % m7;
    else
        return dp[1][steps] = (2ll * count(1, steps - 1, dp) % m7  + count(0, steps - 1, dp)) % m7;
}

int main() {

    int n; cin >> n;

    int nval = 0;
    for(int i=2; i<n+1; i++){
       if(i % 2)
           nval = (1ll * nval * 3) % m7 - 3 + m7;
       else
           nval = (1ll * nval * 3) % m7 + 3;
       nval %= m7;
    }
    cout << nval << endl;
}