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
#define LLINF LLONG_MAX

typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pll>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
typedef unordered_map<int,int> umii;
typedef map<int,int> mii;
typedef map<ll, ll> mll;
typedef unordered_set<int> usi;
typedef set<int> seti;
//=======================
int primes[10] ={0, 1, 11, 101, 1087, 10007, 100003, 1000003, 10000019, 100000007};
//---------------------------------------------------------------------------

struct cmp {

    bool operator()(const int& a, const int& b) const {
        return a > b;
    }

};


ll power(ll x,ll y){
    ll res=1; 
    while(y){
        if(y&1) res = (res*x)%mod; 
        y>>=1; 
        x = (x*x)%mod;
    }
    return res;
}

ll inverse(ll i){
    if(i==1) return 1;
    return (power(i,mod-2))%mod;
}

string decimalToBinary(int n)
{
    //finding the binary form of the number and
    //coneverting it to string.
    string s = bitset<64> (n).to_string();
     
    //Finding the first occurance of "1"
    //to strip off the leading zeroes.
    const auto loc1 = s.find('1');
     
    if(loc1 != string::npos)
        return s.substr(loc1);
     
    return "0";
}

bool isPowerOfTwo(int n)
{
   if(n==0)
   return false;
 
   return (ceil(log2(n)) == floor(log2(n)));
}

ll highestPowerof2(ll n)
{
   ll p = (ll)log2(n);
   return (ll)pow(2, p);
}
 

void prime_sieve(ll n, ll p[]){

    //all even not prime
   for(ll i=2;i<=n;i+=2){
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //WRITE THE CODE HERE

}




                 
              