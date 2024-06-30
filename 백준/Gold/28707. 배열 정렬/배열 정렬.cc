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

const int MAX = 8*7*6*5*4*3*2*1 + 1;
const int INF = 1e9;
map<vector<int>, int> mp;
vector<pii> G[MAX];

vector<int> djikstra(int src, int n){
    vector<int> dist(n, INF);
    dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({dist[src], src});
    while(!pq.empty()){
        auto [w , now]  = pq.top();
        pq.pop();
        if(dist[now] < w) continue;
        for(auto [nxt, cost] : G[now]){
            if(dist[nxt] > w + cost){
                dist[nxt] = w + cost;
                pq.push({dist[nxt], nxt});
            }
        }
    }
    return dist;
}
int main(){
    fast_io
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int m; cin >> m;
    vector<tiii> b(m);
    for(int i=0;i<m;i++){
        int l, r, c; cin >> l >> r >> c;
        b[i] = {l-1, r-1, c};
    }
    vector<int> c = a;
    sort(c.begin(), c.end());
    int cnt = 0;
    do{
        mp[c] = ++cnt;
    }while(next_permutation(c.begin(), c.end()));

    queue<vector<int>> q;
    vector<int> vst(cnt + 1, 0);
    q.push(a);
    while(!q.empty()){
        vector<int> tmp = q.front();
        q.pop();
        if(vst[mp[tmp]]) continue;
        vst[mp[tmp]] = 1;
        for(auto [l, r, c] : b){
            vector<int> ori = tmp;
            swap(tmp[l], tmp[r]);
            q.push(tmp);
            G[mp[ori]].push_back({mp[tmp], c});
            G[mp[tmp]].push_back({mp[ori], c});
        }
    }
    vector<int> D = djikstra(mp[a], cnt+1);
    cout << (D[1] == INF ? -1 : D[1]);
}