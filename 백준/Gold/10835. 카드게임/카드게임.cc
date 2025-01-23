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
    vector<int> A(n+1), B(n+1);
    for(int i=1;i<=n;i++){
        cin >> A[i];
    }
    for(int i=1;i<=n;i++){
        cin >> B[i];
    }
    vector dp(n+1, vector<int>(n+1, -1));
    function<int (int, int)> recur = [&](int a, int b){
        if(a > n || b > n){
            return 0;
        }

        int &ret = dp[a][b];
        if(ret != -1) return ret;
        ret = 0;
        ret = max(ret, recur(a+1, b));
        ret = max(ret, recur(a+1, b+1));
        if(A[a] > B[b]) ret = max(ret, recur(a, b+1) + B[b]);
        return ret;
    };
    int res = recur(1, 1);
    cout << res;
}