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

int short_superseq(string &s, string &t, int i = 0, int j = 0){
    if(i == s.size() or j == t.size())
        return s.size() + t.size() - (i + j);

    if(s[i] == t[j])
        return 1 + short_superseq(s, t, i+1, j+1);

    int ss1 = 1 + short_superseq(s, t, i+1, j);
    int ss2 = 1 + short_superseq(s, t, i, j+1);
    int ss3 = 2 + short_superseq(s, t, i+1, j+1);

    return min({ss1, ss2, ss3});
}

int main() {

    string s, t;
    cin >> s >> t;
    cout << short_superseq(s, t) << endl;
}