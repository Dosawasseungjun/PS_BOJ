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
    ll n; cin >> n;
    vector<int> A(n);
    map<int, ll> mp;
    for(int i=0;i<n;i++) {
        cin >> A[i];
        if(mp.count(A[i])) mp[A[i]] += 1;
        else mp[A[i]] = 1;
    }   
    ll res = n * (n+1)/2;
    for(auto [key, val] : mp){
        res -= val * (val + 1) / 2;
    }
    cout << res + 1;
}