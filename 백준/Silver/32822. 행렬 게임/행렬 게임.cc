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
    vector A(n, vector<int>(n)), B(n, vector<int>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> A[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> B[i][j];
    int res = 0;
    vector<int> C(n);
    for(int b=0;b<n;b++){
        for(int a=0;a<n;a++){
            C[b] = max(C[b], abs(A[a][b]-B[a][b]));
        }
    }
    for(int i=0;i<m;i++){
        int b; cin >> b; b--;
        res += C[b];
    }
    cout << res;
}