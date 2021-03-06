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
list<pll>* l;
list<pll>* lr;

void dijkstra(set<pll>s, vl &dist, int src, list<pll>* l){

    s.insert({0, src});
    dist[src]=0;

    while(!s.empty()){

        auto tmp = *(s.begin());
        ll node = tmp.second;
        ll currDist = tmp.first;
        s.erase(s.begin());

        for(auto nbr: l[node]){

            ll nbrNode= nbr.first;
            ll edgeDist = nbr.second;

            if(currDist+edgeDist<dist[nbrNode]){

                if(dist[nbrNode]!=LLINF){
                    s.erase(s.find({dist[nbrNode], nbrNode}));
                }

                dist[nbrNode] = currDist+ edgeDist;
                s.insert({dist[nbrNode], nbrNode});

            }

        }

    }

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //WRITE THE CODE HERE
    ll n, m, u, v, wt, node, ans;
    cin>>n>>m;

    l = new list<pll>[n];
    lr = new list<pll>[n];
    vpipii edgelist;

    fo(0,m){

        cin>>u>>v>>wt;

        l[u-1].pb({v-1, wt});
        lr[v-1].pb({u-1, wt});
        edgelist.pb({wt, {u-1, v-1}});

    }

    vl dist1(n, LLINF);
    vl dist2(n, LLINF);
 
    set<pll> s;

    //src =0;
    dijkstra(s, dist1, 0, l);
    
    s.clear();

    //src= n-1;
    dijkstra(s, dist2, n-1, lr);

    ans = LLINF;
    for(auto edge: edgelist){

        wt = edge.F;
        u = edge.S.F;
        v = edge.S.S;

        ans = min(ans, dist1[u] + dist2[v] + wt/2);

    }

    cout<<ans<<'\n';

}




                 
              