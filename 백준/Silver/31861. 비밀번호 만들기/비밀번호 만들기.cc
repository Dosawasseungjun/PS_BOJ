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

const int MOD = 1e9+7;
int dp[1001][26];

int main(){
    fast_io
    int N, M; cin >> N >> M;
    for(int i=0;i<26;i++) dp[0][i] = 1;
    for(int i=1;i<M;i++){
        for(int j=0;j<26;j++){
            for(int k=0;k<26;k++){
                if(abs(j - k) >= N){
                    dp[i][j] += dp[i-1][k];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    int res = 0;
    for(int i=0;i<26;i++){
        res += dp[M-1][i];
        res %= MOD;
    }
    cout << res;
}