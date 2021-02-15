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
#define MOD 1000000007

typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;

int mpow(int base, int exp); 
void prime_sieve(ll n, ll p[]);
bool is_prime(ll i,ll n);


int max_no=INT_MAX;
int min_no=INT_MIN;
//=======================

ll power(ll a,ll b){
    if(b==1) return a%MOD;
    if(b==0) return 1;
    ll res=1;
    while(b){
        if(b&1) res=((res%MOD)*(a%MOD))%MOD;
        b=b>>1;
        a=((a%MOD)*(a%MOD))%MOD;
    }
    return res;
}


void solve() {
    ll a,b,c;
    cin>>a>>b>>c;
    b%=MOD;
    ll p=power(b,c);
    p%=MOD;
    ll ans=power(a,p);
    cout<<(ans%MOD)<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

int mpow(int base, int exp) {
  base %= MOD;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % MOD;
    base = ((ll)base * base) % MOD;
    exp >>= 1;
  }
  return result;
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