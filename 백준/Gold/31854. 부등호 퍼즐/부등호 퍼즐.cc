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
    vector G = vector(N*N+1, vector<int>());
    for(int i=0;i<N;i++){
        int st = i * N + 1;
        for(int j=1;j<N;j++){
            char op; cin >> op;
            if(op == '>') G[st+j].push_back(st+j-1);
            else G[st+j-1].push_back(st+j);
        }
    }
    for(int i=0;i<N-1;i++){
        for(int j=1;j<=N;j++){
            char op; cin >> op;
            int p = i * N + j;
            int q = (i+1)*N + j;
            if(op == '<') G[p].push_back(q);
            else G[q].push_back(p);
        }
    }

    vector<int> vst(N*N+1, 0), order;
    function<void(int)> dfs = [&](int here){
        vst[here] = 1;
        for(int nxt : G[here]){
            if(vst[nxt]) continue;
            dfs(nxt);
        }
        order.push_back(here);
    };
    for(int i=1;i<=N*N;i++){
        if(vst[i]) continue;
        dfs(i);
    }
    reverse(order.begin(), order.end());
    vector<int> ans(N*N+1);
    int i = 1;
    for(int o : order){
        ans[o] = i++;
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout << ans[(i-1)*N + j] << ' ';
        }
        cout << '\n';
    }
}