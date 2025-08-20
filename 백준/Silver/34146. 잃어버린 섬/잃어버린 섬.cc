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
    int n, m; cin >> n >> m;
    vector<int> C(10001);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x; cin >> x;
            C[x] += 1;
        }
    }
    int odd = 0;
    for(int i=1;i<=10000;i++) if(C[i] & 1) odd++;
    int k = 0;
    if(m & 1) k = n;
    // cout << odd << '\n';
    if(odd <= k) cout << "YES\n";
    else cout << "NO\n";
}