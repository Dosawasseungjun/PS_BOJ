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
    string s; cin >> s;
    vector<int> fe;
    fe.push_back(-1);
    int f = 0;
    int f_cnt = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] == 'f'){
            f_cnt++;
            f++;
        }else{
            fe.push_back(f);
            f = 0;
        }
    }
    int  n = fe.size()-1;
    vector dp = vector(n+1, vector<ll>(f_cnt+2, 0));
    dp[1][fe[1]] = 1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=f_cnt;j++){
            if(dp[i-1][j]){
                dp[i][fe[i]] += dp[i-1][j];
                dp[i][fe[i]] = (dp[i][fe[i]] % MOD + MOD) % MOD;
                dp[i][fe[i] + j + 1] -= dp[i-1][j];
                dp[i][fe[i] + j + 1] = (dp[i][fe[i] + j + 1] % MOD + MOD) % MOD;
            }
        }
        for(int j=1;j<=f_cnt;j++){
            dp[i][j] += dp[i][j-1];
            dp[i][j] %= MOD;
        }
    }
    ll res = 0;
    for(int j=0;j<=f_cnt;j++){
        res += dp[n][j];
        res %= MOD;
    }
    cout << res;
}