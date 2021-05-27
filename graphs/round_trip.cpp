#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(k, n) for(int i=k; i<n; i++)
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
typedef map<ll, ll> mll;
typedef unordered_set<int> usi;
typedef set<int> seti;
//=======================

list<int>* l;
int sv, ev;

bool dfs(int src, int par, int vis[], vi& parent){

    vis[src]=1;
    parent[src] = par;

    for(auto nbr: l[src]){

        if(vis[nbr]){
            if(par!=nbr) {

                sv = nbr;
                ev = src;
                return true;

            }
        }
        
        if(!vis[nbr]) {
            if(dfs(nbr, src, vis, parent)) return true;
        }

    }

    return false;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //WRITE THE CODE HERE
    int n, m, u, v;
    cin>>n>>m;

    l = new list<int>[n];

    fo(0,m){
        cin>>u>>v;
        l[u-1].pb(v-1);
        l[v-1].pb(u-1);
    }

    bool flag = false;
    int vis[n] ={0};
    vi parent(n);

    vi path;

    fo(0, n){

        if(!vis[i]){

            if(dfs(i,-1, vis, parent)){

                //print path
                path.pb(sv);
                path.pb(ev);

                while(ev!=sv){
                    ev = parent[ev];
                    path.pb(ev);
                }

                cout<<path.size()<<'\n';
                for(auto city:path) cout<<city+1<<" ";
                cout<<'\n';

                flag = true;

            }

        }

        if(flag) break;
           
    }

    if(!flag) cout<<"IMPOSSIBLE"<<'\n';


}




                 
              