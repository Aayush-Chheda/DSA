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

    string s, ans = "";
    cin >> s;

    ans += s[0]; 
    int cnt = 1;
    rep(i,1,s.size()){
        if(s[i] == s[i-1])
            cnt++;
        else{
            if(cnt > 1) {
                ans += to_string(cnt);
                cnt = 1; 
            }
            ans += s[i];
        }
    }

    if(cnt > 1)
        ans += to_string(cnt);

    cout << ans << endl;
}