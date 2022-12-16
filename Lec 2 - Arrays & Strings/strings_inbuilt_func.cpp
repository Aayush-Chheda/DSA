#include<iostream>
#include<cstring>

using namespace std;

int main(){
     
    char s[100];
    cin >> s;

    // find length of the string
    int len = strlen(s); 
    cout << len << endl;

    // compare 2 strings
    char s1[20], s2[20];
    cin >> s1; cin >> s2;
    // returns 0 if both strings are equal
    // returns 1 if s1 > s2 
    // returns -1 if s1 < s2
    cout << strcmp(s1, s2) << endl;

    // copy string 
    strcpy(s1, s2); // (destination_string, source_string)
    cout << s1 << endl;
    strcpy(s1, "hello");
    
    // strncpy(destination_string, source_string, n)
}