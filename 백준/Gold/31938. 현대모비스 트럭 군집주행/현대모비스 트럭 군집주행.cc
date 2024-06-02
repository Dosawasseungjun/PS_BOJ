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

pll P[200001];

template <class T>
struct myGraph{
    static const int V_MAX = 2e5+1;
    const T INF = numeric_limits<T>().max();
    
    int V, E;
    // 인접리스트
    vector<pair<T, T> > adj[V_MAX];

    inline void addEdge(T u, T v, T w){
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    // 다익스트라
    vector<T> dijkstra(int src){
        vector<T> dist(V+1, INF);
        dist[src] = 0;

        priority_queue<pair<T, T>, vector<pair<T, T>>, greater<pair<T, T>>> pq;
        pq.push({dist[src], src});

        while(!pq.empty()){
            auto [cost, here] = pq.top();
            pq.pop();

            if(dist[here] < cost) continue;
            for(auto [nxt, w] : adj[here]){
                if(dist[nxt] > cost + w){
                    dist[nxt] = cost + w;
                    P[nxt] = {w, here};
                    pq.push({dist[nxt], nxt});
                }else if(dist[nxt] == cost + w){
                    if(P[nxt].xx > w){
                        P[nxt] = {w, here};
                    }
                }
            }
        }
        return dist;
    }
};

myGraph<ll> G1;
vector<int> G[200001];
int dp[200001];
ll res = 0;

void dfs(int here, int par){
    dp[here] = 1;
    for(int nxt : G[here]) if(nxt != par){
        dfs(nxt, here);
        dp[here] += dp[nxt];
    }
}

void dfs2(int here, int par){
    for(int nxt : G[here]) if(nxt != par){
        res += P[nxt].xx + (dp[nxt] -1) * P[nxt].xx * 9 / 10;
        dfs2(nxt, here);
    }
}

int main(){
    fast_io
    cin >> G1.V >> G1.E;
    for(int i=0;i<G1.E;i++){
        int u, v, w; cin >> u >> v >> w;
        G1.addEdge(u, v, w);
    }
    vector<ll> D = G1.dijkstra(1);

    for(int i=2;i<=G1.V;i++){
        G[P[i].yy].push_back(i);
    }
    dfs(1, 1);
    dfs2(1, 1);
    cout << res;
}