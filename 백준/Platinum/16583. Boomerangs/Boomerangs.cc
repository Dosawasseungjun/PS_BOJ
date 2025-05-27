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
int n, m;
vector<int> G[MAX], tree[2*MAX];
int vst[MAX], fin[MAX];
vector<tiii> ans;

bool dfs(int here,int parent){
    vector<int> children;
    vst[here] = 1;
    for(int nxt : G[here]){
        if(nxt == parent) continue;
        if(vst[nxt]){
            if(!fin[nxt]) children.push_back(nxt);
        }else if(!dfs(nxt, here)){ // 사용 안됐으면 추가
            children.push_back(nxt);
        }
    }

    fin[here] = 1;
    for(int i=1;i<children.size(); i += 2){
        ans.push_back({children[i-1], here, children[i]});
    }

    if((children.size() & 1) && parent != here){
        ans.push_back({children.back(), here, parent});
        return true;
    }
    return false;
}

int main(){
    fast_io
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    for(int i=1;i<=n;i++){
        if(!vst[i]) dfs(i, i);
    }

    cout << ans.size() << '\n';
    for(auto [a, b, c] : ans){
        cout << a << ' ' << b << ' ' << c << '\n';
    }
}