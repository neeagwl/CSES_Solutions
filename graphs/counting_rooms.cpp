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

char a[1001][1001];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void dfs(int r, int c, int n, int m){

    a[r][c]='#';

    for(int k = 0; k<4; k++){
            
            int rr = r + dr[k];
            int cc = c + dc[k];
            
            if(rr>=0 && rr<n && cc>=0 && cc<m && a[rr][cc]=='.'){
                
                dfs(rr, cc, n, m);
                
            }
            
    }

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //WRITE THE CODE HERE
    int n, m;
    cin>>n>>m;

    fo(0, n){
        for(int j=0; j<m; j++) cin>>a[i][j];
    }

    int ans=0;
    fo(0, n){
        for(int j=0; j<m; j++){

            if(a[i][j]=='.') {

                dfs(i, j, n, m);
                ans++;

            }

        }
    }

    cout<<ans<<'\n';

}




                 
              