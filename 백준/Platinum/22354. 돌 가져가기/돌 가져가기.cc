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
    string s; cin >> s;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<ll> c;
    priority_queue<ll> pq;
    char pre = s[0];
    ll mx = a[0];
    for(int i=1;i<n;i++){
        if(pre == s[i]){
            mx = max(mx, a[i]);
        }else{
            c.push_back(mx);
            pre = s[i];
            mx = a[i];
        }
    }
    for(int i=1;i<c.size();i++) pq.push(c[i]);
    int sz = pq.size();
    ll res = 0;
    for(int i=0;i<(sz+1)/2;i++){
        res += pq.top();
        pq.pop();
    }
    cout << res;

}