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

const int MAXSIZE = 1e6 + 1;

// max 세그
template <class T>
class maxSegtree{
public:
    const T MIN = numeric_limits<T>().lowest();
    static const int TREESIZE = 4*MAXSIZE;
    T* xtree = new T[TREESIZE];

    maxSegtree(){
        for(int i=0;i<TREESIZE;i++) xtree[i] = 0;
    }
    ~maxSegtree(){
        delete[] xtree;
    }
    void init(T node, T S, T E, vector<T>& a){
        if(S==E){
            xtree[node]  = a[S];
            return;
        }
        int mid = (S+E)>>1;
        init(2*node, S, mid); init(2*node+1, mid+1, E);
        xtree[node] = max(xtree[2*node], xtree[2*node+1]);
    }
    T update(T x, T v, T node, T S, T E){
        if(S==E) return xtree[node] = v;
        
        T mid = (S+E)>>1;
        if(x<=mid) update(x, v, 2*node, S, mid);
        else update(x, v, 2*node+1, mid+1, E);
        return xtree[node] = max(xtree[2*node], xtree[2*node+1]);
    }
    T xquery(T L, T R, T node, T S, T E){
        if(L>E||R<S) return MIN;
        if(L<=S&&E<=R) return xtree[node];
        T mid = (S+E)>>1;
        return max(xquery(L, R, 2*node, S, mid), xquery(L, R, 2*node+1, mid+1, E));
    }
};

int main(){
    fast_io
    int n; cin >> n;
    vector<tiii> A(n);
    vector<pii> B(n);
    vector<int> comp;
    for(int i=0;i<n;i++){
        int idx, l, r;
        cin >> idx >> l >> r;
        A[i] = {idx, l, r};
        comp.push_back(l);
        comp.push_back(r);
        B[i] = {l, r};
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for(int i=0;i<n;i++){
        auto &[l, r] = B[i];
        l = lower_bound(comp.begin(), comp.end(), l) - comp.begin();
        r = lower_bound(comp.begin(), comp.end(), r) - comp.begin();
    }

    sort(B.begin(),B.end(), [&](const pii &a, const pii &b){
        auto [l1, r1] = a;
        auto [l2, r2] = b;
        if(l1 != l2) return l1 < l2;
        return r1 > r2;
    });
    B.erase(unique(B.begin(), B.end()), B.end());

    maxSegtree<int> mxsgt;
    for(int i=0;i<B.size();i++){
        auto [l, r] = B[i];
        int dp = mxsgt.xquery(r, comp.size(), 1, 0, comp.size());
        mxsgt.update(r, dp + 1, 1, 0, comp.size());
        // cout << mxsgt.xquery(0, comp.back(), 1, 0, comp.back()) << '\n';
    }

    cout << mxsgt.xquery(0, comp.size(), 1, 0, comp.size());
}