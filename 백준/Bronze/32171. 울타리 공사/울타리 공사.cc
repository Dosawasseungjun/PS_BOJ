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
    int nx = 11, mx = -11, ny = 11, my = -11;
    for(int i=0;i<n;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        nx = min(nx, a);
        mx = max(mx, c);
        ny = min(ny, b);
        my = max(my, d);
        cout << 2 * (my - ny + mx - nx) << '\n';
    }
}