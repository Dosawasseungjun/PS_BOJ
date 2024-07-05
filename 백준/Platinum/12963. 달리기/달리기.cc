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
const int MAX = 2e3+1;
vector<int> G[MAX], vst;
int n, m;

ll mul(ll a, ll e){
    if(!e) return 1LL;
    ll half = mul(a, e / 2);
    if(e & 1) return (half * half) % MOD * a % MOD;
    return half * half % MOD;
}

bool dfs(int here){
    vst[here] = 1;
    if(here == n-1) return 1;
    int ret = 0;
    for(int nxt : G[here]){
        if(vst[nxt]) continue;
        ret |= dfs(nxt);
    }
    return ret;
}

int main(){
    fast_io
    cin >> n >> m;
    vector<pii> E(m);
    vector<ll> cap(m);
    for(int i=0;i<m;i++){
        int u, v; cin >> u >> v;
        E[i] = {u, v};
        cap[i] = mul(3LL, i);
    }
    ll res = 0;
    for(int i=m-1;i>=0;i--){
        auto [u, v] = E[i];
        G[u].push_back(v);
        G[v].push_back(u);
        vst = vector<int>(n, 0);
        if(dfs(0)){
            G[u].pop_back();
            G[v].pop_back();
            res = (res + cap[i]) % MOD;
        }
    }
    cout << res;
}