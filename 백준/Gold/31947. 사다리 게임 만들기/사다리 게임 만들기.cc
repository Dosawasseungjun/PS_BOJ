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

double dp[505][10005];

int main(){
    fast_io
    cout << fixed;
    cout.precision(15);
    int N, M; cin >> N >> M;
    int S, E; cin >> S >> E;
    if (N == 2){
        if(S == E){
            if(M & 1) cout << 0;
            else cout << 1;
        }else{
            if(M & 1) cout << 1;
            else cout << 0;
        }
        return 0;
    }
    dp[S][0] = 1.0;
    for(int j=1;j<=M;j++){
        for(int i=1;i<=N;i++){
            if(i!=1 && i!=N) dp[i][j] = (dp[i-1][j-1] + dp[i+1][j-1] + dp[i][j-1] * (N-3));
            else if(i == 1) dp[i][j] = (dp[i+1][j-1] + dp[i][j-1] * (N-2));
            else dp[i][j] = (dp[i-1][j-1] + dp[i][j-1] * (N-2));
            dp[i][j] /= N-1;
        }
    }
    cout << dp[E][M];
}