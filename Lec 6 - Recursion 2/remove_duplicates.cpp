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

void rmdp(char string[]){
    if(string[0] == '\0')
        return;

    if(string[0] != string[1])
        rmdp(string+1);
    else{
        int i = 1;
        for(; string[i] != '\0'; i++)
            string[i-1] = string[i];
        string[i-1] = string[i];
        rmdp(string);
    }
}

int main() {

    char string[1000];
    cin >> string;
    rmdp(string);
    cout << string;
}