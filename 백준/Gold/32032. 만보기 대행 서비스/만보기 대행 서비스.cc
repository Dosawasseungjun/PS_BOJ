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
    ll N, D;
    cin >> N >> D;
    vector<ll> neg, pos;
    for(int i=0;i<N;i++){
        ll x; cin >> x;
        if(x < 0) neg.push_back(-x);
        else pos.push_back(x);
    }
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());
    if(neg.empty()){
        cout << 2 * pos.back() + D;
    }else if(pos.empty()){
        cout << 2 * neg.back() + D;
    }else{
        ll L = neg.back(), R = pos.back();
        ll res = 1e15;
        // L - LR - R - RR(left - left return - right - right return)
        res = min(res, L + D + L + R + D + R);
        // L - R - LL - RR
        res = min(res, L + L + R + R + L + max(0LL, D - 2 * (L + R)) + L + R + R);
        // R - L - RR - LL
        res = min(res, R + R + L + L + R + max(0LL, D - 2 * (L + R)) + R + L + L);
        // L - R - RR - LL
        res = min(res, L + L + R + D + L + R + L);
        // R - L - LL - RR
        res = min(res, R + R + L + D + R + L + R);
        cout << res;
    }
}