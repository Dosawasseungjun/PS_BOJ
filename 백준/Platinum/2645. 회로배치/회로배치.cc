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
    int n; cin >> n;
    vector G = vector(n+1, vector<int>(n+1, 0));
    int sy, sx, ey, ex;
    cin >> sy >> sx >> ey >> ex;
    int k; cin >> k;
    int m; cin >> m;

    // 1. 길 미리 깔아두기
    for(int i=0;i<m;i++){
        int gn; cin >> gn;
        vector<pii> Ps(gn);
        for(int j=0;j<gn;j++){
            cin >> Ps[j].xx >> Ps[j].yy;
        }
        for(int j=1;j<gn;j++){
            int sm = (Ps[j-1].xx == Ps[j].xx ? Ps[j].xx : Ps[j].yy);
            int st = 0, ed = 0;
            if(Ps[j-1].xx == Ps[j].xx){
                st = min(Ps[j-1].yy, Ps[j].yy);
                ed = max(Ps[j-1].yy, Ps[j].yy);
                for(int jj=st;jj<=ed;jj++){
                    G[sm][jj] = 1;
                }
            }else{
                st = min(Ps[j-1].xx, Ps[j].xx);
                ed = max(Ps[j-1].xx, Ps[j].xx);
                for(int jj=st;jj<=ed;jj++){
                    G[jj][sm] = 1;
                }
            }
        }
    }
    // 2. 다익스트라로 문제해결하기
    const int INF = 2e9;
    vector D = vector(n+1, vector<int>(n+1, INF));
    vector P = vector(n+1, vector<pii>(n+1, {-1, -1}));
    function<void(int, int)> dijkstra = [&](int src_y, int src_x){
        D[src_y][src_x] = G[src_y][src_x] == 0 ? 1 : k;
        P[src_y][src_x] = {src_y, src_x};
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
        pq.push({D[src_y][src_x], {src_y, src_x}});
        while(!pq.empty()){
            int dist = pq.top().xx;
            int now_y = pq.top().yy.xx;
            int now_x = pq.top().yy.yy;
            pq.pop();

            if(dist > D[now_y][now_x]) continue;
            for(int i=0;i<4;i++){
                int next_y = now_y + dy[i];
                int next_x = now_x + dx[i];
                
                if(next_y >= 1 && next_y <= n && next_x >= 1 && next_x <= n){
                    if (!G[next_y][next_x] && D[next_y][next_x] > dist + 1){
                        D[next_y][next_x] = dist + 1;
                        P[next_y][next_x] = {now_y, now_x};
                        pq.push({D[next_y][next_x], {next_y, next_x}});
                    }
                    if(G[next_y][next_x] && D[next_y][next_x] > dist + k){
                        D[next_y][next_x] = dist + k;
                        P[next_y][next_x] = {now_y, now_x};
                        pq.push({D[next_y][next_x], {next_y, next_x}});
                    }
                }
            }
        }
    };
    dijkstra(sy, sx);
    // 3. 경로를 재구축하기
    vector<pii> path;
    function <void(pii)> reconstruct = [&](pii now){
        if(now.xx == sy && now.yy == sx) {path.push_back(now); return ;}
        reconstruct(P[now.xx][now.yy]);
        path.push_back(now);
    };
    reconstruct({ey, ex});
    //4. 경로 압축하기
    vector<pii> comp_path;
    int ny = sy, nx = sx;
    comp_path.emplace_back(sy, sx);
    int j = 1;
    while(ny != ey || nx != ex){
        int ddy = ny - path[j].xx;
        int ddx = nx - path[j].yy;

        int i = j+1;
        while((!ddy && (ny - path[i].xx == 0)) || (!ddx && (nx - path[i].yy) == 0)) i++;
        ny = path[i-1].xx;
        nx = path[i-1].yy;
        comp_path.emplace_back(ny, nx);
        j = i;
    }
    cout << D[ey][ex] << '\n';
    cout << comp_path.size() << ' ';
    for(auto [y, x] : comp_path) cout << y << ' ' << x << ' ';
}