#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
#define xx first
#define yy second

struct ConvexHullTrick{
    deque<pll> dq;
    int pos = 0;
    double crossPoint(pll line1, pll line2){
        return 1.0 * (line1.yy-line2.yy) / (line2.xx- line1.xx);
    }
    void insert(pll A, int line_idx){
        while((int)dq.size() > 1){
            pll B = dq.front();
            dq.pop_front();
            pll C = dq.front();
            
            if(crossPoint(C, B)>crossPoint(B, A)){
                dq.push_front(B);
                break;
            }
        }
        dq.push_front(A);
    }
    ll binary_query(ll x){
        ll l = 0, r = dq.size();
        while(l+1<r){
            ll mid = (l+r)>>1;
            if(crossPoint(dq[mid-1], dq[mid])<=x) l = mid;
            else r = mid;
        }
        return dq[l].xx*x+dq[l].yy;
    }
}CHT;

int main() {
    fast_io
    ll n; cin >> n;
    vector<ll> a(n+1), dp(n+2), ps(n+1), ps2(n+1);
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        ps[i] = ps[i-1] + a[i];
        ps2[i] = ps2[i-1] + i*a[i];
    }
    //dp[i] = i까지 확인했을 때 최대 점수
    /* 
    1) i번째 선택 안했을 때
        dp[i] = dp[i-1]  
    2) i번째 선택 했을 때 (j+1~i까지 쭉 선택함 : j는 필연적으로 선택 안함 -> 1 <= j < i)
        dp[i] = max(dp[j-1] + 1*a[j+1]+2*a[j+2]+...+(i-j)*a[i]) 
              = max(dp[j-1] + ps2[i]-ps2[j]-j*(ps[i]-ps[j]))
            y = -j*ps[i] + dp[j-1] + j*ps[j] - ps2[j] + ps2[i] 
    */
   dp[0] = 0;
   dp[1] = max(dp[0], a[1]);
   CHT.insert({0, 0}, 0);
   CHT.insert({-1, dp[0]}, 1);
   for(ll i=2;i<=n;i++){
        ll X = CHT.binary_query(ps[i]);
        CHT.insert({-i, dp[i - 1] + i * ps[i] - ps2[i]}, 2);
        dp[i] = max(dp[i-1], X + ps2[i]);
   }
   cout << dp[n];
}