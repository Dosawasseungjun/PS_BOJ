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
    vector dp = vector(n+2, vector<int>(n+2));
    vector dp2 = vector(n+1, 0);
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            for(int k=j;k<=i;k++){
                dp[j][i] = max(dp[j][i], dp[j][k-1] + dp[k][i]);
                if((s[k-1]=='a' && s[i-1] == 't') || (s[k-1] == 'g' && s[i-1] == 'c')){
                dp[j][i] = max(dp[j][i], dp[j][k-1] + dp[k+1][i-1] + 2);
            }
            }
        }
    }
    cout << dp[1][n];
}