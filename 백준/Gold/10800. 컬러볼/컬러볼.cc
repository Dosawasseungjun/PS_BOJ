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
    vector<pii> X(n+1);
    vector<int> A;
    vector B = vector(n+1, vector<int>());
    for(int i=1;i<=n;i++){
        int c, s; cin >> c >> s;
        X[i] = {c, s}; 
        A.push_back(s);
        B[c].push_back(s);
    }
    sort(A.begin(), A.end());
    for(int i=1;i<=n;i++) sort(B[i].begin(), B[i].end());
    vector<int> ps(n+1, 0);
    vector ps2 = vector(n+1, vector<int>(1, 0));
    for(int i=1;i<=n;i++){
        ps[i] = ps[i-1] + A[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<B[i].size();j++){
            ps2[i].push_back(ps2[i].back() + B[i][j]);
        }
    }

    vector<int> ans(n+1);
    for(int i=1;i<=n;i++){
        int p = lower_bound(A.begin(), A.end(), X[i].yy) - A.begin();
        int q = lower_bound(B[X[i].xx].begin(), B[X[i].xx].end(), X[i].yy) - B[X[i].xx].begin();
        ans[i] = ps[p] - ps2[X[i].xx][q];
    }

    for(int i=1;i<=n;i++) cout << ans[i] << '\n';
}