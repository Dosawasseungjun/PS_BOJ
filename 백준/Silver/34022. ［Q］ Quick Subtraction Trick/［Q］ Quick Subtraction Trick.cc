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
    ll x, y;
    cin >> x >> y;

    ll a = 8*x;
    ll b = 2*y;
    ll c = 9*x;
    ll d = 3*y;

    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();   
}