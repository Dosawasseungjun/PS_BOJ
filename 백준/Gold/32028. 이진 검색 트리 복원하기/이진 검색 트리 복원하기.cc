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
    vector<tiii> ah(n+1);
    for(int i=1;i<=n;i++) {
        int a, b;
        cin >> a >> b;
        ah[i] = {a, b, i};
    }
    
    sort(ah.begin(), ah.end(), [&](const tiii &a, const tiii &b){
        auto [x, y, z] = a;
        auto [p, q, r] = b;
        if(y != q) return y < q;
        return x < p;
    });
    bool ok = 1;
    vector<pii> C(n+1, {-1, -1});
    vector<pair<pii, pii>> R(n+1);
    R[1].xx = {-2e9-1, get<0>(ah[1])};
    R[1].yy = {get<0>(ah[1]), 2e9+1};
    if(get<1>(ah[1]) != 1) ok = false;
    for(int i=2, j =1;i<=n;i++){
        if(!ok) break;
        auto [num, dep, idx] = ah[i];
        auto [pn, pd, pi] = ah[j];
        while(pd < dep){
            if(pd == dep - 1 && R[j].xx.xx < num && num < R[j].xx.yy){
                if(C[pi].xx == -1){
                    break;
                }
            }
            if(pd == dep-1 && R[j].yy.xx < num && num < R[j].yy.yy){
                if(C[pi].yy == -1){
                    break;
                }
            }
            j++;
            tie(pn, pd, pi) = ah[j];
        }
        if(pd == dep - 1){
            if(R[j].xx.xx < num && num < R[j].xx.yy){ // 왼쪽 자식
                if(C[pi].xx == -1){
                    R[i].xx = {R[j].xx.xx , num};
                    R[i].yy = {num, R[j].xx.yy};
                    C[pi].xx = idx;
                }else ok = false;
            }else if(R[j].yy.xx < num && num < R[j].yy.yy){ // 오른쪽 자식
                if(C[pi].yy == -1){
                    R[i].xx = {R[j].yy.xx, num};
                    R[i].yy = {num, R[j].yy.yy};
                    C[pi].yy = idx;
                }else ok = false;
            }else ok = false;
        }else ok = false;
    }
    if(ok){
        for(int i=1;i<=n;i++) cout << C[i].xx <<  ' ' << C[i].yy << '\n';
    }else{
        cout << -1;
    }
}