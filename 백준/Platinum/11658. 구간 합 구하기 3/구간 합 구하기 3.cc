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

int N, M;
class BIT2D {
public:
    int n, m;
    vector<vector<ll>> bit;
    BIT2D(int n, int m): n(n), m(m) {
        bit.assign(n+1, vector<ll>(m+1, 0));
    }
    // (x, y)에 delta만큼 더하는 점 업데이트 (1-indexed)
    void update(int x, int y, ll delta) {
        for(int i = x; i <= n; i += (i & -i)) {
            for(int j = y; j <= m; j += (j & -j))
                bit[i][j] += delta;
        }
    }
    // (x, y)까지의 누적합 (1-indexed)
    ll query(int x, int y) {
        ll res = 0;
        for(int i = x; i > 0; i -= (i & -i)) {
            for(int j = y; j > 0; j -= (j & -j))
                res += bit[i][j];
        }
        return res;
    }
    // (x1,y1) ~ (x2,y2) 범위 합
    ll query(int x1, int y1, int x2, int y2) {
        return query(x2,y2) - query(x1-1,y2) - query(x2,y1-1) + query(x1-1,y1-1);
    }
};

int main(){
    fast_io
    cin >> N >> M;
    BIT2D seg2D(N, N);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            ll x; cin >> x;
            // cout << seg2D.query(i, i, j, j, 1, 1, N) << ' ';
            seg2D.update(i, j, x);
        }
        // cout << '\n';
    }
    while(M--){
        int op; cin >> op;
        if(op){
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << seg2D.query(x1, y1, x2, y2) << '\n';
        }else{
            int x, y; ll c; cin >> x >> y >> c;
            seg2D.update(x, y, c-seg2D.query(x, y, x, y));
        }
    }
}