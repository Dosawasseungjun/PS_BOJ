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
    int n; cin >> n;
    string s, t; cin >> s >> t;
    const int INF = 2e9;
    //dp[i][j] : i번째 줄까지 올바르게 맞춘 상태고 왼쪽으로 j번 돌아간 상태일 때 최소 돌린 횟수
    vector dp = vector(n+1, vector<int>(10, INF));
    vector p = vector(n+1, vector<tiii>(10, {-1, -1, 0}));
    for(int i=0;i<10;i++) dp[0][i] = i;
    for(int i=1;i<=n;i++){
        int diff = t[i-1] - s[i-1];
        for(int j=0;j<10;j++){
            int left = (diff - j + 20) % 10 ;
            int right = 10 - left;
            if(dp[i][j] > dp[i-1][j] + right){
                dp[i][j] = dp[i-1][j] + right;
                p[i][j] = {i-1, j, -right};
            }
            if(dp[i][(j+left) % 10] > dp[i-1][j] + left){
                dp[i][(j + left) % 10] = dp[i-1][j] + left;
                p[i][(j + left) % 10] = {i-1, j, left};
            }
        }
    }
    int res = INF;
    int a =0, b = 0;
    for(int i=0;i<10;i++){
        if(res > dp[n][i]){
            res = dp[n][i];
            a = n; b = i;
        }
    }
    cout << res << '\n';

    function<void(int ,int)> reconstruct = [&](int i, int j){
        auto [ii, jj, turn] = p[i][j];
        if(ii == -1) return ;
        cout << i << ' ' << turn << '\n';
        reconstruct(ii, jj);
    };
    reconstruct(a, b);
}