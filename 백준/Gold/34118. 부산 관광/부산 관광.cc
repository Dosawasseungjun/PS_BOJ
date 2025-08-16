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

const int inf = 1e9;

int main(){
    fast_io
    int n; cin >> n;
    string a, b;
    cin >> a >> b;
    a = "0" + a;
    b = "0" + b;
    int p[4];
    cin >> p[0] >> p[1] >> p[2] >> p[3];
    vector dp = vector(n+1, vector<int>(n+1, inf));
    
    function<int(int, int)> f = [&](int i, int j){
        if(i < 0 || j < 0) return inf;
        if(!i && !j) return 0;
        int &ret = dp[i][j];
        if(ret != inf) return ret;
        if(a[i] == '0') ret = min(ret, f(i-1, j));
        if(b[j] == '0') ret = min(ret, f(i, j-1));
        for(int k1=1;k1<=5;k1+=2){
            if(i >= k1) ret = min(ret, f(i-k1, j) + p[k1/2]);
        }
        for(int k2=1;k2<=5;k2+=2){
            if(j >= k2) ret = min(ret, f(i, j-k2) + p[k2/2]);
        }
        if(i >= 4 && j >= 4) ret = min(ret, f(i-4, j-4) + p[3]);
        return ret;
    };
    cout << f(n, n);
}