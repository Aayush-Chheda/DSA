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
    int m1 = 100001;
    int a[n]; 
    forn(n) cin >> a[i];

    int ans = n + 1; 
    unordered_map<int, int> *ump = new unordered_map<int,int>[n];

    rep(i,0,n-1){
        rep(j,i+1,n){
            int diff = a[i] - a[j];
            ump[i][diff]++;
            ans++;
        }
    }

    ans %= m1;
    for(int i=n-3; i>-1; i--){
        for(int j=i+1; j<n; j++){
            int diff = a[i] - a[j];
            ump[i][diff] += ump[j][diff];
            ump[i][diff] %= m1;
            ans = (ans + ump[j][diff]) % m1;
        }
    }
    delete [] ump;
    cout << ans << endl;
}