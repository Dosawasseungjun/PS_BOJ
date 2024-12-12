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

// 타일에 들어오는 방향(0 - 위, 1- 오른, 2-아래,3-왼) + 타일 종류 -> 다음에 어디로 가야할지 mapping
map<pii, tiii> mp; 

int main(){
    fast_io
    mp[{1, 0}] = {1, 0, 0}; mp[{2, 0}] = {0, 1, 3};
    mp[{3, 1}] = {1, 0, 0}; mp[{2, 1}] = {0, -1, 1};
    mp[{0, 2}] = {0, 1, 3}; mp[{1, 2}] = {-1, 0, 2};
    mp[{0, 3}] = {0, -1, 1}; mp[{3, 3}] = {-1, 0, 2};
    mp[{0, 4}] = {1, 0, 0}; mp[{2, 4}] = {-1, 0, 2};
    mp[{3, 5}] = {0, 1, 3}; mp[{1, 5}] = {0, -1, 1};
    int n, k; cin >> n >> k;
    vector G = vector(n+2, vector<int>(n+2));
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> G[i][j];
    int res = 1e9;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int ori = G[i][j];
            for(int x=0;x<6;x++){
                if(k){
                    G[i][j] = x;
                    if(x == ori) continue;
                }
                vector d1 = vector(n + 1, vector<int>(n + 1, -1));
                int dir = 3;
                d1[1][0] = 0;
                queue<tiii> q;
                G[1][0] = 5;
                q.push({dir, 1, 0});
                while (!q.empty())
                {
                    auto [d, hy, hx] = q.front();
                    q.pop();
                    tiii dd = mp[{d, G[hy][hx]}];
                    auto [dy, dx, ndir] = dd;
                    int ny = hy + dy, nx = hx + dx;
                    if (ny > n || ny < 1 || nx > n || nx < 1 || d1[ny][nx] != -1)
                        continue;
                    if(mp.count({ndir, G[ny][nx]})){
                        d1[ny][nx] = d1[hy][hx] + 1;
                        q.push({ndir, ny, nx});
                    }
                    
                }

                if(d1[n][n] != -1 && (G[n][n] == 5 || G[n][n] == 2)) res = min(res, d1[n][n]);
            }
            G[i][j] = ori;
        }
    }
    if(res == 1e9) res = -1;
    cout << res;
}