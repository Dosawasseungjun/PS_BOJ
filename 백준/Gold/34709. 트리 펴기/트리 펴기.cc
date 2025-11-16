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


int main(){
    fast_io
    int n; cin >> n;
    vector<int> C(n+1);
    vector G = vector(n+1, vector<int>());
    for(int i=1;i<n;i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        C[u] += 1;
        C[v] += 1;
    }
    int res = 0;
    function<void(int, int)> dfs = [&](int now, int parent){
        res += max(0, C[now] - 2);
        for(int nxt : G[now]){
            if(nxt == parent) continue;
            dfs(nxt, now);
        }
    };
    dfs(1, 0);
    cout << res;
}