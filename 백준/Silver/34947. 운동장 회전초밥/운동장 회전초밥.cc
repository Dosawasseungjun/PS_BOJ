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
    int n, t; cin >> n >> t;
    int r, d, theta, w; cin >> r >> d >> theta >> w;
    double rad = theta / 180.0 * M_PI;
    double r1 = r - w/200.0 ;
    double r2 = r1 - w ;
    double r3 = r2 - w;
    double s1 = 2 * r1 * rad + 2 * d + 4 * r1 * sin((M_PI - rad)/2);
    double s2 = 2 * r2 * rad + 2 * d + 4 * r2 * sin((M_PI - rad)/2);
    double s3 = 2 * r3 * rad + 2 * d + 4 * r3 * sin((M_PI - rad)/2);
    s1 *= n; s2 *= n; s3 *= n;

    cout << fixed;
    cout.precision(15);
    cout << (s1 - s3) / (100* t) << '\n';
    cout << (s1 - s2) / (100* t) << '\n';
}