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

const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};

int main(){
    fast_io
    int n, m, k; cin >> n >> m >> k;
    vector<pii> pos(k);
    vector G = vector(n+1, vector<int> (m+1, 0));
    for(int i=0;i<k;i++){
        int x, y; cin >> x >> y;
        pos[i] = {x, y};
        G[x][y] = 1;
    }   
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;

    vector vst = vector(n+1, vector<int>(m+1, 0));
    ll res = 0;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vst[i][j] && !G[i][j]){
                queue<pii> q;
                q.push({i, j});
                vst[i][j] = ++cnt;
                while(!q.empty()){
                    auto [hy, hx] = q.front();
                    q.pop();

                    for(int k=0;k<4;k++){
                        int ny = hy + dy[k];
                        int nx = hx + dx[k];

                        if(ny >= 1 && ny <= n && nx >= 1 && nx <= m && !vst[ny][nx] && !G[ny][nx]){
                            vst[ny][nx] = cnt;
                            q.push({ny, nx});
                        }
                    }
                }
            }
        }
    }
    vector<ll> C1(cnt + 1), C2(cnt+1);
    for(int i=x1;i<=x2;i++){
        for(int j=y1;j<=y2;j++){
            C1[vst[i][j]] += 1;
        }
    }
    for(int i=x3;i<=x4;i++){
        for(int j=y3;j<=y4;j++){
            C2[vst[i][j]] += 1;
        }
    }
    for(int i=1;i<=cnt;i++){
        res += C1[i] * C2[i];
    }
    cout << res;
}