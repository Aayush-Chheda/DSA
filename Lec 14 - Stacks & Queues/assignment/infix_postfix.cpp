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

int rankOperator(char opr){
    if(opr == '+' or opr == '-')
        return 1;
    else if(opr == '*' or opr == '/')
        return 2;
    return 3;
}

bool hasHigherPrecedence(char opr1, char opr2){
    int r1 = rankOperator(opr1);
    int r2 = rankOperator(opr2);
    if(r1 > r2 or r1 == r2 and opr1 != '^')
        return true;
    return false;
}

bool isBracket(char c){
    return c == '(' or c == ')';
}

int main() {
    
    string s; 
    cin >> s;

    string postfix = "";

    int n = s.size();
    stack<char> sk;
    forn(n){
        if(s[i] == '('){
            sk.push(s[i]);
            i++;
        }
        else if(s[i] == ')'){
            while(sk.top() != '('){
                postfix += sk.top();
                sk.pop();
            }
            sk.pop();
            i++;
        }
        else if(isOperator(s[i])){
            while(!sk.empty() and !isBracket(sk.top()) and hasHigherPrecedence(sk.top(), s[i])){
                postfix += sk.top();
                sk.pop();
            }
            sk.push(s[i]);
            i++;
        }
        else{
            while(i < n and s[i] != ','){
                postfix += s[i];
                i++;
            }
        }
    }
    while(!sk.empty()){
        postfix += sk.top();
        sk.pop();
    }

    cout << postfix << endl;
}