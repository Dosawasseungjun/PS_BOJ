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

const int V_MAX = 1e2 + 1;
bool vst[V_MAX];
vector<int> adj[V_MAX];
int V, E;

void dfs(int here){
    vst[here] = true;
    for (int nxt : adj[here]){
        if (vst[nxt])
            continue;
        dfs(nxt);
    }
}

int main(){
    fast_io
    cin >> V >> E;
    for(int i=0;i<E;i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout << count(vst, vst + V_MAX, 1) - 1;
}