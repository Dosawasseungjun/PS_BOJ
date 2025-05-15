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
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    ll D; cin >> D;
    
    function<vector<ll>(int,int )> f= [&](int l, int r) -> vector<ll>{
        function<vector<ll>(int)> dfs = [&](int idx) -> vector<ll>{
            if(idx > r) return {0};
            vector<ll> v1 = dfs(idx+1), v2 = v1, v3 = v2;
            for(int i=0;i<v2.size();i++) v2[i] -= A[idx];
            for(int i=0;i<v3.size();i++) v3[i] += A[idx];
            vector<ll> ret(v1.size()+v2.size()+v3.size());
            int ik = 0;
            int i1=0, i2=0,i3=0;
            while(i1<v1.size() || i2 < v2.size() || i3 <v3.size()){
                if(i1 < v1.size() && (i2 == v2.size() || v1[i1] <= v2[i2]) && (i3 == v3.size() || v1[i1] <= v3[i3])) ret[ik++] = v1[i1++];
                if(i2 < v2.size() && (i1 == v1.size() || v2[i2] <= v1[i1]) && (i3 == v3.size() || v2[i2] <= v3[i3])) ret[ik++] = v2[i2++];
                if(i3 < v3.size() && (i2 == v2.size() || v3[i3] <= v2[i2]) && (i1 == v1.size() || v3[i3] <= v1[i1])) ret[ik++] = v3[i3++];
            }
            return ret;
        };
        return dfs(l);
    };

    vector<ll> dp1 = f(0, N/2-1), dp2 = f(N/2, N-1);

    ll res = 0;
    ll l = 0, r = 0;
    for(int i=dp2.size()-1;i>=0;i--){
        ll hi = D - dp2[i];
        while(r < dp1.size() && dp1[r] <= hi) r++;
        ll lo = -D - dp2[i];
        while(l < dp1.size() && dp1[l] < lo) l++;
        res += max(0ll, r-l);
    }

    cout << res;
}