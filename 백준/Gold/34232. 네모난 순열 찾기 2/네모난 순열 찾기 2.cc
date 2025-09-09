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
    vector A = vector(n, vector<int>(n));
    vector<pii> C(n*n+1, {-1, -1});
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> A[i][j];
            C[A[i][j]] = {i, j};
        }
    }
    int mx_y = -1, mx_x = -1, mn_y = 1001, mn_x = 1001;
    int res = 0;
    for(int i=1;i<=n*n;i++){
        mx_y = max(mx_y, C[i].xx);
        mx_x = max(mx_x, C[i].yy);
        mn_y = min(mn_y, C[i].xx);
        mn_x = min(mn_x, C[i].yy);
        if(i == (mx_y - mn_y + 1)*(mx_x - mn_x + 1)) res += 1;
    }
    cout << res;
}