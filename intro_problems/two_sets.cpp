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

void solve(){
    int n;
    cin>>n;
    VI first,scnd;
    if( n<3 || (n%2==0 && (n/2)%2 ) || (n%2 && (n/2)%2==0)){
        cout<<"NO"<<'\n';
        return;
    }
    if(n%2==0){
        int i=1;
        int j=n;
        while(i<j){
            first.PB(i); first.PB(j);
            i++; j--;
            scnd.PB(i); scnd.PB(j);
            i++;j--;
        }
    }else{
            first.PB(1); first.PB(2);
            scnd.PB(3);
            int i=4; int j=n;
            while(i<j){
                first.PB(i); first.PB(j);
                i++; j--;
                scnd.PB(i); scnd.PB(j);
                i++; j--;
            }
    }
        int n1=first.size();
        int n2=scnd.size();
        cout<<"YES"<<'\n';
        cout<<n1<<'\n';
        for(int i=0;i<n1;i++){
            cout<<first[i]<<" ";
        }
        cout<<'\n';
        cout<<n2<<'\n';
        for(int i=0;i<n2;i++){
            cout<<scnd[i]<<" ";
        }
        cout<<'\n';

}


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    solve();
}