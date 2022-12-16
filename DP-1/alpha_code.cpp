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

int num_decodings(string s, int n, int dp[]){
    if(n < 1)
        return 1;
    if(dp[n])
        return dp[n];
    string num; num.pb(s[n-1]); num.pb(s[n]);
    if(num[1] == '0')
        return dp[n] = num_decodings(s, n-2, dp);
    int ans = num_decodings(s, n-1, dp);
    if(num[0] != '0' && num < string("27"))
        ans += num_decodings(s, n-2, dp);
    return dp[n] = ans % m7;
}

int main() {

    string s; cin >> s;
    // while(s != "0"){
    //     int n = s.size();
    //     int dp[n+1] = {};
    //     cout << num_decodings(s, n-1, dp) << endl;
    //     cin >> s;
    // }


    // Iterative Approach
    while(s != "0"){
        int n = s.size();
        int dp[n+1] = {};
        dp[0] = dp[1] = 1;
        rep(i,2,n+1){
            string num; 
            num.pb(s[i-2]); num.pb(s[i-1]);
            if(num[1] == '0')
                dp[i] = dp[i-2];
            else{
                dp[i] = dp[i-1];
                if(num[0] != '0' and num < string("27"))
                    dp[i] += dp[i-2];
            }
            dp[i] %= m7;
        }
        cout << dp[n] << endl;
        cin >> s;
    }
}