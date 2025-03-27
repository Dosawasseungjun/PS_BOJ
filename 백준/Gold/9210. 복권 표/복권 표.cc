#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string toNDigitString(ll x, int n) {
    string s = to_string(x);
    while(s.size() < n) s = "0" + s;
    return s;
}

int n, r;
string sU, sZ;
ll dp[25][2][2][25]; 

ll solve_dp(int pos, int tight, int flag, int cur) {
    if (pos == n) {
        return flag ? 1LL : 0LL;
    }
    ll &ret = dp[pos][tight][flag][cur];
    if (ret != -1) return ret;
    ret = 0;
    int limit = tight ? sU[pos]-'0' : 9;
    int digitZ = sZ[pos]-'0';
    for (int d = 0; d <= limit; d++) {
        int ntight = tight && (d == limit);
        int ncur = (d == digitZ ? cur + 1 : 0);
        int nflag = flag || (ncur >= r);
        if(nflag) ncur = 0;
        ret += solve_dp(pos+1, ntight, nflag, ncur);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        ll M, Z;
        cin >> M >> Z >> r;
        ll U = M - 1;
        sU = to_string(U);
        n = sU.size();
        sZ = toNDigitString(Z, n);
        
        memset(dp, -1, sizeof(dp));
        ll ans = solve_dp(0, 1, 0, 0);
        cout << ans << "\n";
    }
    return 0;
}