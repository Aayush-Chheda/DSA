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

int lcs(string &s1, string &s2, int i, int j){
    if(i == s1.size() or j == s2.size())
        return 0;
    int a1, a2;
    a1 = a2 = 0;
    if(s1[i] == s2[j])
        return 1 + lcs(s1, s2, i+1, j+1);
    a1 = lcs(s1, s2, i+1, j);
    a2 = lcs(s1, s2, i, j+1);
    return max(a1, a2);
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2, 0, 0) << endl;

    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    rep(i,1,n1+1)
        rep(j,1,n2+1){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }

    cout << dp[n1][n2] << endl;
}