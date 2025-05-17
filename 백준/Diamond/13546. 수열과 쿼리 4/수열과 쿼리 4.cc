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

// 구간합 세그
template <class T>
class Segtree{
public:
    static const int TREESIZE = 4*MAX;
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

Segtree<int> sgt;

template<int SZ> struct mos{
    int n, K, A[SZ], ans[SZ], cnt[SZ], res = 0;
    deque<int> DQ[SZ];
    vector<pair<pii,int>> Q;
    inline void add(int k, int op){//현 구간에 k를 하나 추가해준다.
        int now = 0;
        deque<int> &dq  = DQ[A[k]];
        if(!dq.empty()){
            now = dq.back() - dq.front();
            if(!(--cnt[now])) sgt.update(now, -1, 1, 0, n), res--;
        }
        if(op == 1) dq.push_back(k);
        else dq.push_front(k);
        now = dq.back() - dq.front();
        if((++cnt[now]) == 1) sgt.update(now, 1, 1, 0, n), res++;
    }
    inline void pop(int k, int op){//현 구간에서 k를 하나 제거해준다.
        deque<int> &dq = DQ[A[k]];
        int now = dq.back()-dq.front();
        if(!(--cnt[now])) sgt.update(now, -1, 1, 0, n), res--;
        if(op == 1) dq.pop_back();
        else dq.pop_front();
        if(!dq.empty()){
            now = dq.back()-dq.front();
            if((++cnt[now]) == 1) sgt.update(now, 1, 1, 0, n), res++;
        }
    }
    void MOquery(){
	    const int sqrtN = sqrt(n);
	    sort(Q.begin(), Q.end(), [sqrtN](auto &a, auto &b){
		    int Ln = a.first.first/sqrtN, Rn = b.first.first/sqrtN;
		    if(Ln != Rn) return Ln < Rn;
		    //부등호를 뒤집으면 더 빨라질수도 있음.
		    if(Ln&1) return a.first.second > b.first.second;
        	else return a.first.second < b.first.second;
	    });

	    int L = 1, R = 1; add(1, 1); // 1-based?
	    for(auto &P : Q){
		    int nL = P.first.first, nR = P.first.second;
		    if(nL < L) for(int i=L-1; i>=nL; --i) add(i, 0);
		    if(R < nR) for(int i=R+1; i<=nR; ++i) add(i, 1);
		    if(L < nL) for(int i=L; i<nL; ++i) pop(i, 0);
		    if(nR < R) for(int i=R; i>nR; --i) pop(i, 1);
		    L = nL; R = nR; ans[P.second] = sgt.kth(1, 0, n, res);
	    }
    }
};

mos<MAX> ms;

int main(){
    fast_io
    cin >> ms.n >> ms.K;
    for(int i=1;i<=ms.n;i++) cin >> ms.A[i];
    for(int i=0;i<=ms.n;i++) ms.cnt[i] = 0;
    int q; cin >> q;
    for(int i=1;i<=q;i++){
        int l, r; cin >> l >> r;
        ms.Q.push_back({{l, r}, i});
    }
    ms.MOquery();
    for(int i=1;i<=q;i++){
        cout << ms.ans[i] << '\n';
    }
}