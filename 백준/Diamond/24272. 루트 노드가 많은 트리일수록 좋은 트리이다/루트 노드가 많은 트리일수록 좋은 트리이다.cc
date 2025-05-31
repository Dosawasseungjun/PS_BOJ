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

const int MAX = 1e5+1;

// 0이 아닌 원소의 개수를 구하는 세그먼트 트리
template <class T>
class RangeSegtree{
public:
    static const int TREESIZE = 4*MAX;
    T* tree = new T[TREESIZE];
    T* len = new T[TREESIZE];

    RangeSegtree(){
        for(int i=0;i<TREESIZE;i++) tree[i] = len[i] = 0;
    }
    ~RangeSegtree(){
        delete[] tree;
        delete[] len;
    }
    void update(T l,T r, T v, T node, T S, T E){
        if(E < l || S > r) return ;
        if(S >= l && E <= r){
            tree[node] += v;
        }else{
            int mid = (S + E) >> 1;
            update(l, r, v, 2*node, S, mid);
            update(l, r, v, 2*node+1, mid+1, E);
        }
        
        if(tree[node]) len[node] = E - S + 1;
        else if(S == E) len[node] = 0;
        else len[node] = len[2*node] + len[2*node+1];
    }
};


RangeSegtree<int> sgt;
vector<int> G[MAX];
vector<tuple<int, string, int>> Edge;
int in[MAX], out[MAX], cnt,dep[MAX];

void dfs(int here, int parent){
    dep[here] = dep[parent] + 1;
    in[here] = ++cnt;
    for(int nxt : G[here]){
        if(nxt == parent) continue;
        dfs(nxt, here);
    }
    out[here] = cnt;
}

int main(){
    fast_io
    int N; cin >> N;
    for(int i=1;i<N;i++){
        int u, v;
        string dir;
        cin >> u >> dir >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        Edge.push_back({u, dir, v});
    }
    dfs(1, 1);
    function<void(int, string, int)> add = [&](int u, string dir, int v){
        if(dir == "<-"){ // u 쪽애들이 불가능
            if(dep[u] > dep[v]){ // u가 v의 자식임
                sgt.update(in[u], out[u], 1, 1, 1, N);
            }else{
                if(in[v]-1 >= 1) sgt.update(1, in[v]-1, 1, 1, 1, N);
                if(out[v]+1 <= N) sgt.update(out[v]+1, N, 1, 1, 1, N);
            }
        }else if(dir == "->"){ // v쪽 애들이 불가능
            if(dep[v] > dep[u]){ // v가 u의 자식임
                sgt.update(in[v], out[v], 1, 1, 1, N);
            }else{
                if(in[u]-1 >= 1) sgt.update(1, in[u]-1, 1, 1, 1, N);
                if(out[u]+1 <= N) sgt.update(out[u]+1, N, 1, 1, 1, N);
            }
        }
    };
    function<void(int, string, int)> del = [&](int u, string dir, int v){
        if(dir == "<-"){ // u 쪽애들이 불가능
            if(dep[u] > dep[v]){ // u가 v의 자식임
                sgt.update(in[u], out[u], -1, 1, 1, N);
            }else{
                if(in[v]-1 >= 1) sgt.update(1, in[v]-1, -1, 1, 1, N);
                if(out[v]+1 <= N) sgt.update(out[v]+1, N, -1, 1, 1, N);
            }
        }else if(dir == "->"){ // v쪽 애들이 불가능
            if(dep[v] > dep[u]){ // v가 u의 자식임
                sgt.update(in[v], out[v], -1, 1, 1, N);
            }else{
                if(in[u]-1 >= 1) sgt.update(1, in[u]-1, -1, 1, 1, N);
                if(out[u]+1 <= N) sgt.update(out[u]+1, N, -1, 1, 1, N);
            }
        }
    };
    map<pii, tuple<int, string, int>> mp;
    for(auto [u, dir, v] : Edge){
        add(u, dir, v);
        // cout << N - sgt.len[1] << '\n';
        int mn = min(u, v), mx = max(u, v);
        mp[{mn, mx}] = {u, dir, v};
    }
    
    int m; cin >> m;
    while(m--){
        int u, v;
        string dir;
        cin >> u >> dir >> v;
        // update -1
        int mn = min(u, v);
        int mx = max(u, v);
        auto [uu, dd, vv] = mp[{mn, mx}];
        del(uu, dd, vv);
        // update 1
        add(u, dir, v);
        mp[{mn, mx}] = {u, dir, v};
        // query
        cout << N - sgt.len[1] << '\n';
    }
}