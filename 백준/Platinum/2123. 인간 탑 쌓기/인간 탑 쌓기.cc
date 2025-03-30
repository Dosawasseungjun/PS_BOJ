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
    ll S = 0;
    vector<pll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].xx >> a[i].yy;
        S += a[i].xx;
    }
    sort(a.begin(), a.end(), [&](const pll &p, const pll& q){
        ll sp = p.xx + p.yy;
        ll sq = q.xx + q.yy;
        if(sp != sq) return sp > sq;
        return p.xx > q.xx;
    });
    ll res = -1e18;
    for(int i=0;i<n;i++){
        res = max(res, S - a[i].xx - a[i].yy);
        S -= a[i].xx;
    }
    cout << res;
}