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
    ll g, l; cin >> g >> l;
    ll A = g, B = g;
    ll k = l / g;
    ll mn = 2e15+1;
    for(ll i=1;i*i <= k;i++){
        if((k%i) == 0){
            ll x = i;
            ll y = k/i;
            if(gcd(x, y) == 1 && x + y < mn){
                mn = x + y;
                A = g*x;
                B = g*y;
            }
        }
    }
    cout << A << ' ' << B;
}
    