#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void totient_fxn(int n, int phi[]){
    for(int i=0;i<=n;i++){
        phi[i]=i;
    }
    for(int i=2;i<=n;i++){
        if(phi[i]==i){
            phi[i]=i-1;
            for(int j=2*i;j<=n;j+=i){
                phi[j]=(phi[j]*(i-1))/i;
            }
        }
    }
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        int n;
        cin>>n;
        ll ans=0;
        int phi[n+1];
        totient_fxn(n,phi);
        for(int i=1;i<=n;i++){
            if(!(n%i)){
                ans+=(i*phi[i]);
            }
        }
        ans=((ans+1)*n)/2;
        cout<<ans<<'\n';
        }
    
    return 0;
}

