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

const ll INF = 1e15;

struct Dinic{
    struct Edge{
        int to;
        ll cap;
        int rev;
    };

    int N;
    vector<vector<Edge>> G;
    vector<int> level, it;

    Dinic(int n) : N(n), G(n), level(n), it(n) {}

    void addEdge(int u, int v, ll cap = INF){
        G[u].push_back({v, cap, (int)G[v].size()});
        G[v].push_back({u, 0, (int)G[u].size()-1});
    }

    bool bfs(int s, int t){
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(auto &e : G[u]){
                if(e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return (level[t] >= 0);
    }

    ll dfs(int u, int t, ll f){
        if(u == t) return f;
        for(int &i = it[u]; i < (int)G[u].size();i++){
            auto &e = G[u][i];
            if(e.cap > 0 && level[e.to] == level[u] + 1){
                ll ret = dfs(e.to, t, min(f, e.cap));
                if(ret > 0){
                    e.cap -= ret;
                    G[e.to][e.rev].cap += ret;
                    return ret;
                }
            }
        }
        return 0;
    }

    ll maxFlow(int s, int t){
        ll flow = 0;
        while(bfs(s, t)){
            fill(it.begin(), it.end(), 0);
            while(1){
                ll f = dfs(s, t, INF);
                if(f == 0) break;
                flow += f;
            }
        }
        return flow;
    }
};

int main(){
    fast_io
    int n; cin >> n;
    vector<int> a(n+1);
    Dinic dinic(n+2); // S = 0, T = n+1
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        if(a[i] == 1){
            dinic.addEdge(0, i);
        }else if(a[i] == 2){
            dinic.addEdge(i, n+1);
        }
    }
    
    vector w = vector(n+1, vector<ll> (n+1, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> w[i][j];
            if(i != j) dinic.addEdge(i, j, w[i][j]);
        }
    }
 
    cout << dinic.maxFlow(0, n+1) << '\n';
    queue<int> q; q.push(0);
    vector<int> vst(n+2); vst[0] = 1;
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(auto &nxt : dinic.G[now]){
            if(vst[nxt.to]) continue;
            if(nxt.cap > 0){
                q.push(nxt.to); 
                vst[nxt.to] = 1;
            }
        }
    }
    vector<int> A, B;
    for(int i=1;i<=n;i++){
        if(vst[i]) A.push_back(i);
        else B.push_back(i);
    }
    for(int aa : A) cout << aa << ' ';
    cout << '\n';
    for(int bb : B) cout << bb << ' ';
    cout << '\n';
}