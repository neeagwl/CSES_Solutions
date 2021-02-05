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
ll dp[10000][10000];

ll knapsack(ll n,ll c){
	//base case
	if(n==0 || c==0){
		return 1;
	}
	//look up
	if(dp[n][c]!=-1){
		return dp[n][c];
	}
	//rec case
	ll op1,op2;
	op1=op2=INT_MIN;
    if(c>=n){
        op1=n*knapsack(n,c-n); //including the nth item
    }
	op2=knapsack(n-1,c); //excluding the nth item
	dp[n][c]=max(op1,op2);
    return dp[n][c];
}

void solve(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }
        ll ans= knapsack(n,n);
        cout<<ans<<'\n';
    }
}   


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    solve();
}