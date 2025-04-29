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

int ask(int y){
    cout << "? " << y << '\n';
    cout.flush();
    int ret; cin >> ret;
    return ret;
}

void answer(int y){
    cout << "! " << y << '\n';
    cout.flush();
}

void solv(){
    int lo = 2100, hi = 2400;
    int pl = 2100, ph = 2400;
    pii pre = {0, 0};
    bool gura = false;
    while(lo + 1 < hi){
        int mid = (lo + hi) >> 1;
        int y = ask(mid);
        if(!pre.xx) {
            pre = {mid, y};
            pl = lo, ph = hi;
            if(y) lo = mid;
            else hi = mid;
            
            continue;
        }
        if(!gura && pre.yy && !y){ // 거짓말일 수 있음
            int py = ask(pre.xx);
            if(!py){ // 거짓말 했음
                lo = pl;
                hi = pre.xx;
                gura = true;
            }else{ // 거짓말이 아님
                pl = lo, ph = hi;
                if(y) lo = mid;
                else hi = mid;
            }
        }else{
            pl = lo, ph = hi;
            if(y) lo = mid;
            else hi = mid;
        }
        pre = {mid, y};
    }
    if(!gura && pre.yy){
        int ly = ask(pre.xx);
        if(!ly){
            lo = pl;
            hi = pre.xx;
        }
    }
    answer(lo);
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}