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

int min_steps_1(int n){

    if(n == 1)
        return 0;
    int min1 = min_steps_1(n-1);
    int by2, by3; 
    by2 = by3 = n + 1;
    if(n % 2 == 0)
        by2 = min_steps_1(n / 2);
    if(n % 3 == 0)
        by3 = min_steps_1(n / 3);
    return 1 + min({min1, by2, by3});
}

int main() {

    int n; cin >> n;
    cout << min_steps_1(4) << endl;
}