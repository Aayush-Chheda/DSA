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

int short_subseq(string &s, string &v, int i = 0, int j = 0, vector<vector<int>> &dp){
    if(j == v.size())
        return 1;
    
    if(i == s.size())
        return 1001;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ss1 = short_subseq(s, v, i+1, j);
    int k;
    for(k = j; k < v.size(); k++)
        if(s[i] == v[k])
            break;
    if(k == v.size())
        return 1;
    int ss2 = 1 + short_subseq(s, v, i+1, k+1);
    return dp[i][j] = min(ss1, ss2);
}

int main() {

    string s, v;
    cin >> s >> v;

    string t;
    int n = s.size();
    vector<int> dp(n, v.size());
    cout << short_subseq(s, v) << endl;
}