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

void solv(){
    int m; cin >> m;
    int n= 0, cnt = 0;
    priority_queue<int> x_heap;
    priority_queue<int, vector<int>, greater<int>> n_heap;
    cout << m / 2 + 1 << '\n';
    for(int i=1;i<=m;i++){
        if(i & 1) n++;
        int x; cin >> x;
        n_heap.push(x);
        while(!x_heap.empty() && x_heap.top() > n_heap.top()){
            int mx = x_heap.top(); x_heap.pop();
            int mn = n_heap.top(); n_heap.pop();
            x_heap.push(mn);
            n_heap.push(mx);
        }
        while(x_heap.size() + 1 < n_heap.size()){
            int k = n_heap.top();
            n_heap.pop();
            x_heap.push(k);
        }

        if(i & 1) cout << n_heap.top() << " \n"[(n % 10) == 0];
    }
    cout << '\n';
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}