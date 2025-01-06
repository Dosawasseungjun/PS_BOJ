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
    string s; cin >> s;
    int n = s.length();
    vector<ll> dp(n+1, 0);
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        ll k = 0;
        k += (s[i-1]-'0');
        if(k >= 1 && k <= 34) dp[i] += dp[i-1];
        if(i > 1){
            if(s[i-2] == '0') k = 0;
            else k += 10*(s[i-2]-'0');
        }
        if(i>1 && k >= 1 && k <= 34) dp[i] += dp[i-2];
    }
    cout << dp[n];
}