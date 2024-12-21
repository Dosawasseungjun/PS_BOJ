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
    vector<ll> a(n+1), ps(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        ps[i] = ps[i-1] + a[i];
    }
    if(ps[n] % 4){
        cout << "0";
    }else if(ps[n] == 0){
        ll k = 0;
        for(int i=1;i<=n;i++) if(!ps[i]) k++;
        cout << k * (k-1) * (k-2) / 6;
    }else{
        vector dp(n+1, vector<ll>(4));
        ll bkt = ps[n] / 4;
        dp[0][0]= 1;
        for(int i=1;i<=n;i++){
            dp[i][0] += dp[i - 1][0];
            dp[i][1] += dp[i - 1][1];
            dp[i][2] += dp[i - 1][2];
            dp[i][3] += dp[i - 1][3];
            if(ps[i] % bkt) continue;
            ll x = ps[i] / bkt;
            if(!x || x > 3) continue;
            dp[i][x] += dp[i-1][x-1];
        }
        cout << dp[n][3];
    }
}