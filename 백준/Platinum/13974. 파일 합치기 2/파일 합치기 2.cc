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

const ll INF = 1e18;

void solv(){
    int N; cin >> N;
    vector<ll> A(N+1), ps(N+1);
    vector dp = vector(N+1, vector<ll>(N+1, INF));
    vector opt = vector(N+1, vector<int>(N+1));
    for(int i=1;i<=N;i++) cin >> A[i], ps[i] = ps[i-1] + A[i];
    function<ll(int, int)> C = [&](int l, int r){
        return (ps[r] - ps[l-1]);
    };
    for(int i=1;i<=N;i++) dp[i][i] = 0;
    for(int i=1;i<N;i++){
        dp[i][i+1] = C(i, i+1);
        opt[i][i+1] = i;
    }
    for(int len=2;len<=N;len++){
        for(int i=1;i+len-1<=N;i++){
            int j = i + len -1;
            ll &best = dp[i][j];
            int st = opt[i][j-1];
            int ed = opt[i+1][j];
            for(int k=st;k<=ed;k++){
                ll v = dp[i][k] + dp[k+1][j] + C(i, j);
                if(v < best){
                    best = v;
                    opt[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][N] << '\n';
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
} 