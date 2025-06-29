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

const ll inf = 1e18;

int main(){
    fast_io
    int n, m; cin >> n >> m;
    vector<pll> C(m+1);
    for(int i=1;i<=m;i++) cin >> C[i].xx >> C[i].yy;
    if(C.back().xx != n) C.push_back({n, 0});
    m = C.size()-1;
    vector dp = vector(m+1, vector<ll>(m+1, -inf));
    dp[0][0] = 0;
    
    for(int i=1;i<=m;i++){
        ll X = 0;
        for(int j=i-1;j>=0;j--){
            // 이전에 데이트를 시작한 곳
            ll st = C[j].xx+1;
            ll ed = C[i].xx;
            ll k = ed - st + 1;
            
            // 데이트를 이번에 안함
            dp[i][i] = max(dp[i][i], dp[j][j] + k*(k-1)/2 - X);
            
            // 데이트 이번에 함
            dp[i][j] = max(dp[i][j], dp[j][j] + k*(k+1)/2-C[i].yy - X);

            X += C[j].yy;
        }
    }

    ll res = 0;
    for(int i=0;i<=m;i++){
        res = max(res, dp[m][i]);
    }
    cout << res;
}