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

const int MAX = 5e5+1;

int main(){
    fast_io
    int n; cin >> n;
    int dx =0 , dy = 0;
    stack<pii> stk;
    for(int i=0;i<n;i++){
        int x, y; cin >> x >> y;
        if(i){
            pii t = stk.top();
            int kx = t.xx - x;
            int ky = t.yy - y;
            if(kx){
                if(dx) stk.pop();
                stk.push({x, y});
                dx = 1; dy = 0;
            }else{
                if(dy) stk.pop();
                stk.push({x, y});
                dx = 0; dy = 1;
            }
        }else{
            stk.push({x, y});
        }
    }
    vector<pii> P;
    while(!stk.empty()) P.push_back(stk.top()), stk.pop();
    sort(P.begin(), P.end(), [](pii &a, pii &b){
        if(a.yy != b.yy) return a.yy < b.yy;
        return a.xx < b.xx;
    });
    int N = P.size();
    vector<int> cnt(2 * MAX);
    int r1 = 0, j = 1, k=0;
    for(int i=0;i<N;i = j){
        if(cnt[P[i].xx+MAX])k -= 1;
        else k += 1;
        cnt[P[i].xx + MAX] ^= 1;
        j = i + 1;
        while(j<N&&P[i].yy == P[j].yy){
            if(cnt[P[j].xx+MAX]) k -= 1;
            else k += 1;
            cnt[P[j].xx + MAX] ^= 1;
            j++;
        }
        r1 = max(r1, k);
    }
    for(int i=0;i<N;i++) swap(P[i].xx, P[i].yy);
    sort(P.begin(), P.end(), [](pii &a, pii &b){
        if(a.yy != b.yy) return a.yy < b.yy;
        return a.xx < b.xx; 
    });
    cnt = vector<int>(2*MAX);
    int r2 = 0;
    k = 0;
    for(int i=0;i<N;i = j){
        if(cnt[P[i].xx+MAX])k -= 1;
        else k += 1;
        cnt[P[i].xx + MAX] ^= 1;
        j = i + 1;
        while(j<N&&P[i].yy == P[j].yy){
            if(cnt[P[j].xx+MAX]) k -= 1;
            else k += 1;
            cnt[P[j].xx + MAX] ^= 1;
            j++;
        }
        r2 = max(r2, k);
    }
    cout << max(r1, r2);
}