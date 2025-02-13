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

const ll MOD = 1e9+7;

int main(){
    fast_io
    int mx_r = 500;
    int mx_a = mx_r*(mx_r+1)/2;
    vector dp = vector(mx_r+1, vector<ll>(mx_a+1, 0));
    dp[1][1] = dp[1][0] = 1;
    for(int r=2;r<=mx_r;r++){
        int c = r*(r+1)/2;
        for(int i=0;i<=c;i++){
            dp[r][i] = dp[r-1][i];
            if(i - r >= 0) dp[r][i] = (dp[r][i] + dp[r-1][i-r]) % MOD;
        }
    }
    vector ps = vector(mx_r+1, vector<ll>(mx_a+1, 0));
    for(int r=1;r<=mx_r;r++){
        for(int i=0;i<=mx_a;i++){
            ps[r][i] = (i == 0 ? 0 : ps[r][i-1]) + dp[r][i];
            ps[r][i] %= MOD;
        }
    }
    int tt; cin >> tt;
    while(tt--){
        ll a, b; cin >> a >> b;
        ll res = 0;
        for(int r = 1; r<=500;r++){
            ll c = r*(r+1)/2;
            ll la = max(0LL, c - b);
            ll ra = a;
            if(la > ra) continue;
            res += ps[r][ra] - (la ? ps[r][la-1] : 0);
            res = (res % MOD + MOD) % MOD;
        }
        cout << res <<'\n';
    }
}