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

const int MAX = 1e6+2;
const ll MOD = 1e9+7;
// dp1[i] : i번째가 비어있을 때, i까지 k연강 없는 경우의 수
// dp2[i] : i번째가 비어있을 때, i까지 k연강 있는 경우의 수
ll n, k, a[MAX], dp1[MAX], dp2[MAX], pfx1[MAX], pfx2[MAX];

int main(){
    fast_io
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    dp1[0] = pfx1[0] = 1;

    for(ll i=1;i<=n+1;i++){
        dp1[i] += pfx1[i - 1] - ((i - min(i, k)) ? pfx1[i - min(i, k) - 1] : 0);
        dp2[i] += pfx2[i - 1] - ((i - min(i, k)) ? pfx2[i - min(i, k) - 1] : 0);

        if (i >= k && !a[i-k-1]){
            dp2[i] += dp1[i-k-1] + dp2[i-k-1];
        }

        dp1[i] %= MOD;
        dp2[i] %= MOD;

        pfx1[i] = (pfx1[i-1] + (!a[i])*dp1[i]) % MOD;
        pfx2[i] = (pfx2[i-1] + (!a[i])*dp2[i]) % MOD;
    }

    cout << (dp2[n+1] %MOD + MOD) % MOD;
}