/********   All Required Header Files ********/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define MEM(a, b) memset(a, (b), sizeof(a))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int  ull;

int max_no=INT_MAX;
int min_no=INT_MIN;

char board[8][8];

bool isSafe(int i, int j, int n)
{
    //col wise- only upper columns
    for (int row = i - 1; row >= 0; row--)
    {
        if (board[row][j] == 'Q')
        {
            return false;
        }
    }
    //upper left diagonal wise
    int x = i;
    int y = j;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 'Q')
        {
            return false;
        }
        x--;
        y--;
    }

    //upper right diagonal wise
    x = i;
    y = j;
    while (x >= 0 && y < n)
    {
        if (board[x][y] == 'Q')
        {
            return false;
        }
        x--;
        y++;
    }
    return true;
}

bool nQueen(int i, int n, int& total)
{
    //base case
    if (i == n)
    {
        total++;
        return false;
    }
    //rec case
    for (int j = 0; j < n; j++)
    {
        if (board[i][j]=='.' &&  isSafe(i, j, n))
        {
            board[i][j] = 'Q';
            bool nextQ = nQueen(i + 1, n,total);
            if (nextQ == false)
            {
                board[i][j] = '.';
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}

void solve(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>board[i][j];
        }
    }
    int total=0;
    nQueen(0,8,total);
    cout<<total<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    solve();
}
