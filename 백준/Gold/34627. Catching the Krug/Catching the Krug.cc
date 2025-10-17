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
    int n;
    pii k, d;
    cin >> n >> k.xx >> k.yy >> d.xx >> d.yy;
    
    int res = 0;
    if(d.xx > k.xx) res = max(res, d.xx);
    else if(d.xx < k.xx) res = max(res, n - d.xx);

    if(d.yy > k.yy) res = max(res, d.yy);
    else if(d.yy < k.yy) res = max(res, n - d.yy);


    cout << res << '\n';
    
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}