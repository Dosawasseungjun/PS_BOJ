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

const ll INF = 1e15;
const int MAXSIZE = 3e5+1;

// min 세그
template <class T>
class minSegtree{
public:
    const T MAX = numeric_limits<T>().max();
    static const int TREESIZE = 4*MAXSIZE;
    T* ntree = new T[TREESIZE];

    minSegtree(){
        for(int i=0;i<TREESIZE;i++) ntree[i] = 0;
    }
    ~minSegtree(){
        delete[] ntree;
    }
    void init(T node, T S, T E, vector<T>& a){
        if(S==E){
            ntree[node]  = a[S];
            return;
        }
        int mid = (S+E)>>1;
        init(2*node, S, mid); init(2*node+1, mid+1, E);
        ntree[node] = min(ntree[2*node], ntree[2*node+1]);
    }
    T update(T x, T v, T node, T S, T E){
        if(S==E) return ntree[node] = v;
        
        T mid = (S+E)>>1;
        if(x<=mid) update(x, v, 2*node, S, mid);
        else update(x, v, 2*node+1, mid+1, E);
        return ntree[node] = min(ntree[2*node], ntree[2*node+1]);
    }
    T nquery(T L, T R, T node, T S, T E){
        if(L>E||R<S) return MAX;
        if(L<=S&&E<=R) return ntree[node];
        T mid = (S+E)>>1;
        return min(nquery(L, R, 2*node, S, mid), nquery(L, R, 2*node+1, mid+1, E));
    }
};

minSegtree<ll> sgt1, sgt2;

int main(){
    fast_io
    ll N, K; cin >> N >> K;
    vector<ll> x(N+1);
    for(int i=1;i<=N;i++) cin >> x[i];
    vector<ll> dp(N+1, INF);
    dp[0] = 0;
    sgt1.update(0, dp[0] - x[0] - 2*x[1], 1, 0, N);
    sgt2.update(0, dp[0] - x[0] + K, 1, 0, N);
    ll res = x[N] + K + x[N] - x[1];
    for(int i=1;i<=N;i++){
        ll lo = -1, hi = i;
        while(lo + 1 < hi){
            ll mid = (lo + hi) >> 1;
            if(2 * (x[i] - x[mid+1]) >= K) lo = mid; // lo가 2(x[i]-x[j+1]) >= k인경우
            else hi = mid;
        }
        
        if(lo == -1) dp[i] = sgt2.nquery(hi, i-1, 1, 0, N) + x[i];
        else if(hi == i) dp[i] = sgt1.nquery(0, lo, 1, 0, N) + 3*x[i];
        else dp[i] = min(sgt2.nquery(hi, i-1, 1, 0, N) + x[i], sgt1.nquery(0, lo, 1, 0, N) + 3 * x[i]);

        if(i <= N) sgt1.update(i, dp[i] - x[i] - 2*x[i+1], 1, 0, N);
        if(i <= N) sgt2.update(i, dp[i] - x[i] + K, 1, 0, N);
        // 끝까지가서 기다리고 돌아와서 마무리하는 경우
        res = min(res, dp[i] + x[N] - x[i] + K + x[N] - x[i+1]);
    }
    res = min(res, dp[N]);
    cout << res;
}