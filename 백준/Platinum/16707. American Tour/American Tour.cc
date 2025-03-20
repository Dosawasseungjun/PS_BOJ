#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define xx first
#define yy second

template <class T> struct MinCost_MaxFlow{
    int n;
    struct edge{
        int to, rev;
        T cap, cost;
    };
    vector<vector<edge>> g;  //잔여그래프의 인접리스트
    vector<pii> pos;        //원래방향 간선
    vector<T> dist;         // 최단경로 (최소비용)
    vector<int> pa, pe;      //이전의 정점 번호와 간선번호
    vector<bool> inQ;       // 지금 큐 안에 있는가
    
    MinCost_MaxFlow(int N) : n(N), g(N), dist(N, 0), pa(N), pe(N), inQ(N, false){}

    void clear(){
        for(int i=0;i<n;i++) g[i].clear();
    }
    
    int add_edge(int u, int v, T cap, T cost){
        int u_idx = (int)g[u].size();
        int v_idx = (int)g[v].size();
        if(u==v) v_idx++;
        pos.emplace_back(u, u_idx);
        g[u].emplace_back(edge{v, v_idx, cap, cost});
        g[v].emplace_back(edge{u, u_idx, (T)0, -cost});
        return (int)pos.size()-1;
    }

    bool spfa(int s, int t){
        dist = vector<T> (n, numeric_limits<T>::max());
        inQ = vector<bool> (n, false);
        queue<int> Q;
        dist[s] = 0;
        inQ[s] = 1;
        Q.push(s);
        bool ok = 0;
        while(!Q.empty()){
            int now = Q.front();
            Q.pop();
            if(now == t) ok = true;
            inQ[now] = 0;
            for(int i=0;i<g[now].size();i++){
                edge e = g[now][i];
                if(e.cap > 0 && dist[e.to] > dist[now] + e.cost){
                    dist[e.to] = dist[now] + e.cost;
                    pa[e.to] = now;
                    pe[e.to] = i;
                    if(!inQ[e.to]){
                        inQ[e.to] = true;
                        Q.push(e.to);
                    }
                }
            }
        }
        return ok;
    }
    
    pair<T, T> mcmf(int s, int t){
        T min_cost = 0, max_flow = 0;
        while(spfa(s, t)){
            T cap = numeric_limits<T>::max();
            for(int pos = t; pos != s; pos = pa[pos]){
                cap = min(cap, g[pa[pos]][pe[pos]].cap);
            }
            min_cost += dist[t] * cap;
            max_flow += cap;
            for(int pos = t; pos != s; pos = pa[pos]){
                int rev = g[pa[pos]][pe[pos]].rev;
                g[pa[pos]][pe[pos]].cap -= cap;
                g[pos][rev].cap += cap;
            }
        }
        return {min_cost, max_flow};
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    MinCost_MaxFlow<ll> G(N+2);
    G.add_edge(0, 1, 1, 0);
    G.add_edge(N+1, N, 1, 0);
    for(int i=0;i<M;i++){
        ll s, e, d; cin >> s >> e >> d;
        G.add_edge(s, e, 1, d);
        G.add_edge(e, s, 1, d);
    }
    auto [mc, mf] = G.mcmf(0, 2);
    auto [mc1, mf1] = G.mcmf(N+1, 2);
    cout << mc + mc1;
}