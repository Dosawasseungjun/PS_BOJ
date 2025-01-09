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
    int N, M; cin >> N >> M;
    vector G = vector(N+1, vector<int>());
    vector R = vector(N+1, vector<int>());
    for(int i=0;i<M;i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        R[v].push_back(u);
    }
    vector<int> vst(N+1, 0);
    function<int(vector<vector<int>> &, int)> dfs = [&](vector<vector<int>> &adj, int here){
        int ret = 0;
        vst[here] = 1;
        for(int nxt : adj[here]){
            if(vst[nxt]) continue;
            ret += (1 + dfs(adj, nxt));
        }
        return ret;
    };
    int res = 0;
    for(int i=1;i<=N;i++){
        vst = vector<int> (N+1, 0);
        int x = dfs(G, i); // 작은거
        int y = dfs(R, i); // 큰거 
        if(x + y == N-1) res += 1;
    }
    cout << res;
}