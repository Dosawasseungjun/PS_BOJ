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
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    ll s = 0;
    int res = 0;
    for(int i=n-1;i>=0;i--){
        s += a[i];
        if(s >=0 ){
            res += 1;
            s = 0;
        }
    }
    if(s < 0){
        cout << "-1\n";
    }else cout << res;
}