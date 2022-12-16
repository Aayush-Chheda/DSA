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

    string s;
    getline(cin, s);

    int i=0;
    vector<string> vs;
    string s_ = "";
    while(i < s.size()){
        if(s[i] == ' ') {
            vs.pb(s_);
            s_ = "";
        }
        else 
            s_ += s[i];
        i++;
    }
    vs.pb(s_);

    string ans = "";
    for(string &i: vs) {
        reverse(i.begin(), i.end());
        ans += i + " ";
    }
    ans.pop_back();
    cout << ans << endl;
}