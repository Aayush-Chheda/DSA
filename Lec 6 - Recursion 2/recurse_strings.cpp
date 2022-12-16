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

void rmchar(char string[], char c, int i, int j){
    if(string[i] == '\0'){
        string[j] = string[i];
        return;
    }
    
    if(string[i] != c) {
        string[j] = string[i];
        j++;
    }
    i++;
    rmchar(string, c, i, j);
}

int main() {

    char c[] = "axcdxbgxhj";
    rmchar(c, 'x', 0, 0);
    cout << c << endl;
}