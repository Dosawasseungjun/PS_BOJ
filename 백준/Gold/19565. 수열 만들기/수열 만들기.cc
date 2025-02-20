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
    vector<priority_queue<int>> pq(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            pq[i].push(j);
        }
    }
    int now = 1;
    vector<int> ans;
    ans.push_back(now);
    while(!pq[1].empty()){
        int nxt = pq[now].top();
        pq[now].pop();
        now = nxt;
        ans.push_back(nxt);
    }
    cout << ans.size() << '\n';
    for(int a : ans) cout << a << ' ';
}