#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long n, k, x;
pair<long long, long long> a[100000];

long long solve(long long ans) {
    pair<ll, ll> p = {ans, INT_MAX};
    int b = upper_bound(a, a+n, p) - a;
    ll skep[n-b];
    for(int i=b; i<n; i++) skep[i-b]=(a[i].first-ans)*a[i].second;
    sort(skep, skep+n-b);
    long long k=0;
    for(int i=0; i<n-b-x+1; i++) k+=skep[i];
    return k;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>k>>x;
    for(int i=0; i<n; i++) cin>>a[i].first>>a[i].second;
    sort(a, a+n);
    long long l=0, r=a[n-1].first;
    while(l<r) {
        auto m=(l+r)/2;
        if(solve(m)>=k) l=m+1;
        else r=m;
    }
    cout<<r;
}