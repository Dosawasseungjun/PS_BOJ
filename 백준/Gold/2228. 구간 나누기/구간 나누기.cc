#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
#define xx first
#define yy second

int n, m;
int dp[101][51], ps[101];

int main(){
    fast_io
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> ps[i];
        ps[i] += ps[i-1];
    }
    for(int i=1;i<=m;i++) dp[0][i] = -1e9;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = dp[i-1][j];
            for(int k=1;k<=i;k++){
                if(k==1&&j==1) dp[i][j] = max(dp[i][j], ps[i]);
                else if(k>=2){
                    dp[i][j] = max(dp[i][j], dp[k-2][j-1]+ps[i]-ps[k-1]);
                }
            }
        }
    }
    cout << dp[n][m];
}
