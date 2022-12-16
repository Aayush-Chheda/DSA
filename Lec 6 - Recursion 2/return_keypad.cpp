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

void rkey(vector<string> &keypad, int n, vector<string> &ans, string &sk, int &l){
    if(n == 0)
        return;
    int num = n % 10;
    n /= 10;
    string s = keypad[num];
    forn(s.size()){
        sk.push_back(s[i]);
        rkey(keypad, n, ans, sk, l);
        //ans.push_back(sk);
        if(sk.size() == l)
            cout << sk << endl;
        sk.pop_back();
    }
}

void rkey2(int n, vector<string> &ans, vector<string> &keypad){
    if(n == 0){
        ans.pb("");
        return;
    }
    int num = n % 10;
    n /= 10;
    string s = keypad[num];
    rkey2(n, ans, keypad);
    int cpy = s.size() - 1;
    int k = ans.size();
    forn(cpy)
        rep(j,0,k)
            ans.push_back(ans[j]);
    int x = 0;
    forn(s.size())
        rep(j,0,k){
            ans[x].pb(s[i]);
            x++;
        }
}

int main() {

    vector<string> keypad{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;

    int n; cin >> n;

    // string sk;  int l = 2;
    // rkey(keypad, n, ans, sk, l);
    rkey2(n, ans, keypad);
    forn(ans.size())
        cout << ans[i] << endl;
}