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
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int q; cin >> q;
    while(q--){
        int x, y, t1, t2, t3;
        cin >> x >> y >> t1 >> t2 >> t3;
        int a = abs(x - x1) + abs(y - y1);
        int b = abs(x - x2) + abs(y - y2);
        int c = abs(x - x3) + abs(y - y3);
        
        a = t1 * ((a-1) / t1 + 1);
        b = t2 * ((b-1) / t2 + 1);
        c = t3 * ((c-1) / t3 + 1);

        cout << min({a, b, c}) << '\n';
    }
}