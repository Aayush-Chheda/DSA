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

void printAllSubsets(int a[], int i, int n, vector<int> &v){
    if(i == n)
        return;
    v.pb(a[i]);
    forn(v.size())
        cout << v[i] << ' ';
    cout << endl;
    printAllSubsets(a, i+1, n, v);
    v.pop_back();
    printAllSubsets(a, i+1, n, v);
}

int main() {

    int n; cin >> n;
    int a[n];
    forn(n) cin >> a[i];

    vector<int> v;
    printAllSubsets(a, 0, n, v);
}