#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cassert>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX = 500001;
int n, m, s, p;
vector<int> G[MAX], R[MAX], DAG[MAX],RDAG[MAX], ATM, restaurnt, order,topo, C;
vector<int> S;
vector<bool> visited;
int dp[MAX];    //i번째를 정점에서 최대

void DFS1(int here){
    C[here] = -1;
    for(int next : G[here]){
        if(!C[next]) DFS1(next);
    }
    order.push_back(here);
}

void DFS2(int here, int color){
    C[here] = color;
    S.back() += ATM[here];
    for(int next : R[here]){
        if(C[next]==-1) DFS2(next, color);
    }
}

void DFS3(int here, int parent){
    visited[here] = true;
    dp[here] = S[here];
    for(int next : DAG[here]){
        if(!visited[next]){
            DFS3(next, here);
        }
    }
    topo.push_back(here);
}

void dfs(int here){
    visited[here] = true;
    int temp = 0;
    for(int next : RDAG[here]){
        if(!visited[next]) dfs(next);
        temp = max(temp, dp[next]);
    }
    dp[here] += temp;
}

int SCC(){
    C = vector<int> (n+1, 0);
    for(int i=1;i<=n;i++) if(!C[i]) DFS1(i);
    reverse(order.begin(), order.end());
    int c = 0;
    S.emplace_back();
    for(int i : order){
        if(C[i]==-1){
            S.emplace_back();
            DFS2(i, ++c);
        }
            
    }
    
    for(int i=1;i<=n;i++){
        for(int next : G[i]){
            if(C[i]!=C[next]){
                DAG[C[i]].push_back(C[next]);
                RDAG[C[next]].push_back(C[i]);
            }
        }
    }
    return c;
}

int main(){
    fast_io;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        R[v].push_back(u);
    }
    ATM = vector<int> (n+1);
    for(int i=1;i<=n;i++) cin >> ATM[i];
    int colors = SCC();  //scc로 dag를 만들어둠
    cin >> s >> p;
    visited = vector<bool> (colors+1, false);
    DFS3(C[s], 0);    //위상정렬
    visited = vector<bool> (colors+1, false);
    for(int i: topo) if(!visited[i]) dfs(i);
    restaurnt = vector<int> (p);
    int res = 0;
    for(int i=0;i<p;i++){
        cin >> restaurnt[i];
        res = max(res, dp[C[restaurnt[i]]]);
    }
    cout << res;
}
