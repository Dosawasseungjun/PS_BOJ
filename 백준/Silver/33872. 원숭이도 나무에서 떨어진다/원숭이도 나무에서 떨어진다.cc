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

const int V_MAX = 26;
int N, H, S, E, B[V_MAX], K[V_MAX], ans;
vector<int> G[V_MAX];

int res, C[V_MAX];

void recur(int now, int hp){
    if(now == E && hp == 0){
        ans = max(ans, res);
        return ;
    }
    if(hp == 0){
        return ;
    }
    for(int nxt : G[now]){
        if(!K[nxt] && C[nxt] < 2){
            if((++C[nxt]) == 1) res += B[nxt];
            recur(nxt, hp-1);
            if((--C[nxt]) == 0) res -= B[nxt];
        }
    }
}

int main(){
    fast_io
    cin >> N >> H;
    cin >> S >> E;
    for(int i=1;i<=N;i++) cin >> B[i];
    for(int i=1;i<=N;i++) cin >> K[i];
    for(int i=1;i<N;i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ans = -1;
    C[S] = 1;
    res = B[S];
    recur(S, H);
    cout << ans;
}