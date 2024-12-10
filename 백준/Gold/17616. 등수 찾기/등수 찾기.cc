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
    int N, M, X; cin >> N >> M >> X;
    vector G = vector(N+1, vector<int>());
    vector R = vector(N + 1, vector<int>());
    for(int i=0;i<M;i++){
        int u, v; 
        cin >> u >> v;
        G[u].push_back(v);
        R[v].push_back(u);
    }

    vector<int> vst1(N+1), vst2(N+1);
    std::function<int(int)> dfs1 = [&](int here) -> int{
        int ret = 1;
        vst1[here] = 1;
        for(int nxt : G[here]){
            if(vst1[nxt]) continue;
            ret += dfs1(nxt);
        }
        return ret;
    };

    std::function<int(int)> dfs2 = [&](int here) -> int{
        int ret = 1;
        vst2[here] = 1;
        for(int nxt : R[here]){
            if(vst2[nxt]) continue;
            ret += dfs2(nxt);
        }
        return ret;
    };
    int bad = dfs1(X) - 1; // X보다 무조건 못하는 애들 수
    int well = dfs2(X) - 1; // X보다 무조건 잘하는 애들 수 

    int best = well + 1; 
    int worst = N - bad; 

    cout << best << ' ' << worst;

}