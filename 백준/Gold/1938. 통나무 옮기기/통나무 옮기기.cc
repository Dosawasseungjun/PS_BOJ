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
    vector G = vector(n+1, vector<char>(n+1));
    vector<pii> B, E;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> G[i][j];
            if(G[i][j] == 'B') B.push_back({i, j});
            if(G[i][j] == 'E') E.push_back({i, j});
        }
    }
    int sy = 0, sx = 0, sdir = (B[0].xx == B[1].xx ? 1 : 0); // 0을 세로, 1을 가로라고 하자.
    int ey = 0, ex = 0, edir = (E[0].xx == E[1].xx ? 1 : 0);
    for(int i=0;i<3;i++){
        sy += B[i].xx; sx += B[i].yy;
        ey += E[i].xx; ex += E[i].yy;
    }
    sy /= 3; sx /= 3; ey /= 3; ex /= 3;

    vector D = vector(n+1, vector(n+1, vector<int>(2, -1)));
    D[sy][sx][sdir] = 0;
    queue<tiii> q; 
    q.push({sy, sx, sdir});
    while(!q.empty()){
        auto [y, x, dir] = q.front();
        // cout << y << ' ' << x << ' ' << dir << '\n';
        q.pop();
        if(dir){ // 가로로 되어있을 때
            // 위
            if(y-1 >= 1 && y-1 <= n && G[y-1][x] != '1' && G[y-1][x-1] != '1' && G[y-1][x+1] != '1' && D[y-1][x][dir]== -1){
                D[y-1][x][dir] = D[y][x][dir] + 1;
                q.push({y-1, x, dir});
            }
            // 아래
            if(y+1 >= 1 && y+1 <= n && G[y+1][x] != '1' && G[y+1][x+1] != '1' && G[y+1][x-1] != '1' && D[y+1][x][dir]== -1){
                D[y+1][x][dir] = D[y][x][dir] + 1;
                q.push({y+1, x, dir});
            }
            // 오른쪽
            if(x >= 1 && x+2 <= n && G[y][x] != '1' && G[y][x+1] != '1' && G[y][x+2] != '1' && D[y][x+1][dir]== -1){
                D[y][x+1][dir] = D[y][x][dir] + 1;
                q.push({y, x+1, dir});
            }
            // 왼쪽
            if(x-2 >= 1 && x <= n && G[y][x] != '1' && G[y][x-1] != '1' && G[y][x-2] != '1' && D[y][x-1][dir]== -1){
                D[y][x-1][dir] = D[y][x][dir] + 1;
                q.push({y, x-1, dir});
            }
            
        }else{// 세로
            // 위
            if(y-2 >= 1 && y <= n && G[y][x] != '1' && G[y-1][x] != '1' && G[y-2][x] != '1' && D[y-1][x][dir]== -1){
                D[y-1][x][dir] = D[y][x][dir] + 1;
                q.push({y-1, x, dir});
            }
            // 아래
            if(y >= 1 && y+2 <= n && G[y][x] != '1' && G[y+1][x] != '1' && G[y+2][x] != '1' && D[y+1][x][dir]== -1){
                D[y+1][x][dir] = D[y][x][dir] + 1;
                q.push({y+1, x, dir});
            }
            // 오른쪽
            if(x+1 >= 1 && x+1 <= n && G[y][x+1] != '1' && G[y+1][x+1] != '1' && G[y-1][x+1] != '1' && D[y][x+1][dir]== -1){
                D[y][x+1][dir] = D[y][x][dir] + 1;
                q.push({y, x+1, dir});
            }
            // 왼쪽
            if(x-1 >= 1 && x-1 <= n && G[y][x-1] != '1' && G[y-1][x-1] != '1' && G[y+1][x-1] != '1' && D[y][x-1][dir]== -1){
                D[y][x-1][dir] = D[y][x][dir] + 1;
                q.push({y, x-1, dir});
            }
        }
        bool can_turn = true;
        for(int dy : {-1, 0, 1}){
            for(int dx : {-1, 0, 1}){
                if (y + dy < 1 || y + dy > n || x + dx < 1 || x + dx > n){
                    can_turn = false;
                    break;
                }
                if(G[y+dy][x+dx] == '1'){
                    can_turn = false;
                    break;
                }
            }
        }

        if(can_turn && D[y][x][dir ^ 1] == -1){
            D[y][x][dir ^ 1] = D[y][x][dir] + 1;
            q.push({y, x, dir ^ 1});
        }
    }

    cout << (D[ey][ex][edir] == -1 ? 0 : D[ey][ex][edir]);
}