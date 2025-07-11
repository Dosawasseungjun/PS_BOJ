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
    int n; cin >> n;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin >> h[i];
    vector<int> a(n), b(n);
    int p1 = 0;
    for(int i=0;i<n;i++){
        if(p1 < h[i]) a[i] = ++p1;
        else a[i] = p1 = h[i];
    }
    int p2 = 0;
    for(int i=n-1;i>=0;i--){
        if(p2 < h[i]) b[i] = ++p2;
        else b[i] = p2 = h[i];
    }
    ll res = 0;
    for(int i=0;i<n;i++){
        res += min(a[i], b[i]);
    }
    cout << res;
}