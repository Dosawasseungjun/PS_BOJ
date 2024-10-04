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
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    bool ok = true;
    for(int i=1;i<n;i++){
        a[i] -= a[i-1] - 1;
        if(a[i] <= 0 && i != n-1) ok = false;
    }
    ok &= (a[n-1] == 0 || a[n-1] == 1);
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}