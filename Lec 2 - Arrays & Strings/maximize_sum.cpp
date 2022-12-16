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

    int m, n;
    cin >> m;

    int a[m];
    forn(m)
        cin >> a[i];

    cin >> n;

    int b[n];
    forn(n)
        cin >> b[i];

    // int pref_a[m], pref_b[n];
    // pref_a[0] = a[0], pref_b[0] = b[0];

    // rep(i,1,m) 
    //     pref_a[i] = a[i] + pref_a[i-1];
    // rep(i,1,n)
    //     pref_b[i] = b[i] + pref_b[i-1];

    // vi av, bv, avs, bvs;
    // rep(i,0,m) {
    //     int k = a[i];
    //     if(binary_search(b, b+n, k)) {
    //         int j = lower_bound(b, b+n, k) - b;
    //         av.pb(i);
    //         bv.pb(j);
    //     }
    // }

    // av.pb(m-1); bv.pb(n-1);
    // avs.pb(pref_a[av[0]]), bvs.pb(pref_b[bv[0]]);
    // rep(i,1,av.size())
    //     avs.pb(pref_a[av[i]] - pref_a[av[i-1]]);
    // rep(i,1,bv.size())
    //     bvs.pb(pref_b[bv[i]] - pref_b[bv[i-1]]);

    // int total = 0;
    // rep(i,0,avs.size())
    //     total += max(avs[i], bvs[i]);
    // cout << total << endl;

    int sa, sb, mxsum, i, j;
    sa = sb = mxsum = i = j = 0;

    while(i < m && j < n){
        if(a[i] < b[j])
            sa += a[i++];
        else if(a[i] > b[j])
            sb += b[j++];
        else{
            mxsum += max(sa, sb) + a[i];
            sa = sb = 0;
            i++, j++;
        }
    }

    while(i < m)
        sa += a[i++];
        
    while(j < n)
        sb += b[j++];

    mxsum += max(sa, sb);
    cout << mxsum << endl;
}