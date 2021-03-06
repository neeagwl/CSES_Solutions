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

int max_no=INT_MAX;
int min_no=INT_MIN;
//=======================


void solve() {
  int n;
  si(n);
  bool sieve[n+2];
  int i;
  fo(i,n+2){
      if(i%2){
          sieve[i]=true;
      }else{
          sieve[i]=false;
      }
  }
  sieve[2]=true;
  for(int i=2;i*i<=(n+1);i++){
      if(sieve[i]){
          for(int j=i*i;j<=n+1;j+=i){
              sieve[j]=false;
          }
      }
  }
  if(n>2){
      cout<<2<<'\n';
  }else{
      cout<<1<<'\n';
  }
  for(int i=2;i<=n+1;i++){
      if(sieve[i]){
          cout<<1<<" ";
      }else{
          cout<<2<<" ";
      }
  }
  cout<<'\n';
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