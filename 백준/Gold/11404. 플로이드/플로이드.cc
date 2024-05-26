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
    static const int V_MAX = 1e2+1;
    static const T INF = 1e9+1;
    int V, E;
    // 인접리스트
    // vector<pair<T, T> > adj[V_MAX];
    // 인접행렬
    T adj[V_MAX][V_MAX];

    void init_edge(){
        for(int i=1;i<=V;i++){
            for(int j=1;j<=V;j++){
                if(i == j) adj[i][j] = 0;
                else adj[i][j] = INF;
            }
        }
    }

    void addEdge(T u, T v, T w){
        //인접 행렬이니까
        adj[u][v] = min(adj[u][v], w);
        // adj[v][u] = min(adj[v][u], w);
    }
    
    // 플로이드 와샬
    void floyd(){
        for(int drop_by = 1;drop_by<=V;drop_by++){
            for(int i=1;i<=V;i++){
                for(int j=1;j<=V;j++){
                    // drop_by를 들러서 가는게 이득이면 relax
                    adj[i][j] = min(adj[i][j], adj[i][drop_by] + adj[drop_by][j]);
                }
            }
        }
    }

    void print_adj(){
        for(int i=1;i<=V;i++){
            for(int j=1;j<=V;j++){
                if(adj[i][j] == INF) cout << "0 ";
                else cout << adj[i][j] << ' ';
            }
            cout << '\n';
        }
    }
};

myGraph<int> G;

int main(){
    fast_io
    cin >> G.V >> G.E;
    G.init_edge();
    for(int i=0;i<G.E;i++){
        int u, v, w; cin >> u >> v >> w;
        G.addEdge(u, v, w);
    }
    G.floyd();
    G.print_adj();
}