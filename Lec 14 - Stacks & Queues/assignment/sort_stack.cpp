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

void sortedInsert(stack<int> &s, int x){

    if(s.empty() or x < s.top()){
        s.push(x);
        return;
    }
    int xs = s.top();
    s.pop();
    sortedInsert(s, x);
    s.push(xs);
}

// Recursive approach using 2 recursions at once.
void sortStack(stack<int> &s){
    if(s.size() == 1)
        return;
    int x = s.top(); 
    s.pop();
    sortStack(s);
    sortedInsert(s, x);
}

int main() {

    int n; cin >> n;
    stack<int> s1, s2;

    forn(n){
        int x; cin >> x;
        s1.push(x);
    }

    // Iterative Approach

    // while(!s1.empty()){
    //     int x = s1.top();
    //     s1.pop();
    //     while(!s2.empty() and x > s2.top()){
    //         s1.push(s2.top());
    //         s2.pop(); 
    //     }
    //     s2.push(x);
    // }

    sortStack(s1);

    while(!s1.empty()){
        cout << s1.top() << ' ';
        s1.pop();
    }
}