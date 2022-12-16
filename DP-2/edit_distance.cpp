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

int editDistance(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
    if(i == s1.size() or j == s2.size())
        return s1.size() + s2.size() - (i + j);

    if(dp[i][j] != -1)
        return dp[i][j];

    if(s1[i] == s2[j])
        return dp[i][j] = editDistance(s1, s2, i+1, j+1, dp);

    int a1, a2, a3;
    a1 = editDistance(s1, s2, i, j+1, dp);
    a2 = editDistance(s1, s2, i+1, j, dp);
    a3 = editDistance(s1, s2, i+1, j+1, dp);
    return dp[i][j] = 1 + min({a1, a2, a3});
}

int main() {

    string s1, s2; 
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    cout << editDistance(s1, s2, 0, 0, dp) << endl;
}