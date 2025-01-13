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

class Node{
public:
    int parent = -1;
    int l = -1, r = -1;
    int row = 0, col = 0;
    Node(){}
};

int rt, in = 1;
vector<Node> tree;

void inorder(int now){
    if(tree[now].l != -1) inorder(tree[now].l);
    tree[now].col = in++;
    if(tree[now].r != -1) inorder(tree[now].r);
}

void dfs(int now){
    tree[now].row = tree[now].parent == -1 ? 1 : tree[tree[now].parent].row + 1;
    if(tree[now].l != -1) dfs(tree[now].l);
    if(tree[now].r != -1) dfs(tree[now].r);
}

int main(){
    fast_io
    int N; cin >> N;
    tree = vector<Node>(N + 1);
    for(int i=1;i<=N;i++){
        int n, l, r; cin >> n >> l >> r;
        tree[n].l = l;
        tree[n].r = r;
        if(l != -1) tree[l].parent = n;
        if(r != -1) tree[r].parent = n;
    }
    for(int i=1;i<=N;i++) if(tree[i].parent == -1) rt = i;
    inorder(rt);
    dfs(rt);
    int mx_depth = 0;
    for(int i=1;i<=N;i++){
        mx_depth = max(mx_depth, tree[i].row);
    }
    vector<pii> width(mx_depth + 1, {10001, -1});
    for(int i=1;i<=N;i++){
        width[tree[i].row].xx = min(width[tree[i].row].xx, tree[i].col);
        width[tree[i].row].yy = max(width[tree[i].row].yy, tree[i].col);
    }
    int res_row, res = 0;
    for(int i=1;i<=mx_depth;i++){
        if(width[i].yy - width[i].xx + 1 > res){
            res_row = i;
            res = width[i].yy - width[i].xx + 1;
        }
    }
    cout << res_row << ' ' << res;
}