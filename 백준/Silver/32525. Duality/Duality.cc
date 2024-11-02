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

void solv(){
    int n; cin >> n;
    vector<tiii> P(n);
    set<pii> st;
    for(int i=0;i<n;i++){
        int x, y; cin >> x >> y;
        P[i] = {x, y, i+1};
        st.insert({x, y});
    }
    sort(P.begin(), P.end());
    int j = 0;
    vector<tiii> res;
    for(int i=0;i<n;i++){
        auto [x, y, k] = P[i];
        while(st.count({x+1, j})) j++;
        res.push_back({k, x+1, j}); j++;
    }
    for(auto [i, x, y] : res) cout << i << ' ' << x << ' ' << y << '\n';
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}