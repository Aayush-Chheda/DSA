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

bool isOperator(char c){
    return c == '+' or c == '-' or c == '*' or c == '/' or c == '^';
}

int performOperation(int op1, int op2, char op){
    if(op == '+')
        return op1 + op2;
    else if(op == '-')
        return op1 - op2;
    else if(op == '*')
        return op1 * op2;
    else if(op == '/')
        return op1 / op2;
    else
        return pow(op1, op2);
}

int main() {

    string s;
    cin >> s;

    // delimiter => ','
    // Given postfix / prefix expression is valid and a correct one
    // ab*cd*+e- (Postfix Evaluation)

    int n = s.size();
    stack<int> sk;
    forn(n){
        if(isOperator(s[i])){
            int op2 = sk.top();
            sk.pop();
            int op1 = sk.top();
            sk.pop(); 
            int val = performOperation(op1, op2, s[i]);
            sk.push(val);
            i++;
        }
        else{
            int opd = 0;
            while(s[i] != ',' and i < n){
                opd = opd * 10 + (s[i] - '0');
                i++;
            }
            sk.push(opd);
        }
    }
    cout << sk.top() << endl;

    // For Prefix Evaluation, simply reverse the string 
    // and apply the same algo above
}