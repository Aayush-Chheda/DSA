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

    string s; 
    getline(cin, s);

    int i, j;
    i = j = 0; 
    while(i < s.size()){
        int len = (i - j);
        if(s[i] == ' ' && len % 2 == 0 && len > 3){
            rep(k,j,j+len/2)
                cout << s[k];
            cout << ' ';
            rep(k,j+len/2,i)
                cout << s[k];
            j = i+1;
            cout << ' ';
        }
        else if(s[i] == ' '){
            rep(k,j,i)
                cout << s[k];
            j = i+1;
            cout << ' ';
        }
        i++;
    }

    int len = i - j;
    if(len % 2 == 0 && len > 3){
        rep(k,j,j+len/2)
                cout << s[k];
            cout << ' ';
        rep(k,j+len/2,i)
            cout << s[k];
        j = i+1;
    }
    else
        rep(k,j,i)
                cout << s[k];
    cout << endl;
}