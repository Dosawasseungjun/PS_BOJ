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
    ll n, k; cin >> n >> k;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for(int i=0;i<k;i++) pq.push({0, i});
    vector<tlll> X;
    for(int i=0;i<n;i++){
        ll id, w; cin >> id >> w;
        pll x = pq.top();
        pq.pop();
        x.xx += w;
        X.push_back({x.xx, x.yy, id});
        pq.push(x);
    }
    sort(X.begin(), X.end(), [](const tlll & a, const tlll &b){
        auto [a1, a2, a3] = a;
        auto [b1, b2, b3] = b;
        if(a1 != b1) return a1 < b1;
        return a2 > b2;
    });
    ll res = 0;
    ll cnt = 0;
    for(auto [t, c, id] : X){
        res += (++cnt) * id;
    }
    cout << res;
}