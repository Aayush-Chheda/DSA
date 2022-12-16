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

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    unordered_map<char, int> a, b;
    for(char i: s2)
        a[i]++;

    int req = a.size();

    int n = s1.size();
    int l, r; l = r = 0;
    int len = n + 1;

    int have = 0;
    int ans = l;
    while(r < n){
        char j = s1[r];
        if(a.count(j)){
            b[j]++;
            if(b[j] == a[j])
                have++;
            if(have == req){
                while(have == req){
                    char k = s1[l];
                    if(b.count(k)){
                        b[k]--;
                        if(b[k] < a[k]){
                            have--;
                            break;
                        }
                    }
                    l++;
                }
                if(r - l + 1 < len){
                    len = r - l + 1;
                    ans = l;
                }
                l++;
            }
        }
        r++;
    }

    cout << s1.substr(ans, len) << endl;
}