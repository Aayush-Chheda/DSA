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

int cntNum(string &num, int n, int freq[], int fact[], int i = 0){
    if(i == n-1)
        return 0;
    int ni = num[i] - '0';

    int base = 1;
    for(int j=0; j<10; j++)
        if(freq[j] > 0)
            base *= fact[freq[j]];

    int ans = 0;
    for(int j=ni+1; j<10; j++)
        ans += fact[n-i-1] * freq[j];
    ans /= base;
    
    freq[num[i]-'0']--;
    return ans + cntNum(num, n, freq, fact, i+1);
}

bool pof2(int n){ if(n & n-1) return false; return true; }

int main() {

    string num; cin >> num;
    int n = num.size();

    int freq[10] = {};
    for(int i=0; i<n; i++)
        freq[num[i]-'0']++;

    int fact[n];
    fact[0] = fact[1] = 1;
    for(int i=2; i<n; i++)
        fact[i] = i * fact[i-1];

    cout << cntNum(num, n, freq, fact) << endl;
}