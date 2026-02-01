#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlll;
#define xx first
#define yy second

const ll mod = 998244353;

ll fastex(ll a, ll e){
    if(!e) return 1;
    if(e==1) return a%mod;
    ll half = fastex(a, e/2);
    ll ret = half*half%mod;
    if(e&1) ret = (ret*a)%mod;
    return ret;
};

void solv(){
    ll N, L, R; cin >> N >> L >> R;
    ll S = (R-L+1);
    ll res = 0;
    if(S == 1) res = 1;
    else res = (fastex(S % mod, N) - 2*fastex((S-1)%mod, N)%mod + mod) % mod + fastex((S-2)%mod, N);
    res = (res+mod) % mod;
    cout << res << '\n';
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}