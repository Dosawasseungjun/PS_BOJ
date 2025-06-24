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


int main(){
    fast_io
    int n; cin >> n;
    vector G = vector(n+1, vector<int>());
    for(int i=1;i<n;i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> A(n+1, 0); 
    for(int i=1;i<=n;i++) cin >> A[i];
    
    int ans = 0;
    function<bool(int, int)> dfs = [&](int here, int parent){
        int cnt = 0;
        for(int nxt : G[here]){
            if(nxt == parent) continue;
            cnt += dfs(nxt, here); // 묶일 수 있는 것의 개수
        }

        if(cnt > 1){ // 묶는다. 
            ans += cnt - 1;
            return false; // 이제 묶을 수 없음
        }

        // 묶을게 없음. 근데 이번 노드가 특별하거나 아래 안쓴거 있어서 다음에 묶을 수 있음
        return (cnt|| A[here]);
    };

    if(dfs(1, 1)) ans += 1; // 루트를사용을 안했으면 남는다. 
    cout << max(ans-1, 0);
}