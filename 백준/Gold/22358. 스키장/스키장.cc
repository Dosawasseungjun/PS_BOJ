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

const int MAX = 1e5+1;
const ll INF = 1e15+1;
int N, M, K, S, T;
vector<pii> G[MAX], R[MAX];

int main(){
    fast_io
    cin >> N >> M >> K >> S >> T;
    vector<tiii> C(M+1);
    for(int i=1;i<=M;i++){
        int a, b, t;
        cin >> a >> b >> t;
        G[a].push_back({b, t});
        R[b].push_back({a, t});
    }
    vector dp(K+1, vector<ll>(N+1, -INF)); // k번 리프트를 탔고 n번째에 있을 때 최대 스키타는 시간
    dp[0][T] = 0;
    for(int k=0;k<=K;k++){
        for(int n=N;n>=1;n--){
            for(auto [down, t] : G[n]){
                if(dp[k][down] != -INF) dp[k][n] = max(dp[k][n], dp[k][down] + t);
            }
            
            if(k != 0){
                for(auto [up, t] : R[n]){
                    dp[k][n] = max(dp[k][n], dp[k-1][up]);
                }
            }
        }
    }
    ll res = -1;
    for(int i=0;i<=K;i++) res = max(res, dp[i][S]);
    cout << res;

}