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
vi indeg;

void findOrder(int v, vi& in) {
    
    vi top_order;
    
    queue<int> q;
    fo(0, v) if(in[i]==0) q.push(i);
    
    int cnt=0;
    while(!q.empty()){
        
        int node = q.front();
        q.pop();
        top_order.push_back(node);
        
        for(auto nbr: l[node]){
            
            in[nbr]--;
            if(in[nbr]==0) q.push(nbr);
            
        }
        cnt++;
        
    }
    
    if(cnt!=v) {
        cout<<"IMPOSSIBLE"<<'\n';
        return ;
    }
    
    for(auto num: top_order) cout<<num<<" ";
    cout<<'\n';
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //WRITE THE CODE HERE
    ll n, m, u, v, wt, node, ans;
    cin>>n>>m;

    vi indeg(n, 0);

    fo(0,m){

        cin>>u>>v>>wt;
        l[u-1].pb(v-1);
        indeg[v-1]++;

    }

    findOrder(n, indeg);

    
}




                 
              