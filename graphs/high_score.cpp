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
#define LLINF LLONG_MAX

typedef pair<int, int>	pii;
typedef pair<int, pii> pipii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pipii>   vpipii;
typedef vector<pll>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
typedef unordered_map<int,int> umii;
typedef map<int,int> mii;
typedef map<ll, ll> mll;
typedef unordered_set<int> usi;
typedef set<int> seti;
//=======================


list<int>* l;
vector<ll> dist;
vpipii edgelist;
set<int> chNode;

ll dfs(int src, int vis[], int n){

    vis[src] = 1;
    if(chNode.find(src)!=chNode.end()) return LLINF;
    for(auto nbr: l[src]){
        if(!vis[nbr]) {
            if(dfs(nbr, vis, n)==LLINF) return LLINF;
        }
    }

    return dist[n-1];

}


bool relaxEdge(int d){

    bool isChanged= false;
                
    for(auto edge: edgelist){

        ll wt = edge.F;
        ll src = edge.second.F;
        ll dstn = edge.second.S;

        if(dist[src]!=LLINF && dist[src]+ wt <dist[dstn]){
            dist[dstn] = dist[src] +wt;                
            isChanged= true;
            chNode.insert(dstn);
        }

    }

    return isChanged;

}

//BELLMAN FORD
ll bellman_ford(int src, int n, int vis[]){

    dist[src]=0;

    fo(1, n){

        if(!relaxEdge(n-1)) break;

    }

    //check for one more time;
    chNode.clear();
    bool negCycle = relaxEdge(n-1);

    if(!negCycle) return dist[n-1];
        
    return dfs(n-1, vis, n);

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //WRITE THE CODE HERE
    ll n, m, u, v, wt, node, ans;
    cin>>n>>m;

    int vis[n]= {0};
    l = new list<int>[n];

    fo(0,m){

        cin>>u>>v>>wt;

        l[v-1].pb(u-1);
        edgelist.pb({-wt, {u-1, v-1}});

    }
    if(m==1){
        cout<<(-edgelist[0].F)<<'\n';
    }
    else{

        dist.resize(n);
        fo(0, n) dist[i]= LLINF;
        
        ans = bellman_ford(0, n, vis);
        if(ans==LLINF) cout<<-1<<'\n';
        else cout<<(-ans)<<'\n';

    }

}




                 
              