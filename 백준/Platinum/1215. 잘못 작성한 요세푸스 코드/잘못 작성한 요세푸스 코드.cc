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


int main(){
    fast_io
    ll n, k; cin >> n >> k;
    ll res = 0;
    if(n > k){
        res += k*(n-k);
    }
    ll m = min(k, n) * k;
    for(ll i=1;i*i <= k && i <= n; i++){
        m -= i * (k / i);
        if(k / i == i) continue;

        ll l = (k / (i+1)) + 1;
        ll r = (k / i);
        if(l > n) continue;
        r = min(r, n);
        if(r < l) continue;
        m -= (l + r) * (r - l + 1) / 2 * i;
    }
    res += m;
    cout << res;
}