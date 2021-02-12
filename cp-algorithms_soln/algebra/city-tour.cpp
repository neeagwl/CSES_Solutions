#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll power(ll x,ll y){
    ll res=1; 
    while(y){
        if(y&1) res = (res*x)%mod; 
        y>>=1; 
        x = (x*x)%mod;
    }
    return res;
}

int solve(int A, vector<int> &B) {
    sort(B.begin(),B.end());
    int vis= B.size();
    int n= A-vis;
    vector<int> C;
    C.push_back(B[0]-1);
    for(int i=1;i<vis;i++){
        C.push_back(B[i]-B[i-1]-1);
    }
    C.push_back(A-B[vis-1]);
    ll fact[1001];
    fact[0]=fact[1]=1;
    for(ll i=2;i<=n;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    ll ans=fact[n];
    for(int i=0;i<C.size();i++){
        if(C[i]>1){
            ans*=(power(fact[C[i]],1000000005)%mod);
            ans=ans%mod;
        }
    }
    ll x=1;
    for(int i=1;i<C.size()-1;i++){
            if(C[i]<2) continue;
            x=(x*power(2,C[i]-1))%mod;
    }
    ans=(ans*x)%mod;
    return ans%mod;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v;
    for(int i=0;i<m;i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    cout<<solve(n,v)<<'\n';
}