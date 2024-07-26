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
    vector<tiii> A(n);
    for(int i=0;i<n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        A[i] = {a, b, c};
    }
    sort(A.begin(), A.end(), [&](const tiii &a, const tiii &b){
        auto [p, q, r] = a;
        auto [s, t, v] = b;
        return r > v;
    });
    vector<int> C(n+1);
    vector<pii> res;
    for(int i=0;i<n;i++){
        if(res.size() == 3) break;
        auto [p, q, r] = A[i];
        if(C[p] > 1) continue;
        C[p]++;
        res.push_back({p, q});
    }
    cout << res[0].xx << ' ' << res[0].yy << '\n';
    cout << res[1].xx << ' ' << res[1].yy << '\n';
    cout << res[2].xx << ' ' << res[2].yy << '\n';
}