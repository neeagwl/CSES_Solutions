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


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //WRITE THE CODE HERE
    int n, m, u, v, node, color;
    cin>>n>>m;

    list<int> l[n];

    fo(0,m){
        cin>>u>>v;
        l[u-1].pb(v-1);
        l[v-1].pb(u-1);
    }

    vi colors(n, -1);

    queue<pii> q;
    bool flag = true;

    fo(0, n){
        if(colors[i]==-1){
            q.push({i,0});
            colors[i]=0;

            while(!q.empty()){

                node = q.front().F;
                color = q.front().S;

                q.pop();

                for(auto nbr : l[node]){

                    if(colors[nbr]==-1){
                        colors[nbr] = 1-color;
                        q.push({nbr, colors[nbr]});
                    }

                    else if(colors[nbr]==color){
                        flag = false;
                        break;
                    }


                }

                if(!flag) break;

         }

        }
    }


    if(!flag) cout<<"IMPOSSIBLE"<<'\n';
    else{

        fo(0, n){
            if(colors[i]==0) cout<<1<<" ";
            else cout<<2<<" ";
        }
        cout<<'\n';

    }

}




                 
              