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

const ll INF = 1e9+1;
int main(){
    fast_io
    int N, Q; cin >> N >> Q;
    vector<ll> H(N+2), D(N+1);
    for(int i=1;i<=N;i++) cin >> H[i];
    H[0] = -INF;
    for(int i=0;i<N;i++) D[i] = H[i+1]-H[i];
    set<pll> st;
    map<ll, ll> mp;
    for(int i=0 ;i<N;i++){
        if(D[i] > 0) st.insert({D[i], i}), mp[i] = D[i];
    }
    
    vector<pll> Query(Q);
    vector<ll> ans(Q);
    for(int i=0;i<Q;i++){
        ll K; cin >> K;
        Query[i] = {K, i};
    }
    sort(Query.begin(), Query.end());

    
    ll curT = 0;
    int j = 0;
    while(!st.empty()){
        auto [gap, idx]  = *st.begin();
        st.erase(st.begin());
        if(idx == 0) break;

        auto it = --mp.find(idx);
        ll idx2 = it -> first;
        ll pregap = it->second;
        mp.erase(++it);
        st.erase(st.find({pregap, idx2}));
        st.insert({pregap+gap, idx2});
        mp[idx2] = pregap+gap;
        while(j < Q && Query[j].xx <= curT + gap * (idx-idx2)){
            ll sz = idx - idx2;
            ll kk = Query[j].xx - curT;
            // if(idx2 == 0 && sz <= 2) ans[Query[j].yy] = H[N] - (H[1] + kk / sz);
            if(idx2 == 0) ans[Query[j].yy] = H[N] - (H[1] + kk/sz);
            else ans[Query[j].yy] = H[N] - H[1];
            j++;
        }
        H[idx] += gap;
        if(idx != idx2 + 1) H[idx2+1] += gap;
        curT += gap * (idx-idx2);
        
    }

    for(ll a : ans) cout << a << '\n';
}