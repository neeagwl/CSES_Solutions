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
ll n, k;
ll a[200001];

bool isPos( ll high){
    
    ll temp, sum;
    sum=0;
    temp=1;
    for(int i=0; i<n; i++){

        if(sum+a[i]<=high) sum+=a[i];
        else{
            temp++;
            sum=a[i];
        }
        if(temp>k) return false;

    }
    return true;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //WRITE THE CODE HERE
    ll s, e, mid, ans;
    
    cin>>n>>k;

    e=s=0;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        s= max(a[i], s);
        e += a[i];
    }

    while(s<=e){

        mid = (s+e)/2;
        if(isPos(mid)){
            ans = mid;
            e= mid-1;
        }else s = mid+1;

    }

    cout<<ans<<'\n';    

}
