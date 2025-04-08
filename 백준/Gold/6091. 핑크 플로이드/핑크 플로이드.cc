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
    vector d = vector(n+1, vector<int>(n+1, 0));
    vector<tiii> e;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cin >> d[i][j];
            d[j][i] = d[i][j];
            e.push_back({d[i][j], i, j});
        }
    }
    sort(e.begin(), e.end());
    int k = 0;
    vector ans = vector(n+1, vector<int>());
    for(auto [dist, u, v] : e){
        bool is_add = true;
        for(int j=1;j<=n;j++){
            if(j == u || j == v) continue;
            if(d[u][j] + d[j][v] == dist){
                is_add = false;
            }
        }
        if(is_add){
            ans[u].push_back(v);
            ans[v].push_back(u);
            k += 1;
        }
        if(k == n-1) break;
    }
    for(int i=1;i<=n;i++){
        cout << ans[i].size() << ' ';
        sort(ans[i].begin(), ans[i].end());
        for(int res : ans[i]) cout << res << ' ';
        cout << '\n';
    }
}