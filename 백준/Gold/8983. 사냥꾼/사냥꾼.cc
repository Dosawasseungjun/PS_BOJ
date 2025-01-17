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
    int M, N, L; cin >> M >> N >> L;
    vector<int> x(M+1);
    for(int i=1;i<=M;i++) cin >> x[i];
    sort(x.begin(), x.end());
    x[0] = -1e9;
    int res = 0;
    for(int i=0;i<N;i++){
        int p, q; cin >> p >> q;
        int x1 = *lower_bound(x.begin(), x.end(), p);
        int x2 = *(--lower_bound(x.begin(), x.end(), p));
        int d = min(abs(x1-p)+q, abs(x2-p)+q);
        if(d <= L) res += 1;
    }
    cout << res;
}
