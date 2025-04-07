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

const int MAX = 2e5+1;
ll N, Q;
vector<ll> adj[MAX];
ll depth[MAX], P[21][1<<21];
ll sub[MAX], dp[MAX];

void dfs(int here, int parent){
    depth[here] = depth[parent]+1;
    P[0][here] = parent;
    sub[here] = 1;
    ll r = 0;
    for(int next : adj[here]){
        if(next==parent) continue;
        dfs(next, here);
        sub[here] += sub[next];
        dp[here] += r * sub[next];
        r += sub[next];
    }
    dp[here] += r ;
}

void setFP(){
    for(int j=1;j<21;j++){
        for(int i=1;i<=N;i++){
            P[j][i] = P[j-1][P[j-1][i]];
        }
    }
}

ll LCA(int u, int v){
    if(depth[u]>depth[v]) swap(u, v);
    int dh = depth[v]-depth[u];

    for(int j=20;j>=0;j--) if((1<<j)&dh){
        v = P[j][v];
    }

    for(int j=20;j>=0;j--) if(P[j][u]!=P[j][v]){
        u = P[j][u];
        v = P[j][v];
    }

    if(u!=v) u = P[0][u];
    return u;
}

ll LCA2(int u, int v){
    if(depth[u]>depth[v]) swap(u, v);
    int dh = depth[v]-depth[u] - 1;

    for(int j=20;j>=0;j--) if((1<<j)&dh){
        v = P[j][v];
    }

    return v;
}


int main(){
    fast_io
    cin >> N >> Q;
    for(int i=1;i<N;i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll rt = 1;
    dfs(rt, rt);
    setFP();
    while(Q--){
        int op, x;
        cin >> op >> x;
        if(op == 1){
            rt = x;
        }else{
            int lca = LCA(rt, x);
            if(rt == x){
                cout << dp[x] + sub[x] * (N - sub[x]) << '\n';
            }else if(lca == x){ 
                ll y = LCA2(rt, x);
                cout << dp[x] - sub[y] * (N - sub[y]) + sub[x] * (N - sub[x]) << '\n';
            }else{
                cout << dp[x] << '\n';
            }
        }
    }
}