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

    string s; cin >> s;
    int i, j; i = j = 0;
    int a[26]; 
    memset(a, -1, 26*sizeof(int));

    cout << endl;
    int x, len = 0;
    while(i < s.size()){
        if(a[s[i] - 'a'] != -1) 
            j = a[s[i] - 'a'] + 1;
        a[s[i] - 'a'] = i;
        i++;
        if(i - j > len){
            len = i - j;
            x = j;
        }
    }
    rep(k, x, x+len)
        cout << s[k];
    cout << endl;
}