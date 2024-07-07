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

const int MAX= 1e5+1;
const ll INF = 1e15+1;
int N, M, L;
vector<pll> G[MAX];
vector<bool> vst, vst2;
vector<ll> D1,D2, R;

ll p, q, rr;

void dfs(int here, ll dist){
    vst[here] = 1;
    D1[here] = dist;
    if(D1[here] > rr){
        rr = D1[here];
        p = here;
    }
    for(auto [nxt, w] : G[here]){
        if(vst[nxt]) continue;
        dfs(nxt, dist + w);
    }
}

void dfs2(int here, ll dist){
    vst2[here] = 1;
    D2[here] = dist;
    if(D2[here] > rr){
        rr = D2[here];
        q = here;
    }
    for(auto [nxt, w] : G[here]){
        if(vst2[nxt]) continue;
        dfs2(nxt, dist + w);
        R[nxt] = here;
    }
}

int main(){
    fast_io
    cin >> N >> M >> L;
    vst = vector<bool> (N+1, 0);
    vst2 = vector<bool> (N+1, 0);
    D1 = vector<ll> (N+1, 0);
    D2 = vector<ll>(N + 1, 0);
    R = vector<ll> (N+1, 0);
    for(int i=0;i<M;i++){
        ll u, v, t;
        cin >> u >> v >> t;
        G[u].push_back({v, t});
        G[v].push_back({u, t});
    }
    ll res = 0;
    vector<pii> trees;
    for(int i=0;i<N;i++){
        if(vst[i]) continue;
        rr = 0;
        p = i;
        dfs(i, 0);
        rr = 0;
        R[p] = -1;
        q = p;
        dfs2(p, 0);
        trees.push_back({q, rr});
        res = max(res, rr);
    }
    vector<ll> radius;
    for(auto [end, rr] : trees){
        ll k = end;
        ll r = INF;
        while(R[k] != -1){
            r = min(r, max(D2[k], rr - D2[k]));
            k = R[k];
        }
        if(r != INF) radius.push_back(r);
        else radius.push_back(0);
    }
    sort(radius.begin(), radius.end(), greater<ll>());
    if(radius.size() >= 2){
        res = max(res, radius[0] + radius[1] + L);
        if(radius.size() >= 3){
            res = max(res, radius[1] + radius[2] + 2 * L);
        }
    }
    cout << res;
}