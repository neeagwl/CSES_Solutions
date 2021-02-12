#include <iostream>
#include <bits/stdc++.h>
using namespace std;

    int divide(int dividend, int divisor) {
         if(dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int x= abs(-2147483647);
        int y= abs(-100);
        cout<<y<<" "<<x<<'\n';
        
        bool flag =false;
        if(divisor<0){
            flag=!flag;
        }
        if(dividend<0){
            flag=!flag;
        }

        long divi=abs((long)dividend);
        long divis=abs((long)divisor);
        
        int q=0;
        while(divi-divis>=0){
            int x=0;
            while((divi- (divis<<1<<x))>=0){
                x++;
            }
            q+=(1<<x);
            divi-=(divis<<x);
        }
        if(flag){
            return -q;
        }
        return q;
    }


int main(){
    int a,b;
    cin>>a>>b;
    cout<<divide(a,b)<<'\n';
}