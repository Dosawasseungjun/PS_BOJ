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

struct Node{
    ll n, cost, dist;
    Node(ll a, ll b, ll c) : n(a), cost(b), dist(c){}
    bool operator < (const Node & a) const  {return dist > a.dist;}
};

int main(){
    fast_io
    int n, m; cin >> n >> m;
    vector<ll> C(n+1);
    for(int i=1;i<=n;i++) cin >> C[i];
    vector G = vector(n+1, vector<pii>());
    for(int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    function<ll()> dijkstra = [&](){
        const ll INF = 1e18+1;
        ll res = INF;
        vector dp = vector(n+1, vector<ll>(2501, INF));
        dp[1][C[1]] = 0;
        priority_queue<Node> pq;
        pq.push({1, C[1], 0});
        while(!pq.empty()){
            auto [now, now_cost, now_dist] = pq.top();
            pq.pop();
            
            if(dp[now][now_cost] < now_dist) continue;
            for(auto [nxt, w] : G[now]){
                ll mn_cost = min(C[nxt], now_cost);
                if(dp[nxt][mn_cost] >  w * now_cost + now_dist){
                    dp[nxt][mn_cost] = w * now_cost + now_dist;
                    pq.push(Node(nxt, mn_cost, dp[nxt][mn_cost]));
                }
            }
        }

        for(int i=1;i<=2500;i++){
            res = min(res, dp[n][i]);
        }
        return res;
    };

    cout << dijkstra();
}