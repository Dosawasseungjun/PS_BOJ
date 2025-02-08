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

struct DisjointSet{
    vector<ll> parent, sz;
    
    DisjointSet(int n):parent(n+1),sz(n+1, 1){
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    
    int find(int u){
        if(u==parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u==v) return;
        
        if(sz[u]>sz[v]) swap(u, v);
        parent[u] = v;
        sz[v] += sz[u];
        sz[u] = 1; //1로 다시 돌아가도 계산상 문제 없음
    }
};

int main(){
    fast_io
    int N; cin >> N;
    vector G = vector(N+1, vector<int>());
    for(int i=1;i<N;i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> par(N+1, 0);
    function<void(int, int)> dfs; // 먼저 dfs를 선언
    dfs = [&](int here, int parent) {
        for (int nxt : G[here]) {
            if (nxt == parent) continue;
            par[nxt] = here;
            dfs(nxt, here);  // 이제 이미 선언된 dfs를 호출하므로 문제 없음
        }
    };

    vector<int> used(N+1, 0);
    DisjointSet dsu(N);
    dfs(1, 1);
    int Q; cin >> Q;
    while(Q--){
        ll res = 0;
        int k; cin >> k;
        vector<int> K(k);
        for(int &x : K) cin >> x, used[x] = 1;
        
        for(int x : K){
            if(used[x] && used[par[x]]) dsu.merge(x, par[x]);
        }
        for(int x : K){
            res += dsu.sz[x] * (dsu.sz[x]-1) / 2;
        }
        for(int x : K){
            used[x] = 0;
            dsu.parent[x] = x;
            dsu.sz[x] = 1;
        }
        cout << res << '\n';
    }
}