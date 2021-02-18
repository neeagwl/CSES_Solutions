#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
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

ll power(ll base, ll exp); 
void prime_sieve(ll n, ll p[]);
bool is_prime(ll i,ll n);


int max_no=INT_MAX;
int min_no=INT_MIN;
//=======================


void solve() {
    ll n,m;
    cin>>n>>m;
    ll x=n+m-1;
    ll fact[x+1]={0};
    fact[0]=fact[1]=1;
    fact[2]=2;
    for(ll i=3;i<=x;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    ll ans=fact[x];
    ans=((ans%mod)*(power(fact[n-1],1000000005)%mod))%mod;
    ans=((ans%mod)*(power(fact[m],1000000005)%mod))%mod;
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

ll power(ll x,ll y){
    ll res=1; 
    while(y){
        if(y&1) res = (res*x)%mod; 
        y>>=1; 
        x = (x*x)%mod;
    }
    return res;
}

void prime_sieve(ll n, ll p[]){
    //all even not prime
   for(ll i=3;i<=n;i+=2){
      p[i]=1;
   }
   for(ll i=3;(i*i)<=n;i+=2){
     if(p[i]==1){
        for(ll j=i*i;j<n;j=j+i){
            p[j]=0;
        }
     }
   }
   p[2]=1;
   p[1]=p[0]=0;
}

bool is_prime(ll i, ll n){
    ll p[n+1];
    prime_sieve(n,p);
    return p[i];
}