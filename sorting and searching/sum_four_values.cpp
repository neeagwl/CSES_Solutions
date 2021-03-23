#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define mem(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define INF (int)1e9
#define EPS 1e-9
#define mod 1000000007

typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
typedef unordered_map<int,int> umii;
typedef map<int,int> mii;
typedef unordered_set<int> usi;
typedef set<int> seti;
//=======================

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //WRITE THE CODE HERE
    ll n, x, num, i, j, k, l, sum, temp1, temp2;
    bool flag = false;
    cin>>n>>x;

    vpii v;
    for(int i=1; i<=n; i++){
        cin>>num;
        v.pb({num, i});
    }

    sort(v.begin(), v.end());

    l= n-1;
    while(l>2){
        if(v[l].F>x){
            l--;
            continue;
        }
        temp1= x- v[l].F;
        k= l-1;
        while(k>1){
            if(v[k].F>temp1){
                k--;
                continue;
            }
            temp2 = temp1- v[k].F;
            i=0; j = k-1;
            while(i<j){
                sum = v[i].F+ v[j].F;
                if(temp2==sum){
                    flag= true;
                    cout<<v[i].S<<" "<<v[j].S<<" "<<v[k].S<<" "<<v[l].S<<'\n';
                    break;
                }else if(sum>temp2) j--;
                else i++;
            }
            if(flag) break;
            k--;
        }
        if(flag) break;
        l--;
    }
    if(!flag) cout<<"IMPOSSIBLE"<<'\n';
}
