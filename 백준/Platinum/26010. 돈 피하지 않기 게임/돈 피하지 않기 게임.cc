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

const ll INF = 1e18;

int main(){
    fast_io
    ll N, P1, P2;
    cin >> N >> P1 >> P2;
    vector<pll> P(N+1);
    P[0] = {0, 0};
    for(int i=1;i<=N;i++){
        cin >> P[i].xx >> P[i].yy;
    }
    sort(P.begin(), P.end(), [&](const pll& a, const pll& b){
        if(a.yy != b.yy) return a.yy < b.yy;
        return a.xx < b.xx;
    });
    for(int i=1;i<=N;i++){
        ll l = i, r = i+1;
        while(r <= N && P[l].yy == P[r].yy) r++;
        // 같은 y좌표가 3개 이상이거나 옆에 붙어있는데 1칸 이상 떨어져 있는 상황은 불가능
        if(r - l > 2 || r - l == 2 && P[l].xx+1<P[r-1].xx){
            cout << "-1";
            return 0;
        }
        i = r-1;
    }
    // vector dp = vector(N, vector(2, vector<ll>(2, INF)));
    map<pll, ll> dp;
    dp[{0, 0}] = 0;
    for(int i=1;i<=N;i++){
        ll l_idx = i, r_idx = i+1;
        while(r_idx <= N && P[r_idx].yy == P[l_idx].yy) r_idx++;
        vector<vector<array<ll, 3>>> XDP(r_idx-l_idx);
        map<pll, ll> ndp;
        for(auto [tup, power] : dp){
            auto [prev, jumped] = tup;
            auto [px, py] = P[prev];
            for(int ii=l_idx;ii<r_idx;ii++){
                auto [nx, ny] = P[ii];
                ll ppx = px;
                ll ppy  = py - jumped; //점프해서 먹어서 여기 있음.
                for(int jp=0;jp<=1;jp++){
                    ll nnx = nx;
                    ll nny = ny - jp;
                    ll dp_val = INF;
                    if(nny <= 0 || abs(nnx-ppx) > nny - ppy) dp_val = INF;
                    else{
                        dp_val = power + abs(nnx-ppx) * P1 + jp*P2;
                    }
                    if(dp_val != INF) XDP[ii-l_idx].push_back({ii, jp, dp_val});
                }
            }

            if(XDP.size() == 2){
                for(auto v1 : XDP.front()){
                    for(auto v2 : XDP.back()){
                        if(v1[1] && !v2[1]){
                            if(ndp.count({v2[0], 0})) ndp[{v2[0], 0}] = min(ndp[{v2[0], 0}], v1[2] + P1);
                            else ndp[{v2[0], 0}] = v1[2] + P1;
                        }else if(!v1[1] && v2[1]){
                            if(ndp.count({v1[0], 0})) ndp[{v1[0], 0}] = min(ndp[{v1[0], 0}], v2[2] + P1);
                            else ndp[{v1[0], 0}] = v2[2] + P1;
                        }
                    }
                }
            }else{
                for(auto v : XDP.front()){
                    if(ndp.count({v[0], v[1]})) ndp[{v[0], v[1]}] = min(ndp[{v[0], v[1]}] , v[2]) ;
                    else ndp[{v[0], v[1]}] = v[2];
                }
            }
        }


        i = r_idx-1;
        dp.swap(ndp);
    }

    ll res = INF;
    for(auto [tup, power] : dp){
        res = min(res, power);
    }
    cout << (res == INF ? -1 : res);
}