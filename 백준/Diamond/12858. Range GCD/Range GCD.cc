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


// 세그
template <class T, int XSZ>
class Segtree{
public:
    static const int TREESIZE = 4*XSZ;
    T* tree = new T[TREESIZE];

    Segtree(){
        for(int i=0;i<TREESIZE;i++) tree[i] = 0;
    }
    ~Segtree(){
        delete[] tree;
    }
    T update(T x, T v, T node, T S, T E){
        if(S==E) return tree[node] = v;
        
        T mid = (S+E)>>1;
        if(x<=mid) update(x, v, 2*node, S, mid);
        else update(x, v, 2*node+1, mid+1, E);
        return tree[node] = gcd(tree[2*node],tree[2*node+1]);
    }
    T query(T L, T R, T node, T S, T E){
        if(L>E||R<S) return 0;
        if(L<=S&&E<=R) return tree[node];
        T mid = (S+E)>>1;
        return gcd(query(L, R, 2*node, S, mid),query(L, R, 2*node+1, mid+1, E));
    }
};

LazySegtree<ll, MAX> lsgt;
Segtree<ll, MAX> sgt;

int main(){
    fast_io
    int n; cin >> n;
    n++;
    for(int i=1;i<=n-1;i++){
        ll x; cin >> x;
        lsgt.update(i, i, x, 1, 1, n);
    }
    for(int i=1;i<=n;i++){
        ll x = ((i == 1 || i == n) ? ( i==1 ? lsgt.query(i, i, 1, 1, n) : lsgt.query(i-1, i-1, 1, 1, n) )
                : lsgt.query(i, i, 1, 1, n) - lsgt.query(i - 1, i - 1, 1, 1, n));
        sgt.update(i, abs(x), 1, 1, n);
    }
    int q; cin >> q;
    while(q--){
        ll t, a, b;
        cin >> t >> a >> b;
        if(t){
            lsgt.update(a, b, t, 1, 1, n);
            ll L = lsgt.query(a, a, 1, 1, n) - lsgt.query(a-1, a-1, 1, 1, n);
            sgt.update(a, abs(L), 1, 1, n);
            ll R = lsgt.query(b+1, b+1, 1, 1, n) - lsgt.query(b, b, 1, 1, n);
            sgt.update(b+1, abs(R), 1, 1, n);
        }else{
            cout << gcd(lsgt.query(a, a, 1, 1, n), sgt.query(a+1, b, 1, 1, n)) << '\n';
        }
    }
}