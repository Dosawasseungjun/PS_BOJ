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

const int MAX = 1e6+1;
vector<int> G[MAX];
int ans, k, dep[MAX];

void dfs(int here, int parent){
    dep[here] = dep[parent] + 1;
    for(int nxt : G[here]) if(nxt != parent){
        dfs(nxt, here);
    }
}

int main(){
    fast_io
    int N; cin >> N;
    for(int i=2;i<=N;i++){
        int p; cin >> p;
        G[p].push_back(i);
        G[i].push_back(p);
    }
    dep[1] = -1;
    dfs(1, 1);
    vector<int> cnt(N+1, 0);
    for(int i=1;i<=N;i++) cnt[dep[i]]++;
    for(int i=2;i<=N;i++){
        int res = 0;
        for(int j=0;j<=N;j+=i){
            res += cnt[j];
        }
        ans = max(res, ans);
    }
    cout << ans;
}