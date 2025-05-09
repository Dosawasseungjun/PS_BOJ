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
    vector<int> a(n), dp1(n), dp2(n);
    for(int i=0;i<n;i++) cin >> a[i];
    dp1[0] = a[0];
    dp2[n-1] = a[n-1];
    for(int i=1;i<n;i++){
        dp1[i] = max(dp1[i-1] + a[i], a[i]);
    }
    for(int i=n-2;i>=0;i--){
        dp2[i] = max(dp2[i+1] + a[i], a[i]);
    }
    for(int i=0;i<n;i++){
        cout << dp1[i] + dp2[i] - a[i] << ' ';
    }
}