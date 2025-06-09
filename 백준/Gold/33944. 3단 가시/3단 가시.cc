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
    ll n; cin >> n;
    int x; cin >> x;
    vector<ll> P(x);
    unordered_map<int, int> mp;
    for(int i=0;i<x;i++){
        cin >> P[i];
        mp[P[i]] = 1;
    }
    bool ok = false;
    set<ll> dp;
    dp.insert(0);
    for(int i=0;i<x;i++){
        set<ll> ndp;
        for(ll pre : dp){
            if(pre > P[i]) ndp.insert(pre);
            for(ll j = max(pre+4, P[i]+1);j<=P[i]+3;j++){
                if(mp.count(j)) continue;
                ndp.insert(j);
            }
        }
        dp.swap(ndp);
    }
    
    if(!dp.empty()) ok = true;
    cout << (ok ? "POSSIBLE\n" : "IMPOSSIBLE\n");
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}