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
    int N, H; cin >> N >> H;
    vector<pii> C(N);
    for(int i=0;i<N;i++) cin >> C[i].xx >> C[i].yy;
    sort(C.begin(), C.end());
    vector<int> P;
    int pre = 1;
    for(int i=0;i<N;i++){
        if(pre < C[i].xx){
            P.push_back(C[i].xx - pre);
        }
        pre = max(pre, C[i].yy+1);
    }
    if(pre <= H) P.push_back(H + 1 - pre);
    sort(P.begin(), P.end());
    int M = P.size();
    vector<ll> ps(M+1);
    for(int i=1;i<=M;i++){
        ps[i] = ps[i-1] + P[i-1];
    }
    int Q; cin >> Q;
    while(Q--){
        int t_i; cin >> t_i;
        int idx = lower_bound(P.begin(), P.end(), t_i) - P.begin();
        ll sum = ps[M] - ps[idx];
        ll cnt = M - idx;
        ll res = sum - cnt * (t_i - 1) ;
        cout << res << '\n'; 
    }
}