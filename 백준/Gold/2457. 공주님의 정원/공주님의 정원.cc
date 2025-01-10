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

vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    fast_io
    int n; cin >> n;
    map<pii, int> mp;
    int cnt = 1;
    for(int i=1;i<=12;i++){
        for(int j=1;j<=days[i];j++){
            mp[{i, j}] = cnt++;
        }
    }
    vector<pii> A(n);
    for(int i=0;i<n;i++){
        int p, q, u, v;
        cin >> p >> q >> u >> v;
        A[i] = {mp[{p, q}], mp[{u, v}]};
    }
    sort(A.begin(), A.end());
    int l = -1;
    int res = 0;
    int r = mp[{3, 1}];
    for(int i=0;i<n;i++){
        auto [st, ed] = A[i];
        
        if(st <= r && r < ed){
            if(st > l){
                res += 1;
                l = r;
                r = ed;                
            }else{
                r = max(r, ed);
            }
        }

        if(r > mp[{11, 30}]) break;
    }
    if(r <= mp[{11, 30}]) res = 0;
    cout << res;
}