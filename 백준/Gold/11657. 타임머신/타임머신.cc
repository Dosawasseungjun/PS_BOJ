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
        // adj[v].push_back({u, w});
    }
    
    // bellmanFord
    vector<T> BellmanFord(int src){
        vector<T> upper(V+1, INF);
        upper[src] = 0;
        bool is_relax= false; // V번의 반복 이후 relax 되는가?
        // V번의 반복
        for(int iter = 1; iter <= V ; iter++){
            is_relax = false;
            for(int u = 1; u <= V ; u++){
                for(auto [v , w] : adj[u]){
                    if(upper[u] == INF) continue;

                    if(upper[v] > upper[u] + w){ // relax됨
                        upper[v] = upper[u] + w;
                        is_relax = true;
                    }
                }
            }
            // relax안되었으면 음수 사이클 없는 거임
            if(!is_relax) break;
        }
        // V+1반복 후에 relax되었으면 음수사이클 있는 거임
        if(is_relax) upper.clear();
        return upper;
    }
};

myGraph<ll> G;

int main(){
    fast_io
    cin >> G.V >> G.E;
    for(int i=0;i<G.E;i++){
        int u, v, w; cin >> u >> v >> w;
        G.addEdge(u, v, w);
    }
    vector<ll> ans = G.BellmanFord(1);
    if(ans.empty()) cout << "-1\n";
    else{
        for(int i=2;i<=G.V;i++){
            cout << ((ans[i] != G.INF) ? ans[i] : -1)<< '\n';
        }
    }
}