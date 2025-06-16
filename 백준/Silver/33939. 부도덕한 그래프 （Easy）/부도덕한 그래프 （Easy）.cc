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

const int MAX = 2e3+1;
int n, m;
int G[MAX][MAX];
vector<int> R[MAX];

int main(){
    fast_io
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u, v; cin >> u >> v;
        G[u][v] = 1;
        R[v].push_back(u);
    }
    for(int i=1;i<=n;i++) G[i][i] = 1;
    int res = 0;
    for(int z = 1;z<=n;z++){
        for(int x : R[z]){
            for(int y : R[z]){
                if(!G[x][y] && !G[y][x]) res += 1;
            }
        }
    }
    cout << res / 2;
}