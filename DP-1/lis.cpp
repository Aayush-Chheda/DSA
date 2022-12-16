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

    int dp[n];
    fill(dp, dp+n, 1);

    for(int i=1; i<n; i++)
        for(int j=0; j<i; j++){
            if(a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }

    int maxlen = *max_element(dp, dp+n);
    cout << maxlen << endl; 
}