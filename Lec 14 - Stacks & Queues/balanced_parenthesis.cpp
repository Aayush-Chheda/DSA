#include <bits/stdc++.h>

using namespace std;

char checkCBracket(char c){
    switch (c)
    {
    case ']':
        return '['; 
        break;
    case ')':
        return '(';
        break;
    default:
        return '{';
    }
}

bool isBalanced(string s, stack<char> sk){

    int n = s.size();
    for(int i=0; i<n; i++){
        if(s[i] == '[' or s[i] == '(' or s[i] == '{')
            sk.push(s[i]);
        else if(s[i] == ']' or s[i] == ')' or s[i] == '}'){
            if(sk.empty() or sk.top() != checkCBracket(s[i]))
                return false;
            else
                sk.pop();
        }
    }
    if(sk.empty())
        return false;
    return true;
}

int main() {

    string s; cin >> s;
    stack<char> sk;

}