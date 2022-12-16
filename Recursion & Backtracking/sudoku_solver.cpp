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

const int N = 9;

void printBoard(vector<vector<int>> &board){
    cout << endl;
        rep(p,0,N){
            rep(q,0,N)  
                cout << board[p][q] << ' ';
            cout << endl;
        }
    cout << endl;
}

void markCell(vector<vector<int>> &board, int p, int q, bool a[N+1]){
    forn(N)
        a[board[p][i]] = true;
    forn(N)
        a[board[i][q]] = true;
    int x = p - p % 3;
    int y = q - q % 3;
    rep(i,x,x+3)    
        rep(j,y,y+3)
            a[board[i][j]] = true;
}

bool checkNum(int num, bool a[N+1]){
    if(a[num])
        return true;
    return false;
}

bool isSolvable(vector<vector<int>> &board, int i, int j){
    if(i == N-1 and j == N){
        printBoard(board);
        return true;
    }
    
    if(j == N){
        j = 0;
        i++;
    }

    if(board[i][j] != 0)
        return isSolvable(board, i, j+1);

    bool a[N+1] = {};
    markCell(board, i, j, a);
    rep(k,1,N+1){
        bool fcn = checkNum(k, a);
        if(!fcn){
            board[i][j] = k;
            bool fis = isSolvable(board, i, j+1);
            if(fis)
                return true;
        }
    }
    //cout << i << ' ' << j << endl;
    board[i][j] = 0;
    return false;
}

void generateAll(vector<vector<int>> &board, int i, int j){
    if(i == N-1 and j == N){
        printBoard(board);
        return;
    }
    
    if(j == N){
        j = 0;
        i++;
    }

    if(board[i][j] != 0){
        generateAll(board, i, j+1);
        return;
    }

    bool a[N+1] = {};
    markCell(board, i, j, a);
    rep(k,1,N+1){
        bool fcn = checkNum(k, a);
        if(!fcn){
            board[i][j] = k;
            generateAll(board, i, j+1);
        }
    }
    //cout << i << ' ' << j << endl;
    board[i][j] = 0;
}

int main() {

    vector<vector<int>> sudoku(9, vector<int>(9));
    rep(i,0,9)
        rep(j,0,9)
            cin >> sudoku[i][j];
    cout << endl;

    // solution exists ?
    cout << isSolvable(sudoku, 0, 0) << endl;

    // print all possible solutions
    generateAll(sudoku, 0, 0);
}