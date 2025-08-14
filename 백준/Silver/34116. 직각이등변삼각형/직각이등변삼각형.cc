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

const int INF = 1e9;

int main(){
    fast_io
    int n; cin >> n;
    vector<pii> p(n);
    for(int i=0;i<n;i++) cin >> p[i].xx >> p[i].yy;
    int res = INF;
    int k1 = -INF, k2 = -INF; // y = x + k1, y = -x + k2
    int k3 = INF, k4 = INF; // y = -x + k3, y = x + k4
    int mn_y = INF, mx_y = -INF;
    for(int i=0;i<n;i++){
        k1 = max(k1, p[i].yy - p[i].xx);
        k2 = max(k2, p[i].yy + p[i].xx);
        k3 = min(k3, p[i].yy + p[i].xx);
        k4 = min(k4, p[i].yy - p[i].xx);
        mn_y = min(mn_y, p[i].yy);
        mx_y = max(mx_y, p[i].yy);
    }
    int y_two = k1 + k2; // 2y = k1 + k2
    int y_two2 = k3 + k4;
    res = min(res, y_two - 2*mn_y); // 2(y - mn_y)
    res = min(res, 2*mx_y - y_two2);
    cout << res;
}