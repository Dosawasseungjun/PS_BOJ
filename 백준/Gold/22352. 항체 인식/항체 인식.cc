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

const int MAX = 31;
int n, m;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

vector<vector<int>> bfs(int y, int x, vector<vector<int>> &G){
    vector vst = vector(n+1, vector<int> (m+1, 0));
    queue<pii> q;
    q.push({y, x});
    vst[y][x] = 1;
    while(!q.empty()){
        auto [hy, hx] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int ny = hy + dy[i];
            int nx = hx + dx[i];
            if(ny >= 1 && ny <= n && nx >= 1 && nx <= m && !vst[ny][nx] && G[hy][hx] == G[ny][nx]){
                q.push({ny, nx});
                vst[ny][nx] = 1;
            }
        }
    }
    return vst;
}

int main(){
    fast_io
    cin >> n >> m;
    vector G1 = vector(n+1, vector<int>(m+1));
    vector G2 = vector(n + 1, vector<int>(m + 1));
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> G1[i][j];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> G2[i][j];
    bool ok = false;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            vector V = bfs(i, j, G1);
            int pre = -1;
            bool pb = true;
            for(int p=1;p<=n;p++){
                for(int q=1;q<=m;q++){
                    if(!V[p][q] && G1[p][q] != G2[p][q]) pb = false;
                    if(V[p][q]){
                        if(pre == -1) pre = G2[p][q];
                        else if(pre != G2[p][q]) pb = false;
                    }
                }
            }
            if(pb) ok = true;
        }
    }

    if(ok) cout << "YES";
    else cout << "NO";
}