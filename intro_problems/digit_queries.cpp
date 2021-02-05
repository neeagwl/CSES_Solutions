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
    int q;
    cin>>q;
    while(q--){
        ll k;
        cin>>k;
        ll digit=1;
        ll num=0;
        ll powten=10;
        while((digit==1 && k>9) || (k>num)){
            digit++;
            cout<<"digit "<<digit<<'\n';
            k=k-num;
            num=9*powten;
            num*=digit;
            cout<<k<<" "<<num<<'\n';
        }
        cout<<"k"<<k<<'\n';
        cout<<"digit"<<digit<<'\n';
        ll last=0;
        for(ll i=1;i<digit;i++){
            last*=10;
            last+=9;
        }
        cout<<"last"<<last<<'\n';
        ll point= k/digit;
        ll rem= k%digit;
        cout<<"point"<<point<<'\n';
        cout<<"rem"<<rem<<'\n';
        ll final_num= last+point;
        cout<<"finalnum"<<final_num<<'\n';
        ll cnt= digit-rem;
        cout<<"cnt"<<cnt<<'\n';
        if(rem>0){
            final_num++;
            while(cnt--){
                final_num/=10;
            }
        }
        cout<<(final_num%10)<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    solve();
}