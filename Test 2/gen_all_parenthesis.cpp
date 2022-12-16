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

void genAllParen(string &s, int &n, int &cnt){
    if(s.size() == 2*n){
        if(cnt == 0){
            int bal = 0;
            forn(2*n){
                if(s[i] == '(')
                    bal++;
                else bal--;
                if(bal < 0)
                    return;
            }
            cout << s << endl;
        }
        return;
    }

    s.push_back('(');
    cnt++;
    genAllParen(s, n, cnt);
    s.pop_back();
    cnt--;
    s.push_back(')');
    cnt--;
    genAllParen(s, n, cnt);
    s.pop_back();
    cnt++;
}

int main() {

    int n; cin >> n;
    string s; 
    int cnt = 0;
    genAllParen(s, n, cnt);
}