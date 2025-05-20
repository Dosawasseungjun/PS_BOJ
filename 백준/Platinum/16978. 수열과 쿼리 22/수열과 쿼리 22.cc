#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cassert>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

class Data{
public:
    int idx, k, i, j;
    
    bool operator < (const Data& d)const{
        return this->k < d.k;
    }
};
int n, m;
ll arr[100001];
ll tree[400004];
vector<pii> q1;
vector<Data> q2;
vector<pll> ans;

void init(int node, int S, int E){
    int mid = (S+E)>>1;
    if(S==E){
        tree[node] = arr[S];
        return;
    }
    init(2*node, S, mid); init(2*node+1, mid+1, E);
    tree[node] = tree[2*node]+tree[2*node+1];
}
void update(int x, ll v, int node, int S, int E){
    int mid = (S+E)>>1;
    if(S==E){
        tree[node] = arr[x] = v;
        return;
    }
        
    if(x<=mid) update(x, v, 2*node, S, mid);
    else update(x, v, 2*node+1, mid+1, E);
    
    tree[node] = tree[2*node]+tree[2*node+1];
}

ll query(int L, int R, int node, int S, int E){
    if(L>E||S>R) return 0;
    if(L<=S&&E<=R) return tree[node];
    int mid = (S+E)>>1;
    return query(L, R, 2*node, S, mid)+query(L, R, 2*node+1, mid+1, E);
}

int main(){
    fast_io;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    cin >> m;
    for(int i=0;i<m;i++){
        int q; cin >> q;
        if(q==1){
            int i; ll v; cin >> i >> v;
            q1.push_back({i, v});
        }else{
            Data d; d.idx =i;
            cin >> d.k >> d.i >> d.j ;
            q2.push_back(d);
        }
    }
    sort(q2.begin(), q2.end());
    init(1, 1, n);
    int now = 0;
    for(int i=0;i<q2.size();i++){
        while (q2[i].k>now) {
            update(q1[now].first, q1[now].second, 1, 1, n);
            now++;
        }
        ans.push_back({q2[i].idx, query(q2[i].i, q2[i].j, 1, 1, n)});
    }
    sort(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++){
        cout << ans[i].second << '\n';
    }
}
