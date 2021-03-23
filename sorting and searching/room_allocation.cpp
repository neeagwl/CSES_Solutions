
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
typedef multimap<int, int> mmap;
//=======================


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //WRITE THE CODE HERE
    int n, a, b, cnt, c, t, idx;
    cin>>n;
    multimap<pii, int> m;

    for(int i=0; i<n; i++){
        cin>>a>>b;
        m.insert({{a,b},i});
    }

    priority_queue<pii, vpii, greater<pii>> pq;
    int ans[n];

    cnt=0;

    for(auto it = m.begin(); it!=m.end(); it++){
        
        a = (*it).F.F;
        b= (*it).F.S;
        idx = (*it).S;
       
        if(!pq.empty()) {
             t = pq.top().F;
             c = pq.top().S;
        }
       
        if(!pq.empty() && a>t){
            ans[idx]=c;
            pq.pop();
            pq.push({b, c});
        }else{
            cnt++;
            ans[idx]=cnt;
            pq.push({b, cnt});
        }

    }

    cout<<cnt<<'\n';
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';

}
