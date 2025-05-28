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

const int V_MAX = 1e5+1;
int N, C[V_MAX][2], ans, dp[V_MAX][2]; 
vector<int> G[V_MAX];

void dfs(int here, int parent){
    int as = 0, bs = 0;
    for(int nxt : G[here]) if(nxt != parent){
        dfs(nxt, here);
        as += dp[nxt][0];
        bs += dp[nxt][1];
    }
    if(C[here][0] > C[here][1]){
        dp[here][0] = as;
        dp[here][1] = as + 1;
    }else if(C[here][0] < C[here][1]){
        dp[here][0] = bs + 1;
        dp[here][1] = bs;
    }else{
        dp[here][0] = min(as, bs + 1);
        dp[here][1] = min(as + 1, bs);
    }
}

int main(){
    fast_io
    cin >> N;
    for(int i=1;i<=N;i++) cin >> C[i][0];
    for(int i=1;i<=N;i++) cin >> C[i][1];
    for(int i=1;i<=N;i++) {
        ans += max(C[i][0], C[i][1]);
        dp[i][0] = dp[i][1] = 1e9;
    }
    
    for(int i=1;i<N;i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 1);
    cout << ans << ' ' << dp[1][0];
}