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
    int N; cin >> N;
    const int MAX = 5e2+1;
    const int INF = 1e9+1;
    int A, B, K; cin >> A >> B >> K;
    int S = A + B;
    vector dp = vector(N+1, vector(S+1, vector<int>(S+1, -1)));
    dp[0][A][B] = 0;

    for(int i=1;i<=N;i++){
        for(int j=0;j<=S;j++){
            if(dp[i-1][j][S-j] != -1){
                for(int k=K;k<=S;k++){
                    if(j >= k) dp[i][j-k][S-j+k] = max(dp[i][j-k][S-j+k] , dp[i-1][j][S-j] + (j-k)*(S-j+k));
                    if(S-j >= k) dp[i][j+k][S-j-k] = max(dp[i][j+k][S-j-k] , dp[i-1][j][S-j] + (j+k)*(S-j-k));
                }
            }
        }
    }

    int res = 0;
    for(int i=0;i<=S;i++){
        res = max(res, dp[N][i][S-i]);
    }
    cout << res;
}