#include "../template.h"

void weirdAlgo(ll n){
    cout<<n<<" ";

    //base case
    if(n==1){
        return;
    }
    //rec case
    if(n%2==0){
        weirdAlgo(n/2);
    }else{
        weirdAlgo((3*n+1));
    }
}

void solve(){
    ll n;
    cin>>n;
    weirdAlgo(n);
    cout<<'\n';
}

/********** Main()  function **********/
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    solve();
}