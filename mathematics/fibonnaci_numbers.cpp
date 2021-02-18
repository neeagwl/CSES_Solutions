#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define mem(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define INF (int)1e9
#define EPS 1e-9
#define mod 1000000007

typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef unordered_map<int, int> umii;
typedef map<int, int> mii;
typedef unordered_set<int> usi;
typedef set<int> seti;
//=======================

ll inverse(ll i)
{
    if (i == 1)
        return 1;
    return (mod - ((mod / i) * inverse(mod % i)) % mod + mod) % mod;
}
ll POW(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % mod;
    ll temp = POW(a, b / 2);
    if (b % 2 == 0)
        return (temp * temp) % mod;
    else
        return (((temp * temp) % mod) * a) % mod;
}
map<ll, ll> f;

ll fib(ll n)
{
    if (f.count(n))
        return f[n];
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    if (n % 2 == 0)
    {
        ll k = n / 2;
        ll x1 = fib(k - 1), x2 = fib(k);
        return f[n] = ((((2ll * x1) % mod + x2) % mod) * x2) % mod;
    }
    else
    {
        ll k = (n + 1) / 2;
        ll x1 = fib(k - 1), x2 = fib(k);
        return f[n] = ((x1 * x1) % mod + (x2 * x2) % mod) % mod;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    cout << fib(n);
}
