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
    int N, M; cin >> N >> M;
    vector<int> ind(N+1), outd(N+1);
    vector G = vector(N+1, vector<pii>());
    for(int i=0;i<M;i++){
        int x, y, k;
        cin >> x >> y >> k;
        outd[x]++;
        ind[y]++;
        G[x].push_back({y, k});
    }
    vector<int> vst(N+1, 0), dp(N+1);
    queue<int> q;
    q.push(N); vst[N] = 1; dp[N] = 1;
    while(!q.empty()){
        int here = q.front();
        q.pop();
        for(auto [nxt, w] : G[here]){
            if(vst[nxt]) continue;
            dp[nxt] += dp[here] * w;
            if(!(--ind[nxt])) {
                q.push(nxt);
                vst[nxt] = 1;
            }
        }
    }

    for(int i=1;i<=N;i++) if(!outd[i]) cout << i << ' ' << dp[i] << '\n';
}