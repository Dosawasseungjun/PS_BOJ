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
    int N; cin >> N;
    int res = 1;
    for(int i=0;i<N;i++){
        int a, b; cin >> a >> b;
        if(a < 0) a += 1;
        if(b < 0) b += 1;
        int d = b - a;
        res += d;
    }
    if(res <= 0) res -= 1;
    cout << res;

}