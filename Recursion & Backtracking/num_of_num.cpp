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

int cntNum(string &num, int i, int big[], int fact[]){
    if(i == 0)
        return 0;
    int cnt = big[num[i]-'0'] * fact[i];
    return cnt + cntNum(num, i-1, big, fact);
}

int main() {

    string num; cin >> num;
    int n = num.size();

    int big[10] = {};

    rep(i,0,n-1)
        rep(j,i+1,n)
            if(num[j] > num[i])
                big[num[i]-'0']++;

    int fact[n];
    fact[0] = fact[1] = 1;
    for(int i=2; i<n; i++)
        fact[i] = i * fact[i-1];

    cout << cntNum(num, n-1, big, fact) << endl;
}