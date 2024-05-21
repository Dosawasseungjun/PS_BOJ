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

const int MAXSIZE = 2e5+1;

template <class T>
class Node_Segtree{
public:
    class Node{
    public: 
        ll l, r, val;

        Node& operator = (const Node & n1){
            l = n1.l;
            r = n1.r;
            val = n1.val;
            return *this;
        }

        Node operator + (const Node & n1){
            Node ret;
            ret.l = l;
            ret.r = n1.r;
            ret.val = val + n1.val - (r!= 0 && r == n1.l);
            return ret;
        }
    };

    static const int TREESIZE = 4*MAXSIZE;
    Node* tree = new Node[TREESIZE];

    Node_Segtree(){
        for(int i=0;i<TREESIZE;i++) tree[i] = (Node){0, 0, 0};
    }
    ~Node_Segtree(){
        delete[] tree;
    }
    void update(T x, T v, T node, T S, T E){
        if(S==E) {
            tree[node] = (Node){v, v, 1};
            return;
        }
        
        T mid = (S+E)>>1;
        if(x<=mid) update(x, v, 2*node, S, mid);
        else update(x, v, 2*node+1, mid+1, E);
        tree[node] = tree[2*node] + tree[2*node + 1];
    }
    
    Node query(T L, T R, T node, T S, T E){
        if(L>E||R<S) return (Node){0, 0, 0};
        if(L<=S&&E<=R) return tree[node];
        T mid = (S+E)>>1;
        return query(L, R, 2*node, S, mid)+query(L, R, 2*node+1, mid+1, E);
    }
};

Node_Segtree<ll> ndsgt;

int main(){
    fast_io
    int n, q; cin >> n >> q;
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        ndsgt.update(i, x, 1, 1, n);
    }
    while(q--){
        int op, a, b; cin >> op >> a >> b;
        if(op == 1){
            ndsgt.update(a, b, 1, 1, n);
        }else{
            cout << ndsgt.query(a, b, 1, 1, n).val << '\n';
        }
    }
}