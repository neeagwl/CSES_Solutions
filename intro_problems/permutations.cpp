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
#define PF push_front
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

void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<1<<'\n';
        return;
    }
    if(n<4){
        cout<<"NO SOLUTION"<<'\n';
        return;
    }
    deque<int> dq{2,4,1,3};
    bool flag=false;
    while(n>4){
        if(flag){
            dq.PB(n);
        }else{
            dq.PF(n);
        }
        flag=!flag;
        n--;
    }
    for(auto num:dq){
        cout<<num<<" ";
    }
    cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    solve();
}