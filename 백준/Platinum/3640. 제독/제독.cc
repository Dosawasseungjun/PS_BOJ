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
    fast_io
    int v, e;
    while(cin >> v >> e){
        MinCost_MaxFlow<int> flo(2 * v+2);
        flo.add_edge(0, 1, 2, 0);
        for(int i=1;i<=v;i++) { // 정점 분리과정
            if(i != 1 && i != v) flo.add_edge(i, i + v, 1, 0); 
            else flo.add_edge(i, i + v, 2, 0);
        }
        flo.add_edge(2*v, 2*v +1, 2, 0);
        for(int i=0;i<e;i++){
            int a, b, c;
            cin >> a >> b >> c;
            flo.add_edge(a + v, b, 1, c);
        }
        cout << flo.mcmf(0, 2 * v + 1).xx << '\n';
    }
}