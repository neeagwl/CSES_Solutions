#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef vector<pair<ll,int>> vec;

void filter(ll a[],ll n,vec& v,ll num){
    ll j=0;
    ll ans=1;
    int cnt=0;
    while(n>0){
        ll last_bit=(n&1);
        if(last_bit==1){
            cnt++;
            ans*=a[j];
            if(ans>num){
                ans=1;
                break;
            }
        }
        j++;
        n=n>>1;
    }
    if(ans>1) v.push_back({ans,cnt});
}

vec printsubsets(ll a[],ll n, vec& v,ll num){
 for(ll i=0;i<(1<<n);i++){
    filter(a,i,v,num);
 }
 return v;
}
int main(){
    ll n, k;
    cin>>n>>k;
    ll a[k];
    for(ll i=0;i<k;i++){
        cin>>a[i];
    }
    vec v;
    printsubsets(a,k,v,n);
    ll ans=0;
    for(auto p:v){
        ll lcm=p.first;
        int x=p.second;
        if(x%2) ans+=(n/lcm);
        else ans-=(n/lcm);
    }
    cout<<ans<<'\n';
}
