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
    int n, m; cin >> n >> m;
    while(m--){
        vector<ll> a(n);
        ll m2 = 0, m1 = 0, z =0, p1 = 0, p2 = 0;
        ll res = -1e18;
        for(int i=0;i<n;i++) {
            cin >> a[i];
            res = max(res, a[i]);
            if(a[i] == -2) m2 += 1;
            else if(a[i] == -1) m1 += 1;
            else if(a[i] == 0) z += 1;
            else if(a[i] == 1) p1 += 1;
            else p2 += 1;
        }
        ll k = 0;
        if(m1){
            if(m1 > 1) res = max(res, 1LL);
            k += m2;
        }else{
            if(m2 & 1) k += m2 - 1;
            else k += m2;
        }
        k += p2;
        if(k) res = max(res, (1LL << k));
        cout << res << '\n';
    }
}