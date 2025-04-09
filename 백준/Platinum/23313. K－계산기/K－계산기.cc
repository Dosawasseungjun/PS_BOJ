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

ll const mod = 1e9+7;
const int MAXSIZE = 5e5+1;

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

ll power(ll a, ll e){
    if(e == 0) return 1;
    if(e == 1) return a;
    ll half = power(a, e/2);
    
    if(e & 1) return half * half % mod * a % mod;
    return half * half % mod;
}

Segtree<ll> sgt1, sgt2;

int main(){
    fast_io
    int N; cin >> N;
    vector<ll> X(N), u(N-1);
    vector<char> Op(N-1);
    for(int i=0;i<N;i++){
        cin >> X[i]; sgt1.update(i, 1, 1, 0, N);
        if(i != N-1 ) cin >> Op[i], sgt2.update(i, 1, 1, 0, N);
    }
    for(int i=0;i<N-1;i+=1) cin >> u[i];
    ll v = 0;
    for(int i=0;i<N-1;i++){
        ll k = u[i] ^ v;
        ll idx = sgt2.kth(1, 0, N, k);
        ll idx1 = sgt1.kth(1, 0, N, k);
        ll idx2 = sgt1.kth(1, 0, N, k+1);
        sgt2.update(idx, -1, 1, 0, N);
        sgt1.update(idx2, -1, 1, 0, N);

        if(Op[idx] == '+'){
            v = X[idx1] + X[idx2];
            v %= mod;
            X[idx1] = v;
        }else if(Op[idx] == '-'){
            v = X[idx1] - X[idx2];
            v = (v % mod + mod) % mod;
            X[idx1] = v;
        }else if(Op[idx] == '*'){
            v = X[idx1] * X[idx2] % mod;
            X[idx1] = v;
        }else{
            ll g = gcd(X[idx1], X[idx2]);
            v =(X[idx1]/g) * power(X[idx2]/g, mod-2) % mod;
            X[idx1] = v;
        }
        cout << v << '\n';
    }
}