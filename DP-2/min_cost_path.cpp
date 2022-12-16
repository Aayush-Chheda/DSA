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

bool checkValidIndex(int i, int j, int n){
    if(i > -1 and j > -1 and i < n and j < n)
        return true;
    return false;
}

int min_cost_path(vector<vector<int>> &arr, int i, int j, int &n) {

    if(i == n-1 and j == n-1)
        return arr[i][j];

    int x1 = i+1, y1 = j;
    int x2 = i, y2 = j+1;
    int x3 = i+1, y3 = j+1;

    int ans = arr[i][j];
    int a1, a2, a3; 
    a1 = a2 = a3 = INT_MAX;

    if(checkValidIndex(x1, y1, n))
        a1 = min_cost_path(arr, x1, y1, n);
    if(checkValidIndex(x2, y2, n))
        a2 = min_cost_path(arr, x2, y2, n);
    if(checkValidIndex(x1, y1, n))
        a3 = min_cost_path(arr, x3, y3, n);

    return ans + min({a1, a2, a3});
}

int main() {

    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));

    rep(i,0,n)
        rep(j,0,n)
            cin >> arr[i][j];

    cout << min_cost_path(arr, 0, 0, n) << endl;

    rep(i,1,n)
        arr[0][i] += arr[0][i-1];
    rep(i,1,n)
        arr[i][0] += arr[i-1][0];

    rep(i,1,n)
        rep(j,1,n)
            arr[i][j] += min({arr[i-1][j-1], arr[i-1][j], arr[i][j-1]});

    cout << arr[n-1][n-1] << endl;
}