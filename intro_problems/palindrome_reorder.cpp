/********   All Required Header Files ********/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define MEM(a, b) memset(a, (b), sizeof(a))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef stack<char> CHARSTACK;
typedef stack<int> INTSTACK;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int  ull;

int max_no=INT_MAX;
int min_no=INT_MIN;

void solve(){
    char map[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; 
    string s;
    cin>>s;
    int n=s.length();
    if(n<3){
        cout<<s<<'\n';
        return;
    }
    int freq[26]={0};
    int odd_freq=0;
    int mid=-1;
    for(int i=0;i<n;i++){
        freq[s[i]-'A']++;
    }
    for(int i=0;i<26;i++){
            if(freq[i]%2){
                mid=i;
                odd_freq++;
            }
    }
    if((n%2==0 && odd_freq>0) || (n%2 && odd_freq>1)){
        cout<<"NO SOLUTION"<<'\n';
    }else{
        CHARSTACK stk;
        for(int i=0;i<26;i++){
            int cnt=freq[i]/2;
            char ch=map[i];
            while(ch!=map[mid] && cnt>0){
                stk.push(ch);
                freq[i]--;
                cnt--;
            }
        }
        if(mid!=-1){
            while(freq[mid]>0){
                stk.push(map[mid]);
                freq[mid]--;
            }
        }
        for(int i=25;i>=0;i--){
            char ch=map[i];
            while(freq[i]>0){
                stk.push(ch);
                freq[i]--;
            }
        }
        string ans;
        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }
        cout<<ans<<'\n';
    }   
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    solve();
}