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
    int n; cin >> n;
    vector dp = vector(n+1, vector(10, vector<ll>(5, 0)));
    vector<pii> inc_k = {{0, 1}, {1, 2}, {3, 1}, {4, 1}};
    vector<pii> dec_k = {{0, 3}, {1, 3}, {3, 4}, {2, 3}};
    for(int i=0;i<10;i++) dp[1][i][0] = 1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<10;j++){
            if(j){
                for(auto [ori_k, nxt_k] : inc_k){
                    dp[i][j][nxt_k] += dp[i-1][j-1][ori_k];
                    dp[i][j][nxt_k] %= MOD;
                }
            }

            if(j+1<=9){
                for(auto [ori_k, nxt_k] : dec_k){
                    dp[i][j][nxt_k] += dp[i-1][j+1][ori_k];
                    dp[i][j][nxt_k] %= MOD;
                }
            }
        }
    }

    ll res = 0;
    for(int j=0;j<10;j++){
        for(int k=0;k<5;k++){
            res += dp[n][j][k];
            res %= MOD;
        }
    }
    cout << res;
}