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

    int n, m; 
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    int ans = 0;
    rep(i,0,n)
        rep(j,0,m){
            cin >> matrix[i][j];
            //matrix[i][j] = 1 - matrix[i][j];
            if(i == 0 or j == 0)
                continue;
            if(matrix[i][j])
                matrix[i][j] = 1 + min({matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]});
            ans = max(ans, matrix[i][j]);
        }
        
    cout << ans << endl;
}