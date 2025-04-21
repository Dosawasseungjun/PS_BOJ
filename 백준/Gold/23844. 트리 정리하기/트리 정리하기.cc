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

const int MAX = 1e4+1;
int N, K;
vector<int> G[MAX];
int dep[MAX];
int in[MAX], out[MAX];
vector<int> D[MAX];

const int MAXSIZE = 1e4+1;

// 구간합 세그
template <class T>
class Segtree{
public:
    static const int TREESIZE = 4*MAXSIZE;
    T* tree = new T[TREESIZE];

    Segtree(){
        for(int i=0;i<TREESIZE;i++) tree[i] = 0;
    }
    ~Segtree(){
        delete[] tree;
    }
    T update(T x, T v, T node, T S, T E){
        if(S==E) return tree[node] += v;
        
        T mid = (S+E)>>1;
        if(x<=mid) update(x, v, 2*node, S, mid);
        else update(x, v, 2*node+1, mid+1, E);
        return tree[node] = tree[2*node]+tree[2*node+1];
    }
    T kth(T node, T S, T E, T K){
        if(S==E) return S;
        T mid = (S+E)>>1;
        if(tree[2*node]>=K) return kth(2*node, S, mid, K);
        else return kth(2*node+1, mid+1, E, K-tree[2*node]);
    }
    T query(T L, T R, T node, T S, T E){
        if(L>E||R<S) return 0;
        if(L<=S&&E<=R) return tree[node];
        T mid = (S+E)>>1;
        return query(L, R, 2*node, S, mid)+query(L, R, 2*node+1, mid+1, E);
    }
};


int cnt = 0;
Segtree<int> sgt;

void dfs(int here, int parent){
    in[here] = ++cnt;
    sgt.update(cnt, 1, 1, 1, N);
    for(int nxt : G[here]) if(nxt != parent){
        dep[nxt] = dep[here] + 1;
        dfs(nxt, here);
    }
    out[here] = cnt;
}




int main(){
    fast_io
    cin >> N >> K;
    for(int i=1;i<N;i++){
        int u, v; 
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 1);
    
    int mx = 0;
    for(int i=1;i<=N;i++) {
        D[dep[i]].push_back(i);
        mx = max(mx, dep[i]);
    }
    
    for(int i = mx; i >= 0; i--){
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(int x : D[i]) pq.push({sgt.query(in[x], out[x], 1, 1, N), x});
        while(pq.size() > K){
            auto [d, k] = pq.top();
            pq.pop();
            int x = sgt.query(in[k], out[k], 1, 1, N);
            sgt.update(in[k], -x, 1, 1, N);
        }
    }

    cout << sgt.query(1, N, 1, 1, N);
}