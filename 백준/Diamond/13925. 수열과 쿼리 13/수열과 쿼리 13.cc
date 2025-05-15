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

const ll MOD = 1e9+7;

template <class T, int XSZ>
class LazySegtree{
public:
    static const int TREESIZE = 4*XSZ;
    T* tree = new T[TREESIZE];
    T* lazy = new T[TREESIZE];
    T* lazy2 = new T[TREESIZE];

    LazySegtree(){
        for(int i=0;i<TREESIZE;i++) tree[i] = 0, lazy[i] =1, lazy2[i]= 0;
    }
    ~LazySegtree(){
        delete[] tree, lazy, lazy2;
    }
    void prop(T node, T S, T E){
        T &a = lazy[node];
        T &b = lazy2[node];
        if(a != 1 || b != 0){
            if(S!=E){   //아래로 전파
                T a1 = lazy[2*node], b1 = lazy2[2*node];
                T a2 = lazy[2*node+1], b2 = lazy2[2*node+1];

                lazy[2*node] = a * a1 % MOD;
                lazy2[2*node] = (a * b1 + b) % MOD;
                lazy[2*node+1] = a * a2 % MOD;
                lazy2[2*node+1] = (a * b2 + b) % MOD;
            }
        }
        tree[node] = (a * tree[node] + (E - S + 1) * b) % MOD;
        a = 1;
        b = 0;
    }
    void update(T L,T R, T v1, T v2, T node, T S, T E){
        prop(node, S, E);  // 표시 되어있으면 전파하는 과정
        if(R<S||L>E) return;
        if(L<=S&&R>=E){
            
            lazy[node] = (lazy[node] * v1) % MOD;
            lazy2[node] = (lazy2[node] * v1 % MOD + v2) % MOD;
            prop(node, S, E);
            
            return;
        }
        ll mid = (S+E)>>1;
        update(L, R, v1, v2, 2*node, S, mid); update(L, R, v1, v2, 2*node+1, mid+1, E);
        tree[node] = (tree[2*node]+tree[2*node+1]) % MOD;
    }


    T query(T L, T R, T node, T S, T E){
        prop(node, S, E);
        if(R<S||L>E) return 0;
        if(L<=S&&R>=E) return tree[node] % MOD;
        ll mid = (S+E)>>1;
        return (query(L, R, 2*node, S, mid)+query(L, R, 2*node+1, mid+1, E)) % MOD;
    }
};

int main(){
    fast_io
    int N; cin >> N;
    LazySegtree<ll, 100001> lsgt;
    for(int i=1;i<=N;i++){
       ll x; cin >> x;
       lsgt.update(i, i, 1, x, 1, 1, N);
    }
    int M; cin >> M;
    while(M--){
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1){
            ll v; cin >> v;
            lsgt.update(x, y, 1, v, 1, 1, N);
        }else if(op == 2){
            ll v; cin >> v;
            lsgt.update(x, y, v, 0, 1, 1, N);
        }else if(op == 3){
            ll v; cin >> v;
            lsgt.update(x, y, 0, v, 1, 1, N);
        }else{
            cout << lsgt.query(x, y, 1, 1, N) << '\n';
        }
    }
}