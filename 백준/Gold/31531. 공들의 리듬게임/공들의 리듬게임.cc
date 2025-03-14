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
    vector<ll> R, L, M;
    for(int i=0;i<n;i++) {
        ll a, d;
        cin >> a >> d;
        if(d == 0){
            M.push_back(a);
        }else if(d == 1){
            R.push_back(a);
        }else{
            L.push_back(a);
        }
    }
    sort(R.begin(), R.end());
    sort(L.begin(), L.end());
    sort(M.begin(), M.end());
    ll ans = 0;
    for(ll r : R){
        // r보다 오른쪽에 있는 애들은 통과하면서 점수를 얻음
        ll lc = L.size() - (lower_bound(L.begin(), L.end(), r) - L.begin());
        ll mc = M.size() - (lower_bound(M.begin(), M.end(), r) - M.begin());
        ans += lc;
        ans += 2*mc;
    }
    for(ll l : L){
        // l보다 왼쪽에 있는 가만히 있는 것들
        ll mc = lower_bound(M.begin(), M.end(), l) - M.begin();
        ans += 2*mc;
    }
    cout << ans;
}