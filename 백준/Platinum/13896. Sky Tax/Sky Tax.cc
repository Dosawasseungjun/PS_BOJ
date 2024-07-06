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

int N, Q, R;
vector<vector<int>> G, par;
vector<int> sub_tree, dep;

void dfs(int here, int parent, int d){
    dep[here] = d;
    par[0][here] = parent;
    sub_tree[here] = 1;
    for(int nxt : G[here]){
        if(nxt == parent) continue;
        dfs(nxt, here, d + 1);
        sub_tree[here] += sub_tree[nxt];
    }
}

int LCA(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    int diff = dep[u] - dep[v];

    for(int i=0;i<18;i++) if(diff & (1 << i)){
        u = par[i][u];
    }
    if(u == v) return u;
    for(int i=17;i>=0;i--) if(par[i][u] != par[i][v]){
        u = par[i][u];
        v = par[i][v];
    }
    if(u != v) u = par[0][u];
    return u;
}

void solv(int case_num){
    cin >> N >> Q >> R;
    G = vector(N+1, vector<int>());
    par = vector(18, vector<int>(N+1, 0));
    sub_tree = vector(N+1, 0);
    dep = vector(N+1, 0);
    for(int i=1;i<N;i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 1, 1);
    for(int j=1;j<18;j++){
        for(int i=1;i<=N;i++){
            par[j][i] = par[j-1][par[j-1][i]];
        }
    }

    cout << "Case #" << case_num << ":\n";
    while(Q--){
        int op, u;
        cin >> op >> u;
        if(op){
            if(R == u){
                cout << N << '\n';
                continue;
            }
            int lca = LCA(u, R);
            if(lca == u){
                int diff = dep[R] - dep[u] - 1;
                int node = R; 
                for(int i=0;i<18;i++) if(diff & (1 << i)){
                    node = par[i][node];
                }
                cout << N - sub_tree[node] << '\n';
            }else{ // u의 서브트리 부분만
                cout << sub_tree[u] << '\n';
            }
        }else{
            R = u;
        }
    }
    
}

int main(){
    fast_io
    int tt; cin >> tt;
    int ori = tt;
    while(tt--) solv(ori - tt);
}