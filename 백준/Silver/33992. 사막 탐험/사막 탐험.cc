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

double dist(ll x1, ll y1, ll x2, ll y2){
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int main(){
    fast_io
    ll a_x, a_y, b_x, b_y, p_x, p_y, r;
    cin >> a_x >> a_y >> b_x >> b_y >> p_x >> p_y >> r;
    double a_to_p = max(0.0, dist(a_x, a_y, p_x, p_y) - r);
    double p_to_b = max(0.0, dist(b_x, b_y, p_x, p_y) - r);
    double res = min(dist(a_x, a_y, b_x, b_y), a_to_p + p_to_b);
    cout << fixed;
    cout.precision(15);
    cout << res;
}