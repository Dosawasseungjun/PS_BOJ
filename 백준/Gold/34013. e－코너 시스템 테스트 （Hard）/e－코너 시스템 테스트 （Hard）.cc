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

const int inf = 1e9;

struct Compare {
    bool operator()(const pair<pii,pii>& a, const pair<pii,pii>& b) const {
        if(a.second.first != b.second.first)
            return a.second.first > b.second.first;  
        return a.second.second < b.second.second;
    }
};


int main(){
    fast_io
    int N; cin >> N;
    vector G = vector(N*N, vector<tiii>());
    vector A = vector(N, vector<int>(N-1));
    vector B = vector(N-1, vector<int>(N));
    for(int i=0;i<2*N-1;i++){
        if(i & 1){
            for(int j=0;j<N;j++){
                cin >> B[i/2][j];
            }
        }else{
            for(int j=0;j<N-1;j++){
                cin >> A[i/2][j];
            }
        }
    }

    // A는 세로줄
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            int u = i + j*N;
            int v = u + N;
            G[u].push_back({v, A[i][j], 1});
            G[v].push_back({u, A[i][j], 1});
        }
    }

    // B는 가로줄
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N;j++){
            int u = N*j + i;
            int v = N*j + i+1;
            G[u].push_back({v, B[i][j], 0});
            G[v].push_back({u, B[i][j], 0});
        }
    }

    vector D = vector(N*N, vector<pii>(2, {inf, 0})); // 앞에는 작아야하고 뒤에는 커야함
    D[0][0] = D[0][1] = {0, 0};
    priority_queue<pair<pii, pii>, vector<pair<pii, pii>>, Compare> pq;
    pq.push({{0, -1}, {0, 0}});
    while(!pq.empty()){
        auto pa = pq.top();
        auto [u, t] = pa.xx;
        auto [dist, turn] = pa.yy;
        pq.pop();
        if(t != -1 && (dist > D[u][t].xx || (dist == D[u][t].xx && turn < D[u][t].yy))) continue;
        for(auto [nxt, w, x] : G[u]){
            if(D[nxt][x].xx > dist + w || (D[nxt][x].xx == dist+w && D[nxt][x].yy < turn + (x + t == 1))){
                D[nxt][x] = {dist+w, turn+(x+t==1)};
                pq.push({{nxt, x}, D[nxt][x]});
            }
        }
    }
    pll res;
    if(D[N*N-1][0].xx > D[N*N-1][1].xx){
        res = D[N*N-1][1];
    }else if(D[N*N-1][0].xx < D[N*N-1][1].xx){
        res = D[N*N-1][0];
    }else{
        if(D[N*N-1][0].yy > D[N*N-1][1].yy) res = D[N*N-1][0];
        else res = D[N*N-1][1];
    }

    cout << res.xx << ' ' << res.yy;
}