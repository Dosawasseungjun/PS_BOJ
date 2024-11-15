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
    int n, k; cin >> n >> k;
    ll s1 = 0, s2 = 0;
    stack<ll> a, b;
    for(int i=0;i<n;i++){
        ll x; cin >> x;
        a.push(x);
        s1 += x;
    }
    for(int i=0;i<n;i++){
        ll x; cin >> x;
        b.push(x);
        s2 += x;
    }
    for(int i=0;i<k;i++){
        if(s1 < s2){
            s2 -= b.top();
            b.pop();
        }else{
            s1 -= a.top();
            a.pop();
        }
    }
    cout << max(s1, s2);
}