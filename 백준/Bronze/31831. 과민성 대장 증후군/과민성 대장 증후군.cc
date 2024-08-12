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
    vector<int> A(n+1);
    int st = 0;
    int res = 0;
    for(int i=1;i<=n;i++){
        cin >> A[i];
        st += A[i];
        st = max(st, 0);
        if(st >= m) res++;
    }
    cout << res;
}