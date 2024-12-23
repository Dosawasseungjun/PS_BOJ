#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;

const int MAX = 2e5+1;
int n, m, q;
vector<int> adj[MAX];
int depth[MAX], fastPar[19][1<<19], V[MAX][2];

struct DisjointSet{
    vector<int> parent, rank;
    DisjointSet(int n) : parent(2*n+1), rank(2*n+1, 1){
        for(int i=1;i<=2*n;i++) parent[i] = i;
    }
    int find(int u){
        if(u==parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    void merge(int u, int v){
        u = find(u); v = find(v);
        if(u==v){
            return;
        }
        adj[++n].push_back(u);
        adj[n].push_back(v);
        if(rank[u]>rank[v]) swap(u, v);
        parent[u] = n;
        parent[v] = n;
        rank[n] = rank[u]+rank[v];
    }
};

void dfs(int here, int parent){
    depth[here] = depth[parent]+1;
    fastPar[0][here] = parent;
    for(int next : adj[here]){
        if(next==parent) continue;
        dfs(next, here);
    }
}

void setFP(){
    for(int i=1;i<19;i++){
        for(int j=1;j<=n;j++){
            fastPar[i][j] = fastPar[i-1][fastPar[i-1][j]];
        }
    }
}

int LCA(int u, int v){
    if(depth[u]>depth[v]) swap(u, v);
    int diff = depth[v]-depth[u];
    for(int i=18;i>=0;i--) if((1<<i)&diff){
        v = fastPar[i][v];
    }
    for(int i=18;i>=0;i--) if(fastPar[i][u]!=fastPar[i][v]){
        u = fastPar[i][u];
        v = fastPar[i][v];
    }
    return fastPar[0][u];
}

int main(){
    fast_io
    cin >> n >> m;
    vector<tiii> E;
    for(int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        E.push_back(make_tuple(w, u, v));
    }
    sort(E.begin(), E.end());
    DisjointSet uf(n);
    for(auto [w, u, v] : E){
        int a = uf.find(u);
        int b = uf.find(v);
        if(a==b) continue;
        uf.merge(u, v);
        V[uf.find(u)][0] = w;
        V[uf.find(u)][1] = uf.rank[uf.find(u)];
    }
    for(int i=1;i<=n;i++) if(uf.parent[i]==i) dfs(i, i);
    setFP();
    cin >> q;
    for(int i=0;i<q;i++){
        int x, y; cin >> x >> y;
        if(uf.find(x)!=uf.find(y)){
            cout << -1 << '\n';
        }else{
            int lca = LCA(x, y);
            cout << V[lca][0] << ' ' << V[lca][1] << '\n';
        }
    }
}
