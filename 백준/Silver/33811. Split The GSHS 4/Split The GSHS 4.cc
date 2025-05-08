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
    string s; cin >> s;
    vector<int> A;
    for(int i=0;i<n-3;i++){
        string k = s.substr(i, 4);
        if(k == "GSHS") A.push_back(-1);
        else if(k == "SSHS") A.push_back(1);
    }
    int m = A.size();
    if(m == 0){
        cout << 0;
        return 0;
    }
    vector<int> dp(m);
    dp[0] = max(0, A[0]);
    int res = dp[0];
    for(int i=1;i<m;i++){
        dp[i] = max(dp[i-1] + A[i], A[i]);
        res = max(res, dp[i]);
    }
    cout << res;
}