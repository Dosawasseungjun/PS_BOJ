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
    int n, m; cin >> n >> m;
    vector G = vector(n+1, vector<int>());
    vector R = vector(n+1, vector<int>());
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        R[v].push_back(u);
    }
    vector<int> vst(n+1, 0);
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
    for(int i=1;i<=n;i++){
        vst = vector<int> (n+1, 0);
        int p = dfs(G, i); //무거운거 수
        int q = dfs(R, i); //가벼운거 수
        if(p > n / 2 || q > n / 2) res++;
    }
    cout << res;
}