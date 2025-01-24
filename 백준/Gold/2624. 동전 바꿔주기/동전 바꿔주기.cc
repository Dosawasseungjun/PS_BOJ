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
    int T; cin >> T;
    int k; cin >> k;
    vector<pii> C(k);
    for(int i=0;i<k;i++){
        int p, n; cin >> p >> n;
        C[i] = {p, n};
    }
    vector dp(T+1, vector<int>(k+1, -1));
    function<int (int, int)> recur = [&](int s, int t){
        int &ret = dp[s][t];
        if(ret != -1) return ret;
        if(s == 0) return (ret = 1);
        if(t >= k) return (ret = 0);
        ret = 0;
        for(int i=0;i<=C[t].yy;i++){
            if(s - (C[t].xx * i) >= 0){
                ret += recur(s - (C[t].xx * i), t + 1);
            }
        }
        return ret;
    };
    cout << recur(T, 0);
}