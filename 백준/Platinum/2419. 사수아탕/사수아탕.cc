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

int dp[301][301][2];

int main(){
    fast_io
    int n, m; cin >> n >> m;
    vector<int> pos(n);
    bool is_zero = false;
    for(int i=0;i<n;i++) {
        cin >> pos[i];
        if(pos[i] == 0) is_zero = true;
    }
    if(!is_zero) pos.push_back(0);
    sort(pos.begin(), pos.end());
    // [s, e]끼지의 사탕은 모두 먹었고 현재 위치가 s인가(0) e인가(1)
    function<int(int, int, int, int)> f = [&](int l, int r, int k, int c){
        if(c == 0) return 0;
        if(l == 0 && r == n-1) return 0;
        int &ret = dp[l][r][k];
        if(ret != -1) return ret;

        ret = 0;
        int now = (k ? r : l);

        if(l > 0){ // 왼쪽꺼 먹음
            ret = max(ret, f(l-1, r, 0, c-1) + m - (pos[now]-pos[l-1])*c);
        }
        if(r < n-1){ // 오른쪽꺼 먹음
            ret = max(ret, f(l, r+1, 1, c-1) + m - (pos[r+1]-pos[now])*c);
        }
        return ret;
    };
    n = pos.size();
    int st = lower_bound(pos.begin(), pos.end(), 0) - pos.begin();
    int ans = 0;
    for(int i=0;i<n;i++){
        memset(dp, -1, sizeof(dp));
        int res = (is_zero ? m : 0) + f(st, st, 0, i);
        ans = max(ans, res);
    }
    cout << ans;
}