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

int kadanes(int a[], int n){
    int sum = 0;
    int mxsum = INT_MIN;
    rep(i,0,n){
        sum += a[i];
        mxsum = max(sum, mxsum);
        if(sum < 0)
            sum = 0;
    }
    return mxsum;
}

int main() {

    int n, m;
    cin >> n >> m;

    int a[n][m], pref[n+1][m+1];

    rep(i,0,n)
        rep(j,0,m){
            cin >> a[i][j];
            if(i == 0 or j == 0)
                pref[i][j] = 0;
            pref[i+1][j+1] = a[i][j];
        }

    // Brute Force
    int mxsum = INT_MIN;
    rep(p,0,n)
        rep(q,0,m){
            int i = p, j = q;
            rep(x,i,n)
                rep(y,j,m){
                    int sum = 0;
                    rep(r,i,x+1)
                        rep(s,j,y+1)
                            sum += a[r][s];
                    mxsum = max(sum, mxsum);
                }
        }

    cout << mxsum << endl;

    // pref-sum optimization
    rep(j,2,m+1)
        pref[1][j] += pref[1][j-1];
    rep(i,2,n+1)
        pref[i][1] += pref[i-1][1];

    rep(i,2,n+1)
        rep(j,2,m+1)
            pref[i][j] += (pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1]);

    mxsum = INT_MIN;
    rep(p,0,n)
        rep(q,0,m){
            int i = p, j = q;
            rep(x,i,n)
                rep(y,j,m){
                    int sum = pref[x+1][y+1] + pref[i][j] - pref[x+1][j] - pref[i][y+1]; 
                    mxsum = max(sum, mxsum);
                }
        }
    cout << mxsum << endl;

    // kadane algo optimization
    mxsum = INT_MIN;
    rep(i,0,m){
        int temp[n] = {};
        rep(j,i,m){
            rep(k,0,n)
                temp[k] += a[k][j];
            int sum = kadanes(temp, n);
            mxsum = max(sum, mxsum);
        }
    }
    cout << mxsum << endl;
}