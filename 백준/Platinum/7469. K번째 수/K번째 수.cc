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


const int MAX = 1e5+2;
int arr[MAX], carr[MAX];

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

int query(int l, int r, int nidx, int s, int e){
    if(r < s || l > e) return 0;
    if(l <= s && e <= r) return node[nidx].val;
    int mid = (s + e) >> 1;
    return query(l, r, node[nidx].l, s, mid) + query(l, r, node[nidx].r, mid+1, e);
}

int kth(int nidx1,int nidx2, int s, int e, int k){
    if(s == e) return s;
    int mid = (s + e) >> 1;
    int lidx1 = node[nidx1].l, ridx1 = node[nidx1].r;
    int lidx2 = node[nidx2].l, ridx2 = node[nidx2].r;
    if(node[lidx2].val - node[lidx1].val >= k) return kth(lidx1,lidx2, s, mid, k);
    else return kth(ridx1,ridx2, mid+1, e, k-(node[lidx2].val - node[lidx1].val));
}

int main(){
    fast_io
    int n, m; cin >> n >> m;
    vector<int> comp;
    for(int i=1;i<=n;i++) cin >> arr[i], comp.push_back(arr[i]);
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for(int i=1;i<=n;i++) carr[i] = lower_bound(comp.begin(), comp.end(), arr[i])-comp.begin();
    head[0] = 1;
    node[1] = {0, 0, 0};
    init(1, 0, MAX);
    for(int i=1;i<=n;i++){
        head[i] = node.size();
        node.push_back(node[head[i-1]]);
        update(carr[i], 1, head[i], 0, MAX);
    }
    for(int i=1;i<=m;i++){
        int l, r, k;
        cin >> l >> r >> k;
        cout << comp[kth(head[l-1], head[r], 0, MAX, k)] << '\n';
    }
}