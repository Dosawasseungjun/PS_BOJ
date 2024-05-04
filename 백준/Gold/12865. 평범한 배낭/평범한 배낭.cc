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

int dp[100001];
int main(){
    fast_io
    int n, k; cin >> n >> k;
    vector<pii> item(n+1);
    for(int i=1;i<=n;i++) cin >> item[i].xx >> item[i].yy;
    int res = 0;
    for(int i=1;i<=n;i++){
        for(int j=k;j>=0;j--){
            if(j + item[i].xx <= k){
                dp[j + item[i].xx] = max(dp[j + item[i].xx], dp[j] + item[i].yy);
                res = max(res, dp[j + item[i].xx]);
            }
        }
    }
    cout << res;
}