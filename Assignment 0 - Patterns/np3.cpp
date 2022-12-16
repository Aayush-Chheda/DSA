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
    for(int i=n; i>-n-1; i--){
        if(i == 0 || i==-1) continue;
        for(int j=-n; j<n+1; j++){
            if(j == 0 || j==-1) continue;
            cout << max(abs(i), abs(j));
        }
        cout << endl;
    }
}