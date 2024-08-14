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
    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        int d; cin >> d;
        pq.push(d);
    }
    int y = 0;
    vector<int> res;
    while(!pq.empty()){
        int d = pq.top();
        pq.pop();
        y = y / 2 + d;
        d -= m;
        res.push_back(y);
        if(d > k) pq.push(d);
    }
    cout << res.size() << '\n';
    for(int r : res) cout << r << '\n';
}