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

const int INF = 1e9;

int main(){
    fast_io
    int N, K; cin >> N >> K;
    vector C = vector(N+1, vector<int> (N+1));
    vector ps = vector(N+1, vector<int> (N+1));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> C[i][j];
            ps[i][j] = ps[i][j-1] + C[i][j];
        }
    }
    vector dp1 = vector(N+1, vector<int> (N+1, -1));

    function<int(int, int)> f = [&](int l, int r){
        if(l == r) return 0;
        int &ret = dp1[l][r];
        if(ret != -1) return ret;
        ret = (ps[l][r] - ps[l][l]) + f(l+1, r);
        return ret;
    };
    
    vector dp = vector(N+1, vector<int>(N+1, INF));
    function<void(int, int, int, int, int)> dnc = [&](int x, int l, int r, int optl, int optr){
        if(l > r) return ;

        int mid = (l + r) >> 1;
        int opt = optl;
        dp[mid][x] = INF;
        for(int k=optl;k<min(mid, optr+1);k++){
            int cost = f(k+1, mid);
            if(dp[mid][x] > dp[k][x-1] + cost){
                dp[mid][x] = dp[k][x-1] + cost;
                opt = k;
            }
        }
        dnc(x, l, mid-1, optl, opt);
        dnc(x, mid+1, r, opt, optr);
    };
    
    dp[0][0] = 0;
    for(int i=1;i<=N;i++) dp[i][0] = INF;  // 0그룹으로 i>0개는 불가능
    for(int i=1;i<=K;i++) dnc(i, 1, N, 0, N);
    cout << dp[N][K];
}