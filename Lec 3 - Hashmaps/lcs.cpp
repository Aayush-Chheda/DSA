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


int main() {

    int n; cin >> n;

/*
    unordered_set<int> us;
    unordered_map<int, int> ump;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        us.insert(x);
        ump[x] = i;
    }

    vector<pi> ans;
    int mxlen = 1;
    for(auto it = us.begin(); it != us.end();){
        int x = *it, i = x+1, len = 1, st;
        while(us.count(i)){
            us.erase(i);
            i++, len++;
        }
        i = x-1;
        while(us.count(i)){
            us.erase(i);
            i--, len++;
        }
        st = i+1;
        if(len > mxlen){
            mxlen = len;
            ans.pb({st, len});
        }
        it = us.erase(it);
    }

    int k = ans.size()-1, st = INT_MAX, sti = n;
    while(ans[k].ss == mxlen){
        if(ump[ans[k].ff] < sti){
            sti = ump[ans[k].ff];
            st = ans[k].ff;
        }
        k--;
    }

    cout << st << ' ' << st + mxlen - 1 << endl;
*/

// Original Solution 
    unordered_map<int, bool> ump;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        ump[x] = false;
    }

    int mxlen = 0;
    for(auto it = ump.begin(); it != ump.end(); it++){
        if(ump[it->ff])
            continue;
        int x = it->ff, len = 1;
        ump[x] = true; x++;
        while(ump.count(x)){
            ump[x] = true;
            len++, x++;
        }
        x = it->ff - 1;
        while(ump.count(x)){
            ump[x] = true;
            len++, x--;
        }
        mxlen = max(len, mxlen);
    }

    cout << mxlen << endl;
}