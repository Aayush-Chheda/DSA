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

    int h; cin >> h;
    int n1 = 1, n2 = 1;
    int nh = 0;
    for(int i=2; i<h+1; i++){
        nh = (n1*n1 + 2*n1*n2) % m7;
        n2 = n1;
        n1 = nh;
    }
    cout << nh << endl;
}