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


int max_no=INT_MAX;
int min_no=INT_MIN;
//=======================

int power(int x,int y){
    int res=1; 
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


ll binCoeff(int n, int k) 
{ 
    ll res = 1; 
  
    // Since C(n, k) = C(n, n-k) 
    if (k > n - k) 
        k = n - k; 
  
    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1] 
    for (int i = 0; i < k; ++i) { 
        res *= (n - i); 
        res%=mod;
        res /= (i + 1); 
    } 
  
    return res%mod; 
} 


void solve() {
    int n;
    si(n);
    if(n%2){
        int win=(n-1)/2;
        int freq[n+1]={0};
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(freq[i]<win){
                    cout<<1<<" ";
                    freq[i]++;
                }else if(freq[j]<win){
                    cout<<-1<<" ";
                    freq[j]++;
                }else{
                    cout<<0<<" ";
                }
            }
        }
    }else{
        for(int i=1;i<=n;i++){
            int win=(n-1)/2;
            int x=win;
            int j=i+1;
            while(win-- && j<=n){
                cout<<1<<" ";
                j++;
            }
            if(j<=n){
                 cout<<0<<" ";
                 j++;
            }
            while(x-- && j<=n){
                cout<<-1<<" ";
                j++;
            } 

        }
    }
    cout<<'\n';
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
