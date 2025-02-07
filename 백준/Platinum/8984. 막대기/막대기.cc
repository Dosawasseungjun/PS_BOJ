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
    ll N, L; cin >> N >> L;
    vector<pll> sticks(N);
    vector<ll> compx, compy;
    for(int i=0;i<N;i++){
        cin >> sticks[i].xx >> sticks[i].yy;
        compx.push_back(sticks[i].xx);
        compy.push_back(sticks[i].yy);
    }
    vector<ll> dp1(N+1), dp2(N+1);
    sort(compx.begin(), compx.end());
    compx.erase(unique(compx.begin(), compx.end()), compx.end());
    sort(compy.begin(), compy.end());
    compy.erase(unique(compy.begin(), compy.end()), compy.end());
    sort(sticks.begin(), sticks.end());
    ll res = 0;
    for(int i=0;i<N;i++){
        ll t = lower_bound(compx.begin(), compx.end(), sticks[i].xx) - compx.begin();
        ll b = lower_bound(compy.begin(), compy.end(), sticks[i].yy) - compy.begin();

        ll ori1 = dp1[t], ori2 = dp2[b];
        ll len = abs(sticks[i].xx - sticks[i].yy) + L;
        dp1[t] = max(dp1[t], ori2 + len);
        dp2[b] = max(dp2[b], ori1 + len);
        res = max({res, dp1[t] ,dp2[b]});
    }
    cout << res;
}