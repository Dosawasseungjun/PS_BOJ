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

const int V_MAX = 2e4+1;
vector<vector<int>> adj;
int vst[V_MAX][2];

void dfs(int here, int cnt){
    vst[here][cnt] = true;
    for(int nxt : adj[here]){
        if(vst[nxt][cnt ^ 1]) continue;
        dfs(nxt, cnt ^ 1);
    }
}

void dfsAll(int v){
    for(int i=1;i<=v;i++) if(!vst[i][0] && !vst[i][1]) dfs(i, 0);
}

void solv(){
    int v, e; cin >> v >> e;
    adj = vector(v+1, vector<int>());
    memset(vst, 0, sizeof(vst));
    for(int i=0;i<e;i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfsAll(v);
    bool isBipar = true;
    for(int i=1;i<=v;i++){
        if(vst[i][0] + vst[i][1] == 1) continue;
        isBipar = false;
    }
    if(isBipar) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}