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

pll sub(pll u, pll v){
    return {u.xx-v.xx, u.yy-v.yy};
}


ll ccw(pll a, pll b, pll c){
    pll u, v;
    u = sub(b, a);
    v = sub(c, a);
    ll ret = u.xx*v.yy - u.yy*v.xx;
    if(ret) ret /= abs(ret);
    return ret;
}

double TriangleArea(pll a, pll b, pll c){
    return abs(a.xx*(b.yy - c.yy) + b.xx * (c.yy - a.yy) + c.xx * (a.yy - b.yy)) / 2.0;
}

bool isOnLine(pll a, pll b, pll c, pll x){
    if(ccw(a, b, x) == 0 && min(a, b) <= x && max(a, b) >= x) return true;
    if(ccw(b, c, x) == 0 && min(b, c) <= x && max(b, c) >= x) return true;
    if(ccw(c, a, x) == 0 && min(c, a) <= x && max(c, a) >= x) return true;
    return false;
}

int main(){
    fast_io
    pll p1, p2, p3;
    cin >> p1.xx >> p1.yy;
    cin >> p2.xx >> p2.yy;
    cin >> p3.xx >> p3.yy;
    cout << fixed;
    cout.precision(1);
    cout << TriangleArea(p1, p2, p3) << '\n';
    int N; cin >> N;
    int res = 0;
    pll tree; 
    for(int i=0;i<N;i++){
        cin >> tree.xx >> tree.yy;
        ll p = ccw(p1, p2, tree);
        ll q = ccw(p2, p3, tree);
        ll r = ccw(p3, p1, tree);
        if((p == q && q == r) || (isOnLine(p1, p2, p3,  tree))) res++;
    }
    cout << res;
}