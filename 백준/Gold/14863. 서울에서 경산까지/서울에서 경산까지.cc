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
    int N, K; cin >> N >> K;
    vector<int> W(N+1), WM(N+1), B(N+1), BM(N+1);
    for(int i=1;i<=N;i++){
        cin >> W[i] >> WM[i] >> B[i] >> BM[i];
    }
    vector dp(N+1, vector<int>(K+1, -1));
    dp[0][0] = 0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=K;j++){
            if(dp[i-1][j] != -1){
                if(j + W[i] <= K) dp[i][j+W[i]] = max(dp[i][j+W[i]], dp[i-1][j] + WM[i]);
                if(j + B[i] <= K) dp[i][j+B[i]] = max(dp[i][j+B[i]], dp[i-1][j] + BM[i]);
            }
        }
    }
    int res = 0;
    for(int j=0;j<=K;j++) res = max(res, dp[N][j]);
    cout << res;
}