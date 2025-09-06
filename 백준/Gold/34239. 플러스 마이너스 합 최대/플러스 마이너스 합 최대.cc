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

const ll inf = 1e18;

int main(){
    fast_io
    int n; cin >> n;
    vector<ll> A(n+1), dp1(n+1, -inf), dp2(n+1, -inf);
    for(int i=1;i<=n;i++){
        cin >> A[i];
    }
    ll res = -inf;
    for(int i=1;i<=n;i++){
        if(i & 1){
            dp1[i] = max(dp1[i-1] + A[i], A[i]);
            dp2[i] = max(dp2[i], dp2[i - 1] - A[i]);
        }else{
            dp1[i] = max(dp1[i], dp1[i-1] - A[i]);
            dp2[i] = max(dp2[i - 1] + A[i], A[i]);
        }
        res = max({res, dp1[i], dp2[i]});
    }
    cout << res;
}