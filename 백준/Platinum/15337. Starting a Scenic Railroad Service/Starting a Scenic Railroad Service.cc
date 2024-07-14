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

Segtree<int> sgt, sgt2;

int main(){
    fast_io
    int n; cin >> n;
    vector<pii> P(n);
    for(int i=0;i<n;i++) cin >> P[i].xx >> P[i].yy;
    int s1 = 0, s2 = 0;
    vector<int> R(MAXSIZE, 0);
    for(int i=0;i<n;i++){
        sgt.update(P[i].yy, 1, 1, 1, MAXSIZE);
        sgt2.update(P[i].xx, 1, 1, 1, MAXSIZE);
        R[P[i].xx]++;
        R[P[i].yy]--;
    }
    for(int i=1;i<MAXSIZE;i++){
        R[i] += R[i - 1];
        s2 = max(s2, R[i]);
    }
    
    for(int i=0;i<n;i++){
        s1 = max(s1, n - sgt2.query(P[i].yy, MAXSIZE, 1, 1, MAXSIZE) - sgt.query(1, P[i].xx, 1, 1, MAXSIZE));
    }
    cout << s1 << ' ' << s2 ;
}