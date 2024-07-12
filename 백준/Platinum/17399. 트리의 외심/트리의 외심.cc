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

const int MAX = 1e5+1;
const int BIT_MAX = 19;
int n, q;
vector<int> adj[MAX];
int depth[MAX], P[BIT_MAX][1<<BIT_MAX];

void dfs(int here, int parent){
    depth[here] = depth[parent]+1;
    P[0][here] = parent;
    for(int next : adj[here]){
        if(next==parent) continue;
        dfs(next, here);
    }
}

void setFP(){
    for(int j=1;j<BIT_MAX;j++){
        for(int i=1;i<=n;i++){
            P[j][i] = P[j-1][P[j-1][i]];
        }
    }
}

int LCA(int u, int v){
    if(depth[u]>depth[v]) swap(u, v);
    int dh = depth[v]-depth[u];

    for(int j=BIT_MAX-1;j>=0;j--) if((1<<j)&dh){
        v = P[j][v];
    }

    for(int j=BIT_MAX;j>=0;j--) if(P[j][u]!=P[j][v]){
        u = P[j][u];
        v = P[j][v];
    }

    if(u!=v) u = P[0][u];
    return u;
}

int t_dist(int a, int b){
    return depth[a] + depth[b] - 2 * depth[LCA(a, b)];
}
int main(){
    fast_io
    cin >> n;
    for(int i=1;i<n;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 1);
    setFP();
    cin >> q;
    while(q--){
        int a, b, c;
        bool ok = true;
        cin >> a >> b >> c;
        int d1 = t_dist(a, b);
        int m1 = -1;
        if(!(d1 & 1)){
            d1 /= 2;
            if(depth[a] > depth[b]){
                m1 = a;
                for(int i=0;i<BIT_MAX;i++) if(d1 & (1 << i)){
                    m1 = P[i][m1];
                }
            }else{
                m1 = b;
                for(int i=0;i<BIT_MAX;i++) if(d1 & (1 << i)){
                    m1 = P[i][m1];
                }
            }
        }
        if(m1 != -1 && t_dist(a,m1) == t_dist(b, m1) && t_dist(b, m1) == t_dist(c, m1)){
            cout << m1 << '\n';
            continue;
        }

        int d2 = t_dist(a, c);
        int m2 = -1;
        if(!(d2 & 1)){
            d2 /= 2;
            if(depth[a] > depth[c]){
                m2 = a;
                for(int i=0;i<BIT_MAX;i++) if(d2 & (1 << i)){
                    m2 = P[i][m2];
                }
            }else{
                m2 = c;
                for(int i=0;i<BIT_MAX;i++) if(d2 & (1 << i)){
                    m2 = P[i][m2];
                }
            }
        }
        if(m2 != -1 && t_dist(a,m2) == t_dist(b, m2) && t_dist(b, m2) == t_dist(c, m2)){
            cout << m2 << '\n';
            continue;
        }

        int d3 = t_dist(b, c);
        int m3=-1;
        if(!(d3 & 1)){
            d3 /= 2;
            if(depth[b] > depth[c]){
                m3 = b;
                for(int i=0;i<BIT_MAX;i++) if(d3 & (1 << i)){
                    m3 = P[i][m3];
                }
            }else{
                m3 = c;
                for(int i=0;i<BIT_MAX;i++) if(d3 & (1 << i)){
                    m3 = P[i][m3];
                }
            }
        }
        if(m3 != -1 && t_dist(a,m3) == t_dist(b, m3) && t_dist(b, m3) == t_dist(c, m3)){
            cout << m3 << '\n';
            continue;
        }

        cout << -1 << '\n';
    }
}