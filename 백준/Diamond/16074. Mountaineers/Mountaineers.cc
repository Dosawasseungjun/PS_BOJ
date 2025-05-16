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
const int INF = 1e9;

struct DisjointSet{
    vector<int> parent, rank;
    
    DisjointSet(int n):parent(n+1),rank(n+1, 0){
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    
    int find(int u){
        if(u==parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u==v) return;
        
        if(rank[u]>rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u]==rank[v]) rank[v]++;
    }
};

class Query{
public:
    int x1, y1, x2, y2;
    int idx;
    int l, r;
    Query(){}
    Query(int a, int b, int c, int d, int i, int L, int R) : x1(a), y1(b), x2(c), y2(d), idx(i), l(L), r(R) {}
};


int main(){
    fast_io
    int m, n, q; cin >> m >> n >> q;
    vector H = vector(m+1, vector<int>(n+1));
    int mx = 0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin >> H[i][j];
            mx = max(mx, H[i][j]);
        }
    }
    vector M = vector(mx+1, vector<pii>());
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            M[H[i][j]].push_back({i, j});
        }
    }
    
    vector<Query> Q(q);
    vector<int> ans(q);

    for(int i=0;i<q;i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Q[i] = Query(x1, y1, x2, y2, i, 0, mx);
    }

    while(1){
        vector mid = vector(mx+1, vector<int>());
        bool flag = false;
        for(int i=0;i<q;i++){
            if(Q[i].l + 1 < Q[i].r){
                flag = true;
                int m = (Q[i].l + Q[i].r) >> 1;
                mid[m].push_back(i);
            }
        }
        if(!flag) break;

        DisjointSet dsu(n*m+n+1);
        for(int it=1;it<=mx;it++){
            for(auto [y, x] : M[it]){
                for(int i=0;i<4;i++){
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if(ny >= 1 && ny <= m && nx >= 1 && nx <= n && H[ny][nx] <= it) dsu.merge(y*n+x, ny*n+nx);
                }
            }

            for(int idx : mid[it]){
                Query &qry = Q[idx];
                int u = qry.x1 * n + qry.y1;
                int v = qry.x2 * n + qry.y2;
                if(H[qry.x1][qry.y1] <= it && dsu.find(u) == dsu.find(v)){
                    qry.r = it;
                }else{
                    qry.l = it;
                }
            }
        }
    }

    for(int i=0;i<q;i++){
        Query qry = Q[i];
        cout << qry.r << '\n';
    }
}