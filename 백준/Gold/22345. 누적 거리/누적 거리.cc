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
    ll N, Q; cin >> N >> Q;
    vector<pll> V(N); // xx = 거리, yy = 사람수
    for(int i=0;i<N;i++){
        cin >> V[i].yy >> V[i].xx;
    }
    sort(V.begin(), V.end());
    vector<ll> ps(N), ps2(N);
    for(int i=0;i<N;i++){
        ps[i] = (i==0 ? 0 : ps[i-1]) + V[i].yy;
        ps2[i] = (i==0 ? 0 : ps2[i-1]) + V[i].xx*V[i].yy;
    }
    for(int i=0;i<Q;i++){
        ll x; cin >> x;
        ll lo = -1, hi = N;
        while(lo + 1 < hi){
            ll mid = (lo + hi) >> 1; 
            if(V[mid].xx <= x) lo = mid;
            else hi = mid;
        }
        ll res = 0;
        res += x*(lo == -1 ? 0 : ps[lo]);
        res -= x*(ps[N-1] - (lo == -1 ? 0 : ps[lo]));
        res -= (lo == -1 ? 0 : ps2[lo]);
        res += (ps2[N-1] - (lo == -1 ? 0 : ps2[lo]));
        cout << res << '\n';
    }
}