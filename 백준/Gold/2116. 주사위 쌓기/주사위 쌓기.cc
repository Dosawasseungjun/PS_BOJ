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
    vector<vector<int>>  D(n);
    for(int i=0;i<n;i++){
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        D[i] = {a, b ,c, d, e, f};
    }
    int res =0;
    map<int, int> mp;
    mp[0] = 5; mp[1] = 3; mp[2] = 4; mp[3] = 1; mp[4] = 2; mp[5]= 0;
    for(int i=0;i<6;i++){
        int r = 0;
        int bottom = D[0][i];
        int top = D[0][mp[i]];
        int mx = 0;
        for(int j=0;j<6;j++){
            if(D[0][j] != bottom && D[0][j] != top) mx = max(mx, D[0][j]);
        }
        r += mx;

        for(int j=1;j<n;j++){
            int idx = 0;
            for(int k=0;k<6;k++){
                if(top == D[j][k]){
                    idx = k;
                    break;
                }
            }
            bottom = D[j][idx];
            top = D[j][mp[idx]];

            mx = 0;
            for(int k=0;k<6;k++)   {
                if(D[j][k] != bottom && D[j][k] != top) mx = max(mx, D[j][k]);
            }
            r += mx;
        }
        res = max(r, res);
    }
    cout << res;
}