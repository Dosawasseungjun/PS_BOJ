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

tuple<ll, ll, ll> xGCD(ll a, ll b) {
    if (!b) {
        return make_tuple(a, 1, 0);
    }
    ll g, x, y;
    tie(g, x, y) = xGCD(b, a%b);
    return make_tuple(g, y, x-(a/b)*y);
}

pll crt(vector<pll> dr){
  for(int i=0;i<dr.size()-1;i++){
      auto[d1, r1] = dr[i];
      auto[d2, r2] = dr[i+1];
      
      ll g = gcd(d1, d2);
      if(abs(r2-r1)%g) return {-1,-1};
      auto [G, s, t] = xGCD(d1/g, d2/g);
      ll lcm = d1/g*d2;
      s = (s%d2+d2)%d2;
      s *= (r2-r1)/g;
      s = (s%d2+d2)%d2;
      ll r = d1*s +r1;
      r %= lcm;
      if(r<0) r+= lcm;
      dr[i+1] = {lcm, r};
  }
  return dr.back();
}


int main(){
    fast_io
    int n; cin >> n;
    ll mx = 0 ;
    vector<pll> dr(n);
    for(pll &p : dr) cin >> p.yy >> p.xx, mx = max(mx, p.yy), p.yy %= p.xx;
    pll res = crt(dr);
    if(res.xx == -1) cout << "-1";
    else{
        while(res.yy < mx) res.yy += res.xx;
        cout << res.yy;
    }
    
}