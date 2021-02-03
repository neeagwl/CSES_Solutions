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

ll binary_exp(ll base,ll pow){
    if(pow==1){
        return base;
    }
    if(pow%2){
        ll b=base*base;
        pow=(pow-1)/2;
        base = base*(binary_exp(b,pow));
    }else{
        ll b=base*base;
        pow=pow/2;
        base=binary_exp(b,pow);
    }
    return base;
}

void solve(){
    ll n;
    cin>>n;
    ll ans=0;
    ll pow=1;
    ll t= binary_exp(5,pow);
    while((n/t)>0){
        ans+=(n/t);
        pow+=1;
        t=binary_exp(5,pow);
    }
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    solve();
}