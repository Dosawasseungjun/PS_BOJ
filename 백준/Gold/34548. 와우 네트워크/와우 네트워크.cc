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

struct DSU{
    vector<int> parent, rank;

    DSU(int n) : parent(n+1, 0), rank(n+1, 0){
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u){
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    bool merge(int u, int v){
        u = find(u); v = find(v);
        if(u == v) return false;

        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u] == rank[v]) rank[v]++;
        return true;
    }
};

int main(){
    fast_io
    int N, M, T; cin >> N >> M >> T; 
    vector<tlll> Edges(M);
    for(int i=0;i<M;i++){
        ll u, v, t; cin >> u >> v >> t;
        Edges[i] = {t, u, v};
    }
    Edges.emplace_back(T+1, 1, 1);
    sort(Edges.begin(), Edges.end());
    DSU dsu(N);
    ll pre = 1;
    ll cnt = N;
    ll res = 0;
    for(int i=0, j=0;i<M+1;i = j){
        auto [t, u, v] = Edges[i];
        res += (t - pre) * cnt;
        j = i+1;
        while(j < M && get<0>(Edges[j]) == t)  j++;
        for(int k=i;k<j;k++){
            auto [tt, uu, vv] = Edges[k];
            if(dsu.merge(uu, vv)){
                cnt -= 1;
            }
        }
        
        pre = t;
    }
    cout << res;
}