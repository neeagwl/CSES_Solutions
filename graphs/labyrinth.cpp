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

// 0-D, 1-R, 2-U, 3-L

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //WRITE THE CODE HERE
    int n, m, x, y, xx, yy;
    cin>>n>>m;

    char a[n][m];
    vector<vpii> parent(n, vpii(m));

    pii start, end;

    fo(0, n){
        for(int j=0; j<m; j++) {

            cin>>a[i][j];
            parent[i][j] = {-1, -1};

            if(a[i][j]=='A') {
                start={i,j};
            }
            if(a[i][j]=='B') {
                end = {i,j};
            }
            
        }
    }

    queue<pii> q;
    q.push(start);

    a[start.F][start.S]='#'; //make start pos as visited
    a[end.F][end.S] ='.'; //make end pos as open

    while(!q.empty()){

            int r = q.front().F;
            int c = q.front().S;

            q.pop();

            if(r==end.F && c==end.S) break;

            //explore nbrs
            for(int k = 0; k<4; k++){
                
                int rr = r + dr[k];
                int cc = c + dc[k];

                if(rr>=0 && rr<n && cc>=0 && cc<m && a[rr][cc]=='.' ){
                    q.push({rr,cc});
                    a[rr][cc] = '#'; //make it as visited
                    parent[rr][cc] = {-dr[k],-dc[k]};
                }
  

            }

    }

    if(a[end.F][end.S]=='.') cout<<"NO"<<'\n';
    else{

        vector<char> path;
        x = end.F;  y = end.S;
        while(x!= start.F || y!=start.S){

            xx = parent[x][y].F;
            yy = parent[x][y].S;

            if(xx==1 && yy == 0) path.pb('U');

            else if(xx == -1 && yy == 0) path.pb('D');

            else if(xx == 0 && yy==1) path.pb('L');

            else if(xx == 0 && yy == -1)  path.pb('R');

            x+=xx; y+=yy;


        }

        cout<<"YES"<<'\n';
        cout<<path.size()<<'\n';

        reverse(path.begin(), path.end());
        for(auto ch: path) cout<<ch;
        cout<<'\n';


    }


}




                 
              