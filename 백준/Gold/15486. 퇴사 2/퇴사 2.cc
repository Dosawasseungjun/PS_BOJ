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
    vector<pii> d(n+1);
    for(int i=1;i<=n;i++) cin >> d[i].xx >> d[i].yy;
    vector dp = vector(n+2, 0);
    for(int i=1;i<=n;i++){
        dp[i] = max(dp[i - 1], dp[i]);
        if(i + d[i].xx <= n+1) dp[i+d[i].xx] = max(dp[i+d[i].xx], dp[i] + d[i].yy);
    }
    cout << *max_element(dp.begin(), dp.end());
}