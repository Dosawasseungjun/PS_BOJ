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

void solv(){
    int n; 
    double L, R;
    cin >> n >> L >> R;
    vector dp = vector(n+1, vector<double>(n+1)); 
    // dp[i][j] = i번 이동,  j번의 이동이 남았을 때 rightmost
    for(int i=1;i<=n;i++) dp[0][i] = i;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            dp[i][j] = L * (dp[i-1][j+1] - 1) + R * (dp[i-1][max(j-1, 0)] +  1) + (1 - L - R) * dp[i-1][j];
        }
    }
    cout.precision(4);
    cout << fixed;
    cout << dp[n][0] << '\n';
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}