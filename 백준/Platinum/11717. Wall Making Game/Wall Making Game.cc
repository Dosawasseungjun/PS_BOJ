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
    int H, W;
    cin >> H >> W;
    vector G = vector(H, vector<char>(W));
    // S[r1][c1][r2][c2] : 네모 구역 왼쪽 위 -(r1, c1), 오른쪽 아래(r2, c2)일때 스프라그 그런디 수
    vector S = vector(H, vector(W, vector(H, vector<int>(W, -1))));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> G[i][j];
        }
    }

    function<int(int, int, int, int )> f = [&](int r1, int c1, int r2, int c2){
        // 기저 사례 범위 밖
        if(r1 < 0 || r1 >= H || c1 < 0 || c1 >= W || r2 <0 || r2 >= H || c2 < 0 || c2 >= W){
            return 0;
        }
        int &ret = S[r1][c1][r2][c2];
        if(ret != -1) return ret;
        ret = 0;
        bitset<401> mex;
        for(int i=r1;i<=r2;i++){
            for(int j=c1;j<=c2;j++){
                if(G[i][j] == 'X') continue;

                int x = 0;
                // 1사분면
                x ^= f(r1, j+1, i-1, c2);
                // 2사분면
                x ^= f(r1, c1, i-1, j-1);
                // 3사분면
                x ^= f(i+1, c1, r2, j-1);
                // 4사분면
                x ^= f(i+1, j+1, r2, c2);

                mex[x] = 1;
            }
        }
        while(mex[ret]) ret++;
        return ret;
    };

    cout << (f(0, 0, H-1, W-1) ? "First" : "Second");
}