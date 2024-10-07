#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    ll a = 3, b = 2*n+1, c = 2 * n;
    ll p = 2, q = 1;
    vector<ll> ans;
    ans.push_back(p);
    ans.push_back(q);
    for(int i=0;i<n;i++){
        ll nxt = 0;
        if((i % 2)){
            ll x = q + a;
            ll y = q - a;
            ll f = p + c;
            ll g = p - c;
            if(x == f) nxt = x;
            else if(x == g) nxt = x;
            else if(y == f) nxt = y;
            else nxt = y;   
            a += 2;
        }else{
            ll x = q + b;
            ll y = q - b;
            ll f = p + c;
            ll g = p - c;
            if(x == f) nxt = x;
            else if(x == g) nxt = x;
            else if(y == f) nxt = y;
            else nxt = y;
            b -= 2;
        }
        p = q;
        q = nxt;
        ans.push_back(nxt);
        c -= 2;
        // cout << c << ' ';
    }
    for(ll an : ans) cout << an << ' ';
}