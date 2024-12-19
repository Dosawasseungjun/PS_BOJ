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

struct ConvexHullTrick{
    deque<pll> dq;
    double crossPoint(pll line1, pll line2){
        return 1.0 * (line1.yy-line2.yy) / (line2.xx- line1.xx);
    }
    void insert_front(pll A){
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
    void insert_back(pll A){
        while((int)dq.size() > 1){
            pll B = dq.back();
            dq.pop_back();
            pll C = dq.back();

            if(crossPoint(C, B)<crossPoint(B, A)){
                dq.push_back(B);
                break;
            }
        }
        dq.push_back(A);
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
    ll query(ll x){
        while(dq.size() > 1&&crossPoint(dq[0], dq[1])<x) dq.pop_front();
        return dq[0].xx*x+dq[0].yy;
    }
    void clear(){
        dq.clear();
    }
}CHT;


void solv(){
    int n; cin >> n;
    vector<pll> a(n+1), b;
    for(int i=1;i<=n;i++) cin >> a[i].xx >> a[i].yy;
    for(int i=1;i<=n;i++){
        while(!b.empty() && a[i].xx <= CHT.crossPoint({1, -b.back().xx+b.back().yy}, {-1, a[i].xx+a[i].yy})) b.pop_back();
        if(!b.empty()&&CHT.crossPoint({1, -b.back().xx+b.back().yy}, {-1, a[i].xx+a[i].yy}) <= b.back().xx) continue;
        b.push_back(a[i]);
    }
    int N = b.size();
    vector<ll> dp(N, 1e18+1); // i번째 조각품까지 봤을 때, 최소 비용
    CHT.clear();
    CHT.insert_back({2*(b[0].yy-b[0].xx), (b[0].yy-b[0].xx)* (b[0].yy-b[0].xx)});
    for(int i=0;i<N;i++){
        ll x = b[i].xx + b[i].yy;
        ll v = (b[i+1].yy - b[i+1].xx);
        ll X = CHT.binary_query(x);
        dp[i] = min(dp[i], X + x*x);
        CHT.insert_back({2 * v, dp[i] + v * v});
    }
    vector<string> str = {".00", ".25", ".50", ".75"};
    cout << dp[N-1]/4 << str[dp[N-1]%4] << '\n';
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}