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
    vector<int> parent, sz;
    
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
        
        parent[u] = v;
        sz[v] += sz[u];
        sz[u] = 0;
    }
};

int main(){
    fast_io
    int n; cin >> n;
    vector<set<int>> a;
    a.emplace_back();
    map<pii, int> mp;
    DisjointSet dsu(n);
    int pre = -1;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        if(x > pre){
            a.back().insert(x);
            if(x == pre + 1) dsu.merge(i, i-1);
        }else{
            a.emplace_back().insert(x);
        }
        mp[{a.size(), x}] = i;
        pre = x;
    }
    for(int i=1;i<a.size();i++){
        for(int x : a[i]){
            if(a[i-1].count(x)){
                dsu.merge(mp[{i, x}], mp[{i+1, x}]);
            }
        }
    }
    set<int> res;
    for(int i=0;i<n;i++) res.insert(dsu.find(i));

    cout << res.size() << '\n';
    cout << n;
}