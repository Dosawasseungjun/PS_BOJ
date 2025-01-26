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
    int N, K; cin >> N >> K;
    vector<int> a(N+1);
    for(int i=1;i<=N;i++) cin >> a[i];
    const int INF = 1e9+1;
    vector dp(N+1, vector(N+1, vector<int> (K+1, INF)));

    function<int (int, int, int)> mktb = [&](int l, int r, int k){
        int &ret = dp[l][r][k];
        if(ret != INF) return ret;

        if(l == r){
            return (ret = (a[l] == k ? 0 : 1));
        }

        for(int i=l;i<r;i++){
            ret = min(ret, mktb(l, i, k) + mktb(i+1, r, k));
        }
        for(int i=1;i<=K;i++){
            if(i == k) continue;
            ret = min(ret, mktb(l, r, i) + 1);
        }
        return ret;
    };

    int res = INF;
    for(int i=1;i<=K;i++){
        res = min(res, mktb(1, N, i));
    }
    cout << res;
}