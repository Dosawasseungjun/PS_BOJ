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

void solv(){
    int N, M, ST, DES; cin >> N >> M >> ST >> DES;
    vector G = vector(N+1, vector<pll>());
    for(int i=0;i<M;i++){
        ll u, v, c;
        cin >> u >> v >> c;
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }
    for(int i=1;i<=N;i++) sort(G[i].begin(), G[i].end());
    const ll INF = 9e18;
    vector<ll> P(N+1), D(N+1, INF);
    for(int i=1;i<=N;i++) cin >> P[i];
    function<ll(ll, ll, ll, ll)> find_start_time = [&](ll d, ll p,  ll j, ll n){
        if(j == -1 || n == 0)return d;
        ll x = (d/p)%n;
        if(x == j) return d;
        // if(d < j * p) return j*p;
        // ll x = d- j*p;
        // ll k = (x + n*p - 1) / (n*p);
        // return k * n * p + j * p;
        return (d/p + (j+n-x)%n)*p;
    };
    function<ll(int)> dijkstra = [&](int src){
        D[src] = 0;
        priority_queue<tlll, vector<tlll>, greater<tlll>> pq;
        pq.push({D[src], src, 0});
        while(!pq.empty()){
            auto [d, here, pre] = pq.top();
            pq.pop();

            if(here == DES) return D[DES];

            int sz = G[here].size();
            int pre_idx = -1;
            for(int j=0;j<G[here].size();j++) if(pre == G[here][j].xx) pre_idx = j;
            for(int j=0;j<G[here].size();j++){
                auto [nxt, cost] = G[here][j];
                // 출발가능시각
                ll st = find_start_time(d, P[here],  pre_idx, sz);
                if(D[nxt] > st + cost){
                    D[nxt] = st + cost;
                    pq.push({D[nxt], nxt, here});
                }
            }
        }
        return D[DES];
    };
    
    ll res = dijkstra(ST);
    cout << (res == INF ? -1  : res) << '\n';
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}