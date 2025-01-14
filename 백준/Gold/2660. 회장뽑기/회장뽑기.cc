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

const int INF = 1e9;

int main(){
    fast_io
    int n; cin >> n;
    vector G = vector(n+1, vector<int>(n+1, INF));
    int u, v;
    while(1){
        cin >> u >> v;
        if(u == -1 && v == -1) break;
        G[u][v] = 1;
        G[v][u] = 1;
    }
    for(int i=1;i<=n;i++) G[i][i] = 0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
            }
        }
    }
    
    int res = INF;
    vector<int> res_arr;
    for(int i=1;i<=n;i++){
        int mx = 0;
        for(int j=1;j<=n;j++){
            mx = max(mx, G[i][j]);
        }
        if(res >= mx){
            if(res == mx) res_arr.push_back(i);
            else{
                res = mx;
                res_arr.clear();
                res_arr.push_back(i);
            }
        }
    }
    cout << res << ' ' << res_arr.size() << '\n';
    for(int r : res_arr) cout << r << ' ';
}