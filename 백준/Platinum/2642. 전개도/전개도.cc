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

// 동서남북
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

int main(){
    fast_io
    vector G = vector(7, vector<int> (7));
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            cin >> G[i][j];
        }
    }
    vector vst = vector(7, vector<int>(7, 0));
    vector<int> mp;
    function<void (int, int, int, int)> dfs = [&](int y, int x, int dir, int cnt){
        vst[y][x] = 1;
        if(cnt == 2){
            mp.push_back(G[y][x]);
        }else{
            for(int i=0;i<4;i++){
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny >= 1 && ny <= 6 && nx >= 1 && nx <= 6 && G[ny][nx] && !vst[ny][nx]){
                    if(dir == -1){
                        dfs(ny, nx, i, 1);
                    }else if(dir == i){
                        dfs(ny, nx, dir, cnt+1);
                    }else{
                        dfs(ny, nx, dir, cnt);
                    }
                }
            }
        }
        
    };

    bool ok = true;
    vector<int> R(7, 0);
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            if(G[i][j]){
                mp.clear();
                vst = vector(7, vector<int>(7, 0));
                dfs(i, j, -1, 0);
                if(mp.size() != 1) ok = false;
                else{
                    R[G[i][j]] = mp[0];
                }
            }
        }
    }
    for(int i=1;i<=6;i++) if(i != R[R[i]]) ok = false;
    
    if(ok) cout << R[1];
    else cout << 0;
}