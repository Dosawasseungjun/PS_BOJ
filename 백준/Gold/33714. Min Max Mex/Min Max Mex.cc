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

const int MAX = 2e5+1;

int main(){
    fast_io
    int n, k; cin >> n >> k;
    vector<int> a(n), c(MAX);
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i] < MAX) c[a[i]]++;
    }
    int mn = MAX;
    for(int i=0;i<MAX;i++){
        if(c[i] <= k){
            mn = i;
            break;
        }
    }
    int mx = k;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    a.push_back(2e9+1);
    for(int i=0;i<=n;i++){
        if(mx >= a[i]){
            mx += 1;
        }else{
            break;
        }
    }
    cout << mn << '\n';
    cout << mx << '\n';
}