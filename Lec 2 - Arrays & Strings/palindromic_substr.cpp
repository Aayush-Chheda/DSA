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

    string s; cin >> s;

    int res = 0;
    forn(s.size()){
        int l, r;
        l = r = i;
        while(l > -1 && r < s.size() && s[l] == s[r]){
            res++;
            l--, r++;
        }
        l = i, r = i+1;
        while(l > -1 && r < s.size() && s[l] == s[r]){
            res++;
            l--, r++;
        }
    }
    return res;
}