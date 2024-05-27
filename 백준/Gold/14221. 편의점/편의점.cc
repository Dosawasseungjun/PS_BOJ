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

template <class T>
struct myGraph{
    static const int V_MAX = 5e3+1;
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
                    pq.push({dist[nxt], nxt});
                }
            }
        }
        return dist;
    }
};

myGraph<int> G;

int main(){
    fast_io
    cin >> G.V >> G.E;
    for(int i=0;i<G.E;i++){
        int u, v, w; cin >> u >> v >> w;
        G.addEdge(u, v, w);
    }
    
    int p, q; cin >> p >> q;
    vector<int> P;
    for(int i=0;i<p;i++){
        int x; cin >> x;
        P.push_back(x);
    }
    sort(P.begin(), P.end());
    for(int i=0;i<q;i++){
        int x; cin >> x;
        // q개의 편의점에서 동시에 시작
        G.adj[0].push_back({x, 0});
    }
    
    vector<int> D = G.dijkstra(0);
    int mn = 1e9+1;
    int ans = 0;
    for(int pp : P){
        if(mn > D[pp]){
            mn = D[pp];
            ans = pp;
        }
    }
    cout << ans ;
}