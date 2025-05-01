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

const int MAXSIZE = 5e5 + 1;
const int INF = 1e9+1;

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
        if(S==E) return xtree[node] += v;
        
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
    int N; cin >> N;
    vector<int> A(N+1), pre(N+1), last(N+1, 0);
    vector<int> D(N+1), L(N+1);

    vector<vector<int>> B(N+1);
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1;i<=N;i++){
        pre[i] = last[A[i]];
        last[A[i]] = i;

        L[i] = max((i == 1 ? 1 : L[i-1]), pre[i]+1);
        D[i] = i - L[i] + 1;
        B[L[i]].push_back(i);
    }
    
    int q; cin >> q;
    vector Q = vector(N+1, vector<pii>());
    vector<ll> ans(q+1, 0);
    for(int i=1;i<=q;i++){
        int l, r; cin >> l >> r;
        Q[l].push_back({r, i});
    }
    maxSegtree<ll> mxsgt1, mxsgt2;

    for(int curL = N; curL >= 1; curL--){
        // L[i] == curL인 애들을 세그트리에 추가 (시작위치가 L[i]인 i들이 들어가 있음 - 쿼리시작 위치보다 항상 큰 애들만 들어가 있음)
        for(int i : B[curL]){
            mxsgt1.update(i, D[i], 1, 1, N);
        }

        for(auto [r, idx] : Q[curL]){
            ans[idx] = max(ans[idx], mxsgt1.xquery(curL, r, 1, 1, N));
        }
    }

    for(int curL = 1; curL <= N ; curL++){
        // L[i] == curL-1인 애들을 세그트리에 추가 (쿼리의 l보다 더 이전에 있는 애들만 되어 있음)
        for(int i : B[curL-1]){
            mxsgt2.update(i, i, 1, 1, N);
        }

        for(auto [r, idx] : Q[curL]){
            ll best = mxsgt2.xquery(curL, r, 1, 1, N);
            ans[idx] = max(ans[idx], best < 0 ? 0 : best - curL + 1);
        }
    }


    for(int i=1;i<=q;i++){
        cout << ans[i] << '\n';
    }
}