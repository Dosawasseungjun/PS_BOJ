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
    vector<int> parent, rank;
    
    DisjointSet(int n):parent(n+1),rank(n+1, 0){
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
        
        if(rank[u]>rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u]==rank[v]) rank[v]++;
    }
};

int main(){
    fast_io
    int N, M, K;
    cin >> N >> M >> K;
    vector<array<int, 2>> G, C;
    DisjointSet dsu1(N), dsu2(N);
    for(int i=0;i<M;i++){
        int u, v, c;
        cin >> u >> v >> c;
        if(c){
            C.push_back({u, v});
        }else{
            G.push_back({u, v});
        }
    }
    vector<tiii> ans;
    int cc = 0, gc = 0;
    for(auto [u, v] : C){ //콘크리트만 사용해서 
        int p = dsu1.find(u);
        int q = dsu1.find(v);
        if(p != q){
            dsu1.merge(p, q);
            cc++;
        }
    }
    for(auto [u, v] : G){ // 자갈을 사용
        int p = dsu1.find(u);
        int q = dsu1.find(v); 
        if(p != q){ //콘크리트로 연결 안되어있음 -> 무조건 써야하는 자갈길
            dsu1.merge(p, q);
            dsu2.merge(u, v);
            ans.push_back({u, v, 0});
            gc++;
        }
    }
    if(cc + gc != N-1 || gc > K){
        // 스패닝트리가 만들어지지 않거나 자갈을 투머치하게 사용해야만 한다면
        cout << "no solution";
        return 0;
    }
    
    for(auto [u, v] : G){ //k개까지 자갈 사용
        if(gc == K) break;
        int p = dsu2.find(u);
        int q = dsu2.find(v);
        if(p != q){
            dsu2.merge(u, v);
            ans.push_back({u, v, 0});
            gc++;
        }
    }

    for(auto [u, v] : C){ // 남은 자리 콘크리트로 채우기
        int p = dsu2.find(u);
        int q = dsu2.find(v);
        if(p != q){
            dsu2.merge(u, v);
            ans.push_back({u, v, 1});
            cc++;
        }
    }

    if(ans.size() != N-1 || gc != K){
        cout << "no solution";
    }else{
        for(auto [u, v, c] : ans){
            cout << u << ' ' <<  v << ' ' << c << '\n';
        }
    }
}