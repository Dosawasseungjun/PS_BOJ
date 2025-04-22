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

const int MAX = 1e2+1;
int N;
int cost[MAX], G[MAX][MAX], R[MAX][MAX];
int C[MAX];
vector<int> order;
vector<vector<int>> sccs;

void dfs1(int here){
    C[here] = -1;
    for(int j=1;j<=N;j++){
        if(!G[here][j]) continue;
        if(!C[j]){
            dfs1(j);
        }
    }
    order.push_back(here);
}

void dfs2(int here, int cnt){
    C[here] = cnt;
    sccs.back().push_back(here);
    for(int j=1;j<=N;j++){
        if(!R[here][j]) continue;
        if(C[j] == -1){
            dfs2(j, cnt);
        }
    }
}

void SCC(){
    for(int i=1;i<=N;i++) if(!C[i]) dfs1(i);
    reverse(order.begin(), order.end());
    int cnt = 0;
    for(int i : order){
        if(C[i] == -1){
            sccs.emplace_back();
            dfs2(i, ++cnt);
        }
    }
}

int main(){
    fast_io
    cin >> N;
    for(int i=1;i<=N;i++) cin >> cost[i];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            char x; cin >> x;
            G[i][j] = x - '0';
            R[j][i] = G[i][j];
        }
    }
    SCC();
    int res = 0;
    for(int i=0;i<sccs.size();i++){
        int mn = 1e9;
        for(int ele : sccs[i]){
            mn = min(cost[ele], mn);
        }
        res += mn;
    }
    cout << res;
}