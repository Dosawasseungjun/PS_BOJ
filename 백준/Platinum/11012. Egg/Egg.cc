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

const int MAXSIZE = 1e5+1;

// lazy propagation segment tree
// 더하기 세그먼트트리
template <class T, int XSZ>
class LazySegtree{
public:
    static const int TREESIZE = 4*XSZ;
    T* tree = new T[TREESIZE];
    T* lazy = new T[TREESIZE];

    LazySegtree(){
        for(int i=0;i<TREESIZE;i++) tree[i] = lazy[i] = 0;
    }
    ~LazySegtree(){
        delete[] tree, lazy;
    }
    void prop(T node, T S, T E){
        if(lazy[node]){
            tree[node] += (E-S+1)*lazy[node];
            if(S!=E){   //아래로 전파
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0; //전파 다했으면 이칸은 0으로
        }
    }
    void update(T L,T R, T v, T node, T S, T E){
        prop(node, S, E);  // 표시 되어있으면 전파하는 과정
        if(R<S||L>E) return;
        if(L<=S&&R>=E){
            tree[node] += (E-S+1)*v;
            if(S!=E){
                lazy[2*node] += v;
                lazy[2*node+1] += v;
            }
            return;
        }
        ll mid = (S+E)>>1;
        update(L, R, v, 2*node, S, mid); update(L, R, v, 2*node+1, mid+1, E);
        tree[node] = tree[2*node]+tree[2*node+1];
    }
    T query(T L, T R, T node, T S, T E){
        prop(node, S, E);
        if(R<S||L>E) return 0;
        if(L<=S&&R>=E) return tree[node];
        ll mid = (S+E)>>1;
        return query(L, R, 2*node, S, mid)+query(L, R, 2*node+1, mid+1, E);
    }
};

void solv(){
    int n, m; cin >> n >> m;
    vector<vector<int>> col(MAXSIZE);
    for(int i=0;i<n;i++){
        int x, y; cin >> x >> y;
        col[x].push_back(y);
    }
    ll res = 0;
    LazySegtree<ll, MAXSIZE> lsgt;
    vector<vector<pii>> st(MAXSIZE);
    vector<vector<pii>> ed(MAXSIZE);
    for(int i=0;i<m;i++){
        int l, r, b, t;
        cin >> l >> r >> b >> t;
        st[l].push_back({b, t});
        ed[r].push_back({b, t});
    }
    ll ans = 0;
    for(int i=0;i<MAXSIZE;i++){
        for(auto [l, r] : st[i]){
            lsgt.update(l, r, 1, 1, 0, MAXSIZE);
        }

        for(int y : col[i]){
            ans += lsgt.query(y, y, 1, 0, MAXSIZE);
        }

        for(auto [l, r] : ed[i]){
            lsgt.update(l, r, -1, 1, 0, MAXSIZE);
        }
    }
    cout << ans << '\n';
}


int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}