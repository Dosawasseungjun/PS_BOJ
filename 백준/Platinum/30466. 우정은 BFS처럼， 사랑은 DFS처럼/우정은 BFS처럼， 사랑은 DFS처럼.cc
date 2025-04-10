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
    ll n; cin >> n;
    ll k = n / 2;
    ll res = (k-1) * (n-k-1) + (k-1) * (n-k-1);
    
    cout << res << '\n';
    for(int i=2;i<=k+1;i++){
        cout << 1 << ' ' << i << '\n';
    }
    for(int i=k+2;i<=n;i++){
        cout << 2 << ' ' << i << '\n';
    }
}