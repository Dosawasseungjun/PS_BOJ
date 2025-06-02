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
    vector<int> a(n);
    int x = n;
    a[n/2] = x--;
    int lo = n/2-1, hi = n/2+1;
    while(x){
        if(lo >= 0) a[lo--] = x--;
        if(hi < n) a[hi++] = x--;
    }
    for(int i=0;i<n;i++) cout << a[i] << ' ';
}