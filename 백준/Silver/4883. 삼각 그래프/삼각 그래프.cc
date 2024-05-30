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

const int INF = 2e9+1;

int main(){
    fast_io
    int t = 1;
    while(1){
        int n; cin >> n;
        if(n == 0) break;
        vector a = vector(n+1, vector<int>(3));
        vector dp = vector(n+1, vector<int>(3, INF));
        for(int i=1;i<=n;i++) for(int j=0;j<3;j++) cin >> a[i][j];
        dp[1][1] = a[1][1];
        dp[1][2] = dp[1][1] + a[1][2];
        for(int i=2;i<=n;i++){
            dp[i][0] = min({dp[i][0], dp[i-1][0] + a[i][0], dp[i-1][1] + a[i][0]});
            dp[i][1] = min({dp[i][1], dp[i][0] + a[i][1], dp[i - 1][0] + a[i][1], dp[i - 1][1] + a[i][1], dp[i - 1][2] + a[i][1] });
            dp[i][2] = min({dp[i][2], dp[i][1] + a[i][2], dp[i - 1][1] + a[i][2], dp[i - 1][2] + a[i][2]});
        }
        cout << t++ << ". " << dp[n][1] << '\n';
    }
}