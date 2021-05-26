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

int visited[100001]={0};
list<int> *l;

void dfs(int src, vi& v){

    visited[src] =1;
    v.pb(src);

    for(auto nbr: l[src]){
        if(!visited[nbr]) dfs(nbr, v);
    }

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //WRITE THE CODE HERE
    int n, m, u, v, numRoads;
    cin>>n>>m;

    l = new list<int>[n];
    vvi comp;

    fo(0, m){

        cin>>u>>v;
        l[u-1].pb(v-1);
        l[v-1].pb(u-1);

    }

    fo(0, n){

        if(!visited[i]){

            vi v;
            v.clear();
            dfs(i, v);
            comp.pb(v);

        }

    }

    vpii new_roads;
    numRoads = comp.size()-1;

    fo(0, numRoads){

        u = comp[i][0];
        v = comp[i+1][0];

        new_roads.pb({u+1,v+1});

    }

    cout<<numRoads<<'\n';
    for(auto road: new_roads) cout<<road.F<<" "<<road.S<<'\n';


}




                 
              