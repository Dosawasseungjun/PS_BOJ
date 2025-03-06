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


ll cross(const pll &a, const pll &b, const pll &c){
    return (b.xx - a.xx) * (c.yy - a.yy) - (b.yy-a.yy) *(c.xx - a.xx);
}

ll dist(const pll &a, const pll &b){
    return (a.xx - b.xx)*(a.xx-b.xx) + (a.yy-b.yy)*(a.yy-b.yy);
}

int main(){
    fast_io
    int N; cin >> N;
    vector<pll> P(N);
    set<pll> st;
    for(int i=0;i<N;i++){
        cin >> P[i].xx >> P[i].yy;
    }
    if(N & 1){
        cout << "0\n";
        return 0;
    }
    vector<pll> neg, pos;
    for(int i=0;i<N;i++){
        pll prv = P[(i-1+N)%N];
        pll nxt = P[(i+1)%N];
        ll cp = cross(prv, P[i], nxt);
        if(cp > 0) pos.push_back(P[i]);
        else neg.push_back(P[i]);
    }
    const ll INF = 1e9+7;
    pll A = {INF, INF}, B = {INF, INF};
    if(neg.size() == 1 && pos.size() == N-1) B = neg.back();
    if(pos.size() == 1 && neg.size() == N-1) B = pos.back(); 
    if(neg.size() != 1 && pos.size() != 1){
        cout << "0\n";
        return 0;
    }
    int idx = -1;
    for(int i=0;i<N;i++){
        if(B == P[i]){
            idx = i;
            break;
        }
    }
    bool ok = true;
    A = P[(idx + N/2)%N];
    map<pll, int> mp;
    for(int i=0;i<N;i++){
        if(P[i] == A || P[i] == B) continue;
        ll x1 = dist(A, P[i]);
        ll x2 = dist(B, P[i]);
        mp[{x1, x2}] += 1;
    }
    for(auto [key, value] : mp){
        if(value != 2) ok = false;
    }

    cout << (ok ? "1\n" : "0\n");
}