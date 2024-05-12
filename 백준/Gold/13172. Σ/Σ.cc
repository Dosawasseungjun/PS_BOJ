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

tuple<ll, ll, ll> xGCD(ll a, ll b)
{
    if (!b)
        return make_tuple(a, 1, 0);
    ll g, x, y;
    std::tie(g, x, y) = xGCD(b, a % b);
    return make_tuple(g, y, x - (a / b) * y);
}

const ll MOD = 1e9+7;

int main(){
    fast_io
    int m; cin >> m;
    ll res = 0;
    for(int i=0;i<m;i++){
        int n, s; cin >> n >> s;
        auto [g, x, y] = xGCD(MOD, n);
        y = (y % MOD + MOD) % MOD;
        res += s * y;
        res %= MOD;
    }
    cout << res;

}