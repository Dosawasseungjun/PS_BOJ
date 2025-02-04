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
    int n, m; cin >> n >> m;
    vector dp = vector(10001, vector<int>(101, -1));
    
    function<int(int, int)> sol = [&](int h, int w){
        if(h < w) swap(h, w);
        int &ret = dp[h][w];
        if(ret != -1) return ret;
        
        if(h == 0 || w == 0){
            return (ret = 0);
        }

        if(h == w){
            return (ret = 1);
        }

        ret = h*w;
        for(int i=1;i<=h/2;i++){
            ret = min(ret, sol(i, w) + sol(h-i, w));
        }
        for(int i=1;i<=w/2;i++){
            ret = min(ret, sol(h, i) + sol(h, w-i));
        }
        return ret;
    };
    int r = 0;
    if(n > m * 3){
        r = (n-m*2)/m;
        n -= m*r;
    }
    cout << sol(n, m) + r;
}