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
    vector<int> a(n+1), ps(n+1);
    for(int i=1;i<=n;i++) cin >> a[i], ps[i] = ps[i-1] + a[i];
    int m; cin >> m;
    // dp[i][3] : i까지 j개의 소형 기관차를 이용해서 끌고 갔을 때 최대 손님 수
    // dp[i][j] = dp[i-m][j-1] + c(i-m+1~i) 
    const int INF = 1e9;
    vector dp = vector(n+1, vector<int>(4, -INF));
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        dp[i][0] = dp[i-1][0];
        for(int j=1;j<=3;j++){
            dp[i][j] = dp[i-1][j];
            if(i>=m) dp[i][j] = max(dp[i][j], dp[i-m][j-1] + (ps[i]-ps[i-m]));
        }
    }
    cout << dp[n][3];
}