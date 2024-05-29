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

const int MOD = 1e9+7;
const int MAXSIZE = 1e5+1;

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
        if(S==E) return tree[node] = (tree[node] +  v) % MOD;
        
        T mid = (S+E)>>1;
        if(x<=mid) update(x, v, 2*node, S, mid);
        else update(x, v, 2*node+1, mid+1, E);
        return tree[node] = (tree[2*node]+tree[2*node+1]) % MOD;
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
        return (query(L, R, 2*node, S, mid)+query(L, R, 2*node+1, mid+1, E)) % MOD;
    }
};

Segtree<int> sgt[11];

int main(){
    fast_io
    int n, k; cin >> n >> k;
    vector<int> a(n+1);
    vector dp = vector(n+1, vector<int>(k+1));
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        sgt[1].update(a[i], 1, 1, 1, n);
        for(int j=2;j<=k;j++){
            sgt[j].update(a[i], sgt[j-1].query(1, a[i]-1, 1, 1, n), 1, 1, n);
        }
    }
    cout << sgt[k].query(1, n, 1, 1, n);
}