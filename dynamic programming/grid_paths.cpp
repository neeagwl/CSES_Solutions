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
int dp[1001][1001];


int solve(int n){

    //base case

    for(int i=0; i<n && dp[i][0]!=-1; i++) dp[i][0] = 1;

    for(int j=0; j<n && dp[0][j]!=-1; j++) dp[0][j]=1;

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){

            if(dp[i][j]!=-1){

                if(dp[i-1][j]!=-1) dp[i][j] += dp[i-1][j];
                dp[i][j] %= mod;

                if(dp[i][j-1]!=-1) dp[i][j] += dp[i][j-1];
                dp[i][j] %= mod; 

            }

        }
    }
    
    return dp[n-1][n-1];

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //WRITE THE CODE HERE
    int n;
    cin>>n;

    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){

            char ch;
            cin>>ch;
            if(ch=='.'){
                dp[i][j]=0;
            }

        }
    }

    if(dp[n-1][n-1]==-1 || dp[0][0]==-1)    cout<<0<<'\n';

    else  cout<<solve(n)<<'\n';

}
