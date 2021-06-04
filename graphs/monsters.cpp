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


int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

string s = "DRUL";

// 0-D, 1-R, 2-U, 3-L

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //WRITE THE CODE HERE
    int n, m, x, y, d, r, c;
    char xx, yy;
    cin>>n>>m;

    if(n==1 && m==1) {
        cout<<"YES"<<'\n';
        cout<<'0'<<'\n';
    }
    else{

    char a[n][m];
    int dist[n][m];
    char parent[n][m];
    bool vis[n][m];
    pii from[n][m];
    queue<pair<int, pii>> q;

    pii start, end;

    fo(0, n){
        for(int j=0; j<m; j++) {

            cin>>a[i][j];
            parent[i][j] = '*';
            dist[i][j] = 0;
            vis[i][j]=0;
            from[i][j]={-1,-1};

            if(a[i][j]=='A') start={i,j};

            else if(a[i][j]=='M') 
            {
                q.push({0,{i,j}});
                dist[i][j] = 0;
                vis[i][j] =1;
            }
            else if(a[i][j]=='#') vis[i][j]=1;
            
        }
    }
    a[start.F][start.S] ='.';

    //multi source bfs
    while(!q.empty()){

        d = q.front().F;
        r = q.front().S.F;
        c = q.front().S.S;

        q.pop();

        //explore nbrs
        for(int k = 0; k<4; k++){
                
            int rr = r + dr[k];
            int cc = c + dc[k];

            if(rr>=0 && rr<n && cc>=0 && cc<m && !vis[rr][cc]){
                q.push({d+1,{rr,cc}});
                dist[rr][cc] = d+1;
                vis[rr][cc] = 1;
            }
  

        }

    }

    fo(0, n){
        for(int j=0; j<m; j++) cout<<dist[i][j]<<" ";
        cout<<'\n';
    }

    //bfs frm src A 
    end = {-1, -1};
    q.push({0,{start.F, start.S}});
    dist[start.F][start.S] =0;

    while(!q.empty()){

        d = q.front().F;
        r = q.front().S.F;
        c = q.front().S.S;

        q.pop();

        //explore nbrs
        for(int k = 0; k<4; k++){
                
            int rr = r + dr[k];
            int cc = c + dc[k];

            if(rr>=0 && rr<n && cc>=0 && cc<m  && (dist[rr][cc] > d+1 || !vis[rr][cc])){
                q.push({d+1,{rr,cc}});
                from[rr][cc] ={r,c};
                parent[rr][cc] = s[k];
                vis[rr][cc]=1;
                if(rr==0 || rr==n-1 || cc==0 || cc==m-1){
                    end={rr, cc};
                    break;
                }
            }
  

        }
        if(end.F!=-1) break;

    }
    // fo(0, n){
    //     for(int j=0; j<m; j++) cout<<parent[i][j].F<<","<<parent[i][j].S<<"  ";
    //     cout<<'\n';
    // }

    if(end.F==-1) cout<<"NO"<<'\n';
    else{

        string path ="";
        x = end.F; y = end.S;
        while(x!=start.F || y!=start.S){

            path += parent[x][y];

            x = from[x][y].F;
            y = from[x][y].S;

        }

        cout<<"YES"<<'\n';
        cout<<path.length()<<'\n';

        reverse(path.begin(), path.end());
        cout<<path<<'\n';    

    }

        
    }


}




                 
              