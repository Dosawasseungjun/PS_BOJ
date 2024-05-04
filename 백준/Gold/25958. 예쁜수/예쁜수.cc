#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long  ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll m, k;
int pretty[5001];
ll dp[5001];

int main(){
    fast_io
    cin >> m >> k;
    for(int i=1;i<5001;i++) {
        int s = 0;
        int tmp = i;
        while (tmp / 10) {
            s += tmp % 10;
            tmp /= 10;
        }
        s += tmp;
        if (!(i % s)) pretty[i] = 1;
    }
    dp[0] = 1;
    for(int i=1;i<=m;i++){
        if(pretty[i]) {
            for (int j = i; j <= m; j++) {
                dp[j] += dp[j - i];
                dp[j] %= k;
            }
        }
    }

    cout << dp[m];
}
