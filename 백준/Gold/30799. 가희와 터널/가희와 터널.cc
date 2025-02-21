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

const ll MOD = 998244353;

int main(){
    fast_io
    ll s; cin >> s;
    vector dp = vector(s+1, vector<ll>(8, 0));
    dp[0][0] = 1;
    for(int i=1;i<=s;i++){
        dp[i][0] = dp[i-1][0] * 6 % MOD;
        for(int j=1;j<=7;j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] * (j == 7 ? 7 : 6) % MOD) % MOD;
        }
    }
    cout << dp[s][7];
}