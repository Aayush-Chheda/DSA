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

bool checkValidIndex(int i, int j, int n){
    if(i > -1 and j > -1 and i < n and j < n)
        return true;
    return false;
}

void printSolutionPath(bool **visited, int n){
    cout << endl;
    rep(i,0,n){
        rep(j,0,n)
            cout << visited[i][j] << ' ';
        cout << endl;
    }
}

bool hasPath(bool **grid, int n, int i, int j, bool **visited){
    if(i == n-1 and j == n-1)
        return visited[i][j] = true;

    if(checkValidIndex(i, j, n) and grid[i][j] and not visited[i][j]){
        visited[i][j] = true;
        bool b1 = hasPath(grid, n, i, j+1, visited);
        bool b2 = hasPath(grid, n, i+1, j, visited);
        bool b3 = hasPath(grid, n, i-1, j, visited);
        bool b4 = hasPath(grid, n, i, j-1, visited);
        if(b1 or b2 or b3 or b4)
            return true;
        visited[i][j] = false;
    }
    return false;
}

void printAllPaths(bool **grid, int n, int i, int j, bool **visited){
    if(i == n-1 and j == n-1){
        printSolutionPath(visited, n);
        return;
    }
    if(checkValidIndex(i, j, n) and grid[i][j] and not visited[i][j]){
        visited[i][j] = true;
        printAllPaths(grid, n, i, j+1, visited);
        printAllPaths(grid, n, i+1, j, visited);
        printAllPaths(grid, n, i-1, j, visited);
        printAllPaths(grid, n, i, j-1, visited);
        visited[i][j] = false;
    }
}

int main(){

    int n; cin >> n;
    bool **grid = new bool*[n], **visited = new bool*[n];
    forn(n){
        grid[i] = new bool[n];
        visited[i] = new bool[n];
    }

    rep(i,0,n)
        rep(j,0,n){
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    
    // is there a path ?
    cout << endl;
    cout << hasPath(grid, n, 0, 0, visited) << endl;
    printSolutionPath(visited, n);

    cout << "------------------------------" << endl;
    rep(i,0,n)
        rep(j,0,n)
            visited[i][j] = false;

    // print all paths
    visited[n-1][n-1] = true;
    printAllPaths(grid, n, 0, 0, visited);
}