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
    int N; cin >> N;
    vector G = vector(N+1, vector<int>());
    for(int i=1;i<=N;i++){
        int x; cin >> x;
        G[i].push_back(x);
        G[x].push_back(i);
    }
    vector<int> vst(N+1), dep(N+1);
    int cycle_size = 0;
    int c_cnt = 0;
    function<void(int, int)> dfs = [&](int here, int parent){
        vst[here] = 1;
        c_cnt++;
        for(int nxt : G[here]){
            if(nxt == parent) continue;

            if(!vst[nxt]){
                dep[nxt] = dep[here] + 1;
                dfs(nxt, here);
                if(cycle_size) continue ;
            }else if(vst[nxt] && dep[here] > dep[nxt]){
                cycle_size = dep[here] - dep[nxt] +1;
                continue ;
            }
        }
    };
    int res = 0;
    for(int i=1;i<=N;i++){
        if(!vst[i]){
            cycle_size = 0;
            c_cnt = 0;
            dfs(i, 0);
            if(cycle_size){
                if(cycle_size & 1) res += c_cnt - 1;
                else res += c_cnt;
            }else{
                res += c_cnt - 1;
            }
        }
    }
    cout << res;
}