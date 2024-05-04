#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX = 1001;
int n;
int a[MAX], dp[MAX];

int main() {
    fast_io
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(a[i]>a[j]) dp[i] = max(dp[i], dp[j]+1);
        }
    }
    int res = 0;
    for(int i=0;i<n;i++) res = max(res, dp[i]);
    cout << res;
}
