#include <iostream>
#include<bits/stdc++.h>
using namespace std;
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

int xoredSubarrays(int n,int k,int a[]){
    int cnt=0;
    int xr=0;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        xr^=a[i];
        if(xr==k) cnt++;
        int y=xr^k;
        if(m.find(y)!=m.end()) cnt+=m[y];
        m[y]++;
    }
    return cnt;
}


void solve() {
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        int num;
        cin>>a[i];
    }
    cout<<xoredSubarrays(n,k,a)<<'\n';

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