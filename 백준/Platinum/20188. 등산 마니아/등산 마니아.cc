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

const int MAX = 3e5+1;
ll n;
vector<int> G[MAX];
// D: 루트에서 거리, S : 각 정점을 루트로 하는 트리의 노드 수 , K: 각 정점을 거치는 경로의 수
ll D[MAX], K[MAX], S[MAX];

void dfs(int here, int parent){
    S[here] = 1;
    for(int nxt : G[here]){
        if(nxt == parent) continue;
        D[nxt] = D[here] + 1;
        dfs(nxt, here);
        S[here] += S[nxt];
    }
}

void dfs2(int here, int parent){
    K[here] = S[here]-1;
    ll preS = 0;
    for(int nxt : G[here]){
        if(nxt == parent) continue;
        K[here] += preS * S[nxt];
        preS += S[nxt];
        dfs2(nxt, here);
    }
}

int main(){
    fast_io
    cin >> n;
    for(int i=1;i<n;i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 1);
    dfs2(1, 1);
    ll R = 0;
    for(int i=1;i<=n;i++){
        R += (n-1)*D[i];
        R -= D[i] * K[i];
    }
    cout << R;
}