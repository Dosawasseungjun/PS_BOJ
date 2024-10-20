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
    ll x; cin >> x;
    vector<ll> ans;
    for(ll k=1;k*k<=x+1;k++){
        if((x+1)%k == 0){
            ans.push_back(k);
            if((x+1)/k <= x && (x+1)/k != k) ans.push_back((x+1)/k);
        }
    }
    sort(ans.begin(), ans.end());
    for(ll a : ans) cout << a << ' ';
}