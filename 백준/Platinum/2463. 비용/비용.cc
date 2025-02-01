#include <bits/stdc++.h>
using namespace std;
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlll;
#define xx first
#define yy second

const ll MOD = 1e9;

struct DisjointSet{
    vector<ll> parent, sz;
    DisjointSet(int n) : parent(n+1), sz(n+1){
        for(int i=1;i<=n;i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }

    ll find(ll u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    ll merge(ll u, ll v, ll w){
        u = find(u);
        v = find(v);
        if(u == v) return 0;

        ll oriu = sz[u], oriv = sz[v];
        if(sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
        sz[v] = 0;
        return oriu * oriv;
    }
};

int main(){
    fast_io
    int N, M; cin >> N >> M;
    vector G = vector(N+1, vector<pll>());
    vector<tlll> E(M);
    ll Esum = 0;
    for(int i=0;i<M;i++){
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
        E[i] = {w, u, v};
        Esum += w;
    }
    sort(E.begin(), E.end(), [&](const tiii & a, const tiii & b){
        auto [p, q, r] = a;
        auto [x, y, z] = b;
        return p > x;
    });
    DisjointSet dsu(N);
    ll res = 0;
    for(int i=0;i<M;i++){
        auto [w, u, v] = E[i];
        ll k = dsu.merge(u, v, w);
        res += k * (Esum);
        res %= MOD;
        Esum -= w;
    }
    cout << res % MOD;
}