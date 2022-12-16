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

    unordered_map<string, int> ump;

    // insert
    ump.insert({"abc", 1});
    ump["def"] = 2;

    // find or access
    cout << ump["abc"] << endl;
    cout << ump.at("def") << endl;

    // if key not present (behaviour)
    // cout << ump.at("ghi") << endl; 
    // Will throw error if key not present
    cout << ump["ghi"] << endl; // Will insert 0 if key not present

    // check if key is present without default insertion
    if(ump.count("ghi") > 0)
        cout << "present" << endl;

    // delete a key
    ump.erase("ghi");
    cout << ump.size() << endl;
}