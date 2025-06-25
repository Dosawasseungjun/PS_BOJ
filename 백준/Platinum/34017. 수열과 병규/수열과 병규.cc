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

ll S(ll n){
    if(n == 1) return 1;
    if(n == 2) return 3;
    if(n == 3) return 10;

    ll k = n / 3;
    if(n % 3 == 2){
        return 2*S(k) + 2*k + 3;
    }
    if(n % 3 == 1){
        return 2*S(k+2) + 2*k + 1;
    }
    return 2*S(k+1) + 2*k+2;
}

int main(){
    fast_io
    int q; cin >> q;
    while(q--){
        ll n; cin >> n;
        cout << S(n) << '\n';
    }
}