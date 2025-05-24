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
int N, M, W[MAX], CW[MAX], CW_idx[MAX], dep[MAX], par[21][1 << 21];
vector<int> G[MAX], comp;

class Node{
public:
    int l, r, val;
};

int head[MAX]; // n번째 원소의 당장의 root를 저장
vector<Node> node(2); // 0 - dummy, 1 - root

void init(int nidx, int s, int e){
    if(s == e) return ;
    int mid = (s + e) >> 1;
    node.push_back({0, 0, 0});
    node[nidx].l = node.size()-1;
    init(node[nidx].l, s, mid);
    node.push_back({0, 0, 0});
    node[nidx].r = node.size()-1;
    init(node[nidx].r, mid+1, e);
}

void update(int i, int x, int nidx, int s, int e){
    if(s == e) return ;
    int mid = (s + e) >> 1;
    if(i <= mid){
        int lidx = node[nidx].l;
        node.push_back({node[lidx].l, node[lidx].r, node[lidx].val + x});
        node[nidx].l = node.size()-1;
        update(i, x, node[nidx].l, s, mid);
    }else{
        int ridx = node[nidx].r;
        node.push_back({node[ridx].l, node[ridx].r, node[ridx].val + x});
        node[nidx].r = node.size()-1;
        update(i, x, node[nidx].r, mid+1, e);
    }
}



int kth(int u_head, int v_head, int lca_head, int p_head, int s, int e, int k){
    if(s == e) return s;
    int mid = (s + e) >> 1;
    
    Node u_node = node[u_head];
    Node v_node = node[v_head];
    Node lca_node = node[lca_head];
    Node p_node = node[p_head];

    Node u_l_node = node[u_node.l];
    Node v_l_node = node[v_node.l];
    Node lca_l_node = node[lca_node.l];
    Node p_l_node = node[p_node.l];

    int x = u_l_node.val + v_l_node.val - lca_l_node.val - p_l_node.val;
    if(x >= k) return kth(u_node.l, v_node.l, lca_node.l, p_node.l, s, mid, k);
    else return kth(u_node.r, v_node.r, lca_node.r, p_node.r, mid+1, e, k - x);
}


void dfs(int here, int parent){
    dep[here] = dep[parent] + 1;
    par[0][here] = parent;
    // pst갱신
    head[here] = node.size(); node.push_back(node[head[parent]]);
    update(CW[here], 1, head[here], 0, comp.size()-1);
    for(int nxt : G[here]) if(nxt != parent){
        dfs(nxt, here);
    }
}

void setFP(){
    for(int j=1;j<21;j++){
        for(int i=1;i<=N;i++){
            par[j][i] = par[j-1][par[j-1][i]];
        }
    }
}

int LCA(int u, int v){
    if(dep[u] > dep[v]) swap(u, v);
    int dh = dep[v] - dep[u];

    for(int j=20;j>=0;j--) if((1 << j) & dh){
        v = par[j][v];
    }

    for(int j=20;j>=0;j--) if(par[j][u] != par[j][v]){
        u = par[j][u];
        v = par[j][v];
    }

    if(u != v) u = par[0][u];
    return u;
}




int main(){
    fast_io
    cin >> N >> M;
    
    for(int i=1;i<=N;i++) cin >> W[i], comp.push_back(W[i]);
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()) ,comp.end());

    for(int i=1;i<=N;i++){
        int c = lower_bound(comp.begin(), comp.end(), W[i]) - comp.begin();
        CW[i] = c;
        CW_idx[c] = i;
    }

    for(int i=1;i<N;i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    // pst 만들어두기
    head[0] = 1;
    node[1] = node[0] = {0, 0, 0};
    init(1, 0, comp.size()-1);
    // lca
    dfs(1, 0);
    setFP();

    while(M--){
        int u, v, k;
        cin >> u >> v >> k;
        int lca = LCA(u, v);
        int kth_c = kth(head[u], head[v] , head[lca], head[par[0][lca]], 0, comp.size()-1, k);
        int idx = CW_idx[kth_c];

        cout << W[idx] << '\n';
    }
}