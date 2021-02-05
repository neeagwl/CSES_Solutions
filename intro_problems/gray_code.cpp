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
typedef vector<char> VCH;
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
    VS v;
    v.PB("0");
    v.PB("1");
    for(int i=2;i<(1<<n);i=i<<1){
        // Enter the prviously generated codes again in arr[] in reverse
        // order. Nor arr[] has double number of codes.
        for (int j = i-1 ; j >= 0 ; j--)
            v.PB(v[j]);
 
        // append 0 to the first half
        for (int j = 0 ; j < i ; j++)
            v[j] = "0" + v[j];
 
        // append 1 to the second half
        for (int j = i ; j < 2*i ; j++)
            v[j] = "1" + v[j];    
    }
    for(int i=0;i<v.size();i++){
            cout<<v[i]<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    solve();
}