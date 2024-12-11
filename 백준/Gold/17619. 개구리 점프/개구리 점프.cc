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
    DSU(int n) : parent(n+1), rank(n+1, 1){
        for(int i=1;i<=n;i++) parent[i] = i;
    }

    int find(int p){
        if(parent[p] == p) return p;
        return parent[p] = find(parent[p]);
    }

    void merge(int u, int v){
        u = find(u); v = find(v);
        if(u == v) return;

        if(rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if(rank[u] == rank[v]) rank[u]++;
    }
};

int main(){
    fast_io
    int N, Q; cin >> N >> Q;
    vector<pair<pii, pii>> X(N);
    for(int i=0;i<N;i++){
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        X[i] = {{x1, x2}, {y, i}};
    }
    DSU dsu(N);
    sort(X.begin(), X.end(), [](const pair<pii, pii> &a, const pair<pii, pii> &b){
        return a.xx.xx < b.xx.xx;
    });
    int mx = -1;
    int pre = 0;
    for(int i=0;i<N;i++){
        auto [x1, x2] = X[i].xx;
        auto [y, idx] = X[i].yy;
        if(mx < x1){
            mx = x2;
            pre = idx;
        }else{
            mx = max(mx, x2);
            dsu.merge(pre, idx);
        }
    }

    while(Q--){
        int u, v; cin >> u >> v;
        u--; v--;
        if(dsu.find(u) == dsu.find(v)) cout << "1\n";
        else cout << "0\n";
    }
}