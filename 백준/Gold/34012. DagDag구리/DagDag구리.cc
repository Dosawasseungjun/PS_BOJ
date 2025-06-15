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
    vector G = vector(N+1, vector<int>());
    vector<int> ind(N+1, 0);
    for(int i=0;i<M;i++){
        int u, v; cin >> u >> v;
        G[v].push_back(u);
        ind[u]++;
    }
    int E = 0;
    for(int i=1;i<=N;i++) if(!ind[i]) E = i;
    vector<int> cnt(N+1, 0);
    queue<int> q;
    q.push(E);
    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int nxt : G[now]){
            cnt[nxt]++;
            if(!(--ind[nxt])) q.push(nxt);
        }
    }
    int res = 0;
    for(int i=1;i<=N;i++) if(cnt[i] == 1) res += 1;
    cout << res;
}