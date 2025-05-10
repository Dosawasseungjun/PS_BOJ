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
    vector<pii> a(n);
    for(int i=0;i<n;i++) cin >> a[i].xx >> a[i].yy;
    sort(a.begin(), a.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;
    for(int i=0;i<n;i++){
        while(!pq.empty() && pq.top() <= a[i].xx) pq.pop();
        pq.push(a[i].yy);
        ans = max(ans, (int)pq.size());
    }
    cout << ans;
}