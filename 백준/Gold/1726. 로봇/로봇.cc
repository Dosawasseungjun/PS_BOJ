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
    int N, M; cin >> N >> M;
    vector G = vector(N+1, vector<int> (M+1));
    vector D = vector(N+1, vector(M+1, vector<int> (5, -1)));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++) cin >> G[i][j];
    }
    int sy, sx, sd; cin >> sy >> sx >> sd;
    int ey, ex, ed; cin >> ey >> ex >> ed;
    D[sy][sx][sd] = 0;
    queue<tiii> q;
    q.push({sy, sx, sd});
    vector<int> go = {1, 2, 3};
    // 동 서 남 북 보고있을 때 right, left
    vector<vector<int>> mp = {{0, 0}, {3, 4}, {4, 3}, {2, 1}, {1, 2}};
    while(!q.empty()){
        auto [hy, hx, hd] = q.front();
        q.pop();
        for(int k : go){
            int ny = hy, nx = hx, nd = hd;
            if(hd == 1) nx += k;
            else if(hd == 2) nx -= k;
            else if(hd == 3) ny += k;
            else ny -= k;

            if(ny > 0 && ny <= N && nx > 0 && nx <= M && !G[ny][nx] && D[ny][nx][nd] == -1){
                D[ny][nx][nd] = D[hy][hx][hd] + 1;
                q.push({ny, nx, nd});
            }else if(ny > 0 && ny <= N && nx > 0 && nx <= M && G[ny][nx]) break;
        }
        int right = mp[hd][0];
        int left = mp[hd][1];
        if(D[hy][hx][right] == -1){
            D[hy][hx][right] = D[hy][hx][hd] + 1;
            q.push({hy, hx, right});
        }
        if(D[hy][hx][left] == -1){
            D[hy][hx][left] = D[hy][hx][hd] + 1;
            q.push({hy, hx, left});
        }
    }
    cout << D[ey][ex][ed];
}