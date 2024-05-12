#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
#define xx first
#define yy second

ll fastmul(ll a, ll ex, ll mod){
    if(!ex) return 1;
    if(ex==1) return a % mod;
    if(ex & 1) return a * fastmul(a, ex-1, mod) % mod;
    ll half = fastmul(a, ex/2, mod);
    return half * half % mod;

}

int main(){
    fast_io
    ll m, seed, x1, x2; 
    cin >> m >> seed >> x1 >>x2;
    ll a = (x1 - x2) * fastmul(seed-x1, m-2, m) % m;
    if(a<0) a += m;
    ll c = (x1 - a*seed) % m;
    if(c < 0) c += m;
    cout << a << ' ' << c;
}