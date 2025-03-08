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

int main(){
    fast_io
    int N, M; cin >> N >> M;
    vector<pll> D(N+1);
    D[1] = {0, 1};
    for(int i=2;i<=N;i++) cin >> D[i].xx, D[i].yy = i;
    vector G = vector(N+1, vector<array<ll, 3>>());
    for(int i=0;i<M;i++){
        ll u, v, L, R;
        cin >> u >> v >> L >> R;
        G[u].push_back({v, L, R});
        G[v].push_back({u, L, R});
    }
    sort(D.begin(), D.end());
    vector<int> vst(N+1, 0);
    vector<ll> dist(N+1, 0);
    vst[1] = 1; 
    ll res = 1;
    for(int i=2;i<=N;i++){
        auto [d, u] = D[i];
        vst[u] = 1;
        ll cnt = 0;
        ll p = 1, q = 1, r =1;
        for(auto [v, L, R] : G[u]){
            if(vst[v]){
                ll sz = dist[v] + R - d + 1;
                if(dist[v] + L <= d && d <= dist[v] + R){
                    cnt++;
                    p = p * sz % MOD;
                    q = q * (sz-1) % MOD;
                }else if(dist[v] + L > d){
                    r = r * (R - L + 1) % MOD;
                }else{
                    res = 0;
                }
            }
        }

        if(!cnt) res = 0;
        else{
            dist[u] = d;
            ll tmp = ((p - q) % MOD + MOD) % MOD ;
            res = res * tmp % MOD * r % MOD;
        }
        
    }
    cout << res;
}