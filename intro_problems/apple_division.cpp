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

void sumSubset(int n, ll a[],int i,ll sum, vector<ll> & v){
    //base case
    if(i==n){
        v.PB(sum);
        return;
    }
    sumSubset(n,a,i+1,(sum+a[i]),v);
    sumSubset(n,a,i+1,sum,v);
}

void solve(){
    int n;
    cin>>n;
    ll a[n];
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    vector<ll> v;
    sumSubset(n,a,0,0,v);
    ll ans=max_no;
    for(int i=0;i<v.size();i++){
        ans=min(ans,abs(sum-v[i]-v[i]));
    }
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    solve();
}