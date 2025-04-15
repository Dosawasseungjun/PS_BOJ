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

const int mod = 1e9+7;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int D[(1 << 9)][(1 << 9)][(1 << 8)];
bool vst[(1 << 9)][(1 << 9)][(1 << 8)];
bool O[(1 << 9)][(1 << 9)];


int main(){
    fast_io
    int x, y; cin >> x >> y; // 얘가 (200, 200)으로 생각
    int T; cin >> T;
    int hx, hy; cin >> hx >> hy;
    int N; cin >> N;
    int DX = -x + 200; int DY = -y + 200;

    x += DX; y += DY; 
    hx += DX; hy += DY; 

    for(int i=0;i<N;i++){
        int ox, oy;
        cin >> ox >> oy;
        
        int kx = ox + DX;
        int ky = oy + DY;
        if(kx >= 0 && kx <= 400 && ky >= 0 && ky <= 400){
            O[kx][ky] = 1;
        }
    }


    if(hx < 0 || hx > 400 || hy < 0 || hy > 400){
        cout << 0;
        return 0;
    }

    vector<pii> cand;
    cand.push_back({x, y});
    D[x][y][0] = 1;
    for(int i=0;i<=T;i++) vst[hx][hy][i] = 1; // 집에서 다시 출발하는 경우는 없음...;;
    for(int i=1;i<=T;i++){
        vector<pii> new_cand;
        for(auto [cx, cy] : cand){
            for(int j=0;j<4;j++){
                int nxt_x = cx + dx[j];
                int nxt_y = cy + dy[j];

                if(nxt_x >= 0 && nxt_x <= 400 && nxt_y >= 0 && nxt_y <= 400 && !O[nxt_x][nxt_y]){
                    if(!vst[nxt_x][nxt_y][i]){
                        vst[nxt_x][nxt_y][i] = 1;
                        new_cand.push_back({nxt_x, nxt_y});
                    }
                    D[nxt_x][nxt_y][i] = (D[nxt_x][nxt_y][i] + D[cx][cy][i-1]) % mod;
                }
            }
        }
        cand = new_cand;
    }
    int ans = 0;
    for(int i=0;i<=T;i++){
        ans += D[hx][hy][i];
        ans %= mod;
    }
    cout << ans;
}