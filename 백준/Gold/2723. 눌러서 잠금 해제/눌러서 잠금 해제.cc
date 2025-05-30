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
    vector<ll> DP[12];
    vector<ll> dp1(1 << (11), 1);
    dp1[0] =0;
    DP[1] = dp1;
    for(int k=1;k<11;k++){
        DP[k+1] = vector<ll> (1 << (11));
        for(int i=0;i<(1<<11);i++){
            for(int j=0;j<(1<<11);j++){
                if((i & j) == 0){
                    DP[k+1][i | j] += DP[k][i] * DP[1][j];
                }
            }
        }
    }
    while(n--){
        int b; cin >> b;
        int r = (1 << b);
        ll res = 0;
        for(int i=1;i<=b;i++){
            res += accumulate(DP[i].begin(), DP[i].begin() + r, 0);
        }
        cout << res << '\n';
    }
}