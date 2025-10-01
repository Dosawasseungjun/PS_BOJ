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
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    int res = n;
    // 1. toggle해서 만들기
    int r1 = 0;
    for(int i=0;i<n;i++){
        if(a[i] != b[i]) r1 += 1;
    }
    res = min(res, r1);

    // 2. 전체 체크 후 만들기
    int c = 0;
    for(int i=0;i<n;i++){
        if(a[i]) c++;
    }
    int r2 = (c == n ? 0 : 1);
    for(int i=0;i<n;i++){
        if(!b[i]) r2 += 1;
    }
    res = min(res, r2);

    // 3. 전체 해제 후 만들기
    int r3 = (c == 0 ? 0 : 2);
    if(c == n) r3 = 1;
    for(int i=0;i<n;i++){
        if(b[i]) r3 += 1;
    }
    res = min(res, r3);
    cout << res;
}