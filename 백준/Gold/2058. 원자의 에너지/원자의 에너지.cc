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
    vector<int> E1(n+1);
    set<int> E2;
    for(int i=1;i<=n;i++) cin >> E1[i];
    for(int i=0;i<m;i++){
        int x; cin >> x;
        E2.insert(x);
    }
    vector G = vector(n+1, vector<int>());
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int diff = abs(E1[i]-E1[j]);
            if(E2.count(diff)){
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
    vector<int> vst(n+1, 0);
    vector dp = vector(n+1, vector<int>(2, 0));
    function<void(int)> dfs = [&](int here){
        vst[here] = 1;
        for(int nxt : G[here]){
            if(!vst[nxt]){
                dfs(nxt);
                dp[here][0] += max(dp[nxt][1], dp[nxt][0]);
                dp[here][1] += dp[nxt][0];
            }
        }
        dp[here][1] += E1[here];
    };
    int res = 0;
    for(int i=1;i<=n;i++){
        if(!vst[i]){
            dfs(i);
            res += max(dp[i][0], dp[i][1]);
        }
    }
    cout << res;
}