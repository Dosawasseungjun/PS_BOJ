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
    int N, M; cin >> N >> M;
    vector<tiii> lines(M+1);
    for(int i=1;i<=M;i++){
        int a, b; cin >> a >> b;
        if(a > b) {
            b += N;
            lines[i] = {a, b, i};
        }else{
            lines[i] = {a, b, i};
            lines.push_back({a + N, b + N, i});
        }
        
        
    }
    vector<int> ans(M+1, 1); //0이면 불가능 1이면 가능

    sort(lines.begin(), lines.end(), [&](const tiii &a, const tiii &b){
        auto [aa, ab, ai] = a;
        auto [ba, bb, bi] = b;
        if(aa != ba) return aa < ba;
        return ab > bb;
    });
    stack<int> stk;
    for(auto [a, b, idx] : lines){
        while(!stk.empty() && stk.top() <  b) stk.pop();
        if(!stk.empty() && stk.top() >= b) ans[idx] = 0;
        else stk.push(b);
    }
    for(int i=1;i<=M;i++) if(ans[i]) cout << i << ' ';
}