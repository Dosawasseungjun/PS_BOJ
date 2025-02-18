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
    vector<int> A(n+1), B(n+1), C(n+1);
    vector<int> A_idx(n+1), B_idx(n+1), C_idx(n+1);
    for(int i=1;i<=n;i++) cin >> A[i], A_idx[A[i]] = i;
    for(int i=1;i<=n;i++) cin >> B[i], B_idx[B[i]] = i;
    for(int i=1;i<=n;i++) cin >> C[i], C_idx[C[i]] = i;
    vector G = vector(n+1, vector<int>());
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int a = (A_idx[i] < A_idx[j]);
            int b = (B_idx[i] < B_idx[j]);
            int c = (C_idx[i] < C_idx[j]);
            // a + b + c는 1이면 바뀐게 j가 더 크다고 한게 1개밖에 없다는 뜻이므로
            if(a + b + c <= 1){ // i가 더 뒤에 
                G[j].push_back(i);
            }else{ // j가 더 뒤에
                G[i].push_back(j);
            }
        }
    }
    vector<int> order, vst(n+1);
    function<void(int)> dfs = [&](int here){
        vst[here] = 1;
        for(int nxt : G[here]) if(!vst[nxt]) dfs(nxt);
        order.push_back(here);
    };
    for(int i=1;i<=n;i++) if(!vst[i]) dfs(i);
    reverse(order.begin(), order.end());
    for(int ans : order) cout << ans << ' ';
}