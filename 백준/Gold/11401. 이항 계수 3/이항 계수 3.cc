#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int > tiii;

const int MAX = 4e6+1;
const int MOD = 1e9+7;
ll fac[MAX];

ll fastMul(ll a, ll e){
    if(!e) return 1;
    if(e==1) return a%MOD;
    ll half = fastMul(a, e/2);
    ll ret = half*half%MOD;
    if(e&1) ret = (ret*a)%MOD;
    return ret;
}

int main(){
    fast_io
    fac[0] = 1;
    fac[1] = 1;
    for(int i=2;i<MAX;i++){
        fac[i] = (fac[i-1]*i)%MOD;
    }
    ll n, k; cin >> n >> k;
    ll res = (fac[n]*fastMul(fac[n-k]*fac[k]%MOD, MOD-2))%MOD;
    cout << res;
}
