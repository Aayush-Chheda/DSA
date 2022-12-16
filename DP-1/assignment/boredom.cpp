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
    
    // Straight forward Iterative DP
    int freq[1005] = {};
    int maxval = 0;
    while(n--){
        int x; cin >> x;
        freq[x]++;
        maxval = max(maxval, x);
    }

    int a = 0;
    int b, c;
    c = b = freq[1];
    for(int i=2; i<maxval+1; i++){
        c = max(b, a + i * freq[i]);
        a = b;
        b = c;
    }
    cout << c << endl;
}