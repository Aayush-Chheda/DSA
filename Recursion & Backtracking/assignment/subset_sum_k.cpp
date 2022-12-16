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

// Non - reference approach
void printSSK(int a[], int i, int n, int left, vector<int> &v){
    if(i == n)
        return;

    v.pb(a[i]);
    if(left - a[i] == 0){
        forn(v.size())
            cout << v[i] << ' ';
        cout << endl;
        return;
    }
    printSSK(a, i+1, n, left-a[i], v);
    v.pop_back();
    printSSK(a, i+1, n, left, v);
}

// Reference approach
/*
void printSSK(vector<int> &a, int i, int n, int k, vector<int> &v, vector<vector<int>> &subsets, int &sum){
    if(i == n)
        return;

    v.push_back(a[i]);
    sum += a[i];
    if(sum == k)
        subsets.push_back(v);
    printSSK(a, i+1, n, k, v, subsets, sum);
    v.pop_back();
    sum -= a[i];
    printSSK(a, i+1, n, k, v, subsets, sum);
}
*/

int main() {

    int n; cin >> n;
    int a[n]; forn(n) cin >> a[i];
    int total; cin >> total;

    vector<int> v;
    cout << endl;
    printSSK(a, 0, n, total, v);
}