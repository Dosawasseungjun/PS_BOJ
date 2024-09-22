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
    int R, C; cin >> R >> C;
    int N; cin >> N;
    // x_min, y_min, x_max, y_max
    vector<pair<pll, pll>> box(N+1, {{100001, 100001}, {0, 0}});
    for(int i = 0;i<N;i++){
        ll a, r, c;
        cin >> a >> r >> c;
        box[a].xx.xx = min(box[a].xx.xx, r);
        box[a].xx.yy = min(box[a].xx.yy, c);
        box[a].yy.xx = max(box[a].yy.xx, r);
        box[a].yy.yy = max(box[a].yy.yy, c);
    }
    int ans = 0;
    ll res = 0;
    for(int i=1;i<=N;i++){
        ll B = -1;
        if ((box[i].yy.xx - box[i].xx.xx + 1) > 0 && (box[i].yy.yy - box[i].xx.yy + 1))
            B = (box[i].yy.xx - box[i].xx.xx + 1) * (box[i].yy.yy - box[i].xx.yy + 1);
        if(res < B){
            ans = i;
            res = B;
        }
    }
    cout << ans << ' ' << res;
}