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

vi v;

void solve(int a[], int n, int w){

    int dp[n+1][w+1];

    for(int j=0; j<=w; j++) dp[0][j]=0;
    for(int i=0; i<=n; i++) dp[i][0]=1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){

            if(a[i-1]<=j){

                dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];

            }else{

                dp[i][j]= dp[i-1][j];

            }

        }
    }

    for(int j=1; j<=w; j++){
        if(dp[n][j]==1) v.pb(j);
    }

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //WRITE THE CODE HERE
    int n,x;
    cin>>n;

    int a[n];
    x =0;
    for(int i=0; i<n; i++){

         cin>>a[i];
         x+=a[i];
    
    }

    solve(a, n, x);

    cout<<v.size()<<'\n';

    for(auto num: v){

        cout<<num<<" ";

    }

    cout<<'\n';

}

