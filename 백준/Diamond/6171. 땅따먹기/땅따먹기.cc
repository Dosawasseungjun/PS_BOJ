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

const ll inf = 1e18;

struct ConvexHullTrick{
    vector<pll> stk;
    vector<int> idx_stk;
    int pos = 0;    //지금 스택에서 어딘지
    double crossPoint(pll line1, pll line2){
        return 1.0 * (line1.yy-line2.yy) / (line2.xx- line1.xx);
    }
    void insert(pll A, int line_idx){
        while(((int)stk.size()-1) > 0){
            pll B = stk.back();
            stk.pop_back();
            int Bidx = idx_stk.back();
            idx_stk.pop_back();
            pll C = stk.back();
            
            if(crossPoint(C, B)<=crossPoint(B, A)){
                stk.push_back(B);
                idx_stk.push_back(Bidx);
                break;
            }
        }
        stk.push_back(A);
        idx_stk.push_back(line_idx);
    }
    ll query(ll x){ // query가 증가수열
        while(pos+1<stk.size()&&stk[pos].xx*x+stk[pos].yy >= stk[pos+1].xx*x+stk[pos+1].yy) pos++;
        return stk[pos].xx*x+stk[pos].yy;
    }
    void clear(){
        stk.clear();
        idx_stk.clear();
        pos = 0;
    }
}CHT;

int main(){
    fast_io
    ll n; cin >> n;
    vector<pll> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i].xx >> a[i].yy;
    }
    sort(++a.begin(), a.end());
    vector<pll> b;
    for(int i=n;i>=1;i--){
        if(b.empty() || b.back().yy < a[i].yy) b.push_back(a[i]);
    }
    reverse(b.begin(), b.end());
    int m = b.size();
    ll ans = 0;
    for(int i=0;i<m;i++){
        CHT.insert({b[i].yy, ans}, i);
        ans = CHT.query(b[i].xx);
    }
    cout << ans;
}