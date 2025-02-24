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

template<int SZ, ll MOD> struct PrimeControl{
    vector<ll> P;
    ll p[SZ+1];
    void eratos(int sz = SZ){
        p[1] = 1;
        for(ll i=2;i<sz;i++){
            if(p[i]) continue;
            p[i] = i;
            P.push_back(i);
            for(ll j=i*i;j<sz;j += i) p[j] = i;
        }
    }
};

const int MAX = 1e5+1;
PrimeControl<MAX, numeric_limits<ll>::max()> pc;


int main(){
    fast_io
    pc.eratos();
    int n; cin >> n;
    vector<pii> ans;
    for(int i=1;i<=n;i++){
        if(i & 1) ans.push_back({1, i});
        if(pc.p[i] == i) continue;
        ans.push_back({2, i});
    }
    cout << ans.size() << '\n';
    for(auto [a, b] : ans){
        cout << a << ' ' << b << '\n';
    }
}