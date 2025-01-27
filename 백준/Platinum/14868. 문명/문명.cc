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

const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};

struct DisjointSet{
    vector<int> parent, rank;
    int res = 0;
    
    DisjointSet(int n):parent(n+1),rank(n+1, 0){
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    
    int find(int u){
        if(u==parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u, int v, int turn){
        u = find(u);
        v = find(v);
        if(u==v) return;

        res = max(res, turn);
        if(rank[u]>rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u]==rank[v]) rank[v]++;
    }
};

int main(){
    fast_io
    int n, k; cin >> n >> k;
    vector G = vector(n+1, vector(n+1, 0));
    vector D = vector(n+1, vector(n+1, -1));
    queue<pii> q;
    for(int i=1;i<=k;i++){
        int x, y; cin >> x >> y;
        G[x][y] = i;
        D[x][y] = 0;
        q.push({x, y});
    }
    DisjointSet dsu(k);
    while(!q.empty()){
        auto [hx, hy] = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int nx = hx + dx[i];
            int ny = hy + dy[i];

            if(nx >=1 && nx <= n && ny >= 1 && ny <= n && G[nx][ny] && G[nx][ny] != G[hx][hy] && D[nx][ny] <= D[hx][hy]){
                dsu.merge(G[nx][ny], G[hx][hy], max(D[hx][hy], D[nx][ny]));
            }
        }
        
        for(int i=0;i<4;i++){
            int nx = hx + dx[i];
            int ny = hy + dy[i];

            if(nx >=1 && nx <= n && ny >= 1 && ny <= n && !G[nx][ny]){
                G[nx][ny] = G[hx][hy];
                D[nx][ny] = D[hx][hy] + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << dsu.res;

}