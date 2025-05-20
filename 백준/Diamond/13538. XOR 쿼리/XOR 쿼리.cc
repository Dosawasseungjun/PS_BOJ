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

const int MAX = (1 << 19)-1;

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
    if(node[lidx2].val - node[lidx1].val >= k) return kth(lidx1, lidx2, s, mid, k);
    else return kth(ridx1,ridx2, mid+1, e, k-(node[lidx2].val - node[lidx1].val));
}

int xor_query(int nidx1, int nidx2, int s, int e, int x){
    if(s == e) return s;
    int mid = (s+e) >> 1;
    int lidx1 = node[nidx1].l, ridx1 = node[nidx1].r;
    int lidx2 = node[nidx2].l, ridx2 = node[nidx2].r;
    int cnt1 = node[lidx2].val - node[lidx1].val;
    int cnt2 = node[ridx2].val - node[ridx1].val;
    int mm = (e - s + 1) / 2; // 전체구간의 절반의 비트가 켜져있는가?(전체구간은 2^n꼴임)
    if(((mm & x) && cnt1) || !cnt2) return xor_query(lidx1, lidx2, s, mid, x);
    else return xor_query(ridx1, ridx2, mid+1, e, x);
}


int main(){
    fast_io
    int M; cin >> M;
    head[0] = 1;
    node[1] = node[0] = {0, 0, 0};
    init(1, 0, MAX);
    int sz = 0; // 현재 배열의 사이즈
    while(M--){
        int op; cin >> op;
        if(op == 1){
            int x; cin >> x;
            head[++sz] = node.size();
            node.push_back(node[head[sz-1]]);
            update(x, 1, head[sz], 0, MAX);
        }else if(op == 2){
            int l, r, x;
            cin >> l >> r >> x;
            cout << xor_query(head[l-1], head[r], 0, MAX, x) << '\n';
        }else if(op == 3){
            int k; cin >> k;
            sz -= k;
        }else if(op == 4){
            int l, r, x;
            cin >> l >> r >> x;
            cout << query(1, x, head[r], 0, MAX) - query(1, x, head[l-1], 0, MAX) << '\n';
        }else{
            int l, r, k;
            cin >> l >> r >> k;
            cout << kth(head[l-1], head[r], 0, MAX, k) << '\n';
        }
    }
}