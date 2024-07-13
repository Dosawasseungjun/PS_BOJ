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

const int MAX = 1e3+1;
const int INF = 1e9+1;
int n, m, a, b, c;
vector<pii> G[MAX];
int P[MAX];

vector<int> dijkstra(int src, int op = 0){
    vector<int> D(n+1, INF);
    D[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({D[src], src});
    while(!pq.empty()){
        auto [W, here] = pq.top();
        pq.pop();

        if(W > D[here]) continue;
        for(auto [nxt, w] : G[here]){
            if(D[nxt] > W + w){
                D[nxt] = W + w;
                pq.push({D[nxt], nxt});
                if(op) P[nxt] = here;
            }
        }
    }
    return D;
}

void recon(int a, vector<pii> & ans){
    int node = a;
    while(P[node]){
        ans.emplace_back(P[node], node);
        node = P[node];
    }
}

int main(){
    fast_io
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    cin >> a >> b >> c;
    vector<int> D1 = dijkstra(a);
    vector<int> D2 = dijkstra(b);
    vector<int> D3 = dijkstra(c);
    int mn = INF;
    int node = 0;
    for(int i=1;i<=n;i++){
        if(D1[i] + D2[i] + D3[i] < mn){
            mn = D1[i] + D2[i] + D3[i];
            node = i;
        }
    }
    vector<int> D = dijkstra(node, 1);
    vector<pii> ans;
    recon(a, ans); recon(b, ans); recon(c, ans);
    cout << mn << ' ' << ans.size() << '\n';
    for(auto [u, v] : ans){
        cout << u << ' ' <<  v << '\n';
    }
}