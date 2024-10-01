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

const ll mod = 1e9+7;

int main(){
    fast_io
    ll N; cin >> N;
    vector<ll> A(N+1), fac(N+1);
    vector dp = vector(101, vector(101, vector<ll>(2001, 0)));
    fac[0] = 1;
    ll S = 0;
    for(ll i=1;i<=N;i++){
        cin >> A[i];
        S += A[i];
        fac[i] = fac[i-1] * i % mod;
    }
    if(S & 1){
        cout << 0;
    }else{
        dp[0][0][0] = 1;
        for(int i=1;i<=N;i++){
            for(int j=i-1;j>=0;j--){
                for(int k=2000;k>=0;k--){
                    if(dp[i-1][j][k]){
                        dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k]) % mod;
                        dp[i][j + 1][k + A[i]] = (dp[i][j + 1][k + A[i]] + dp[i - 1][j][k]) % mod;
                    }
                }
            }
        }
        ll res = 0;
        for(int j=0;j<=N;j++){
            if(dp[N][j][S/2]){
                res += dp[N][j][S / 2] * fac[j] % mod * fac[N - j] % mod;
                res %= mod;
            }
        }
        cout << res;
    }
    
}