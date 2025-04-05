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


pll sub(pll u, pll v){
    return {u.xx-v.xx, u.yy-v.yy};
}

ll ccw(pll a, pll b, pll c){
    pll u, v;
    u = sub(b, a);
    v = sub(c, a);
    ll ret = u.xx*v.yy - u.yy*v.xx;
    if(ret) ret /= abs(ret);
    return ret;
}

ll dist(pll a, pll b){
    return (b.xx-a.xx)*(b.xx-a.xx) + (b.yy-a.yy)*(b.yy-a.yy);
}

//모노톤 체인을 이용하여 컨벡스헐과 회전하는 캘리퍼스 구현 : green55님 블로그 참고
ll rotating_calipers(vector<pll> &poly){
    sort(poly.begin(), poly.end());
    vector<pll> up, down;
    for(auto &p : poly){
        while(up.size() >= 2 && ccw(up[(int)up.size()-2], up[(int)up.size()-1], p) >= 0)
            up.pop_back();
        up.push_back(p);
        while(down.size() >= 2 && ccw(down[(int)down.size()-2], down[(int)down.size()-1], p) <= 0)
            down.pop_back();
        down.push_back(p);
    }
    
    ll ret = 0;
    pair<pll, pll> ans;
    
    for(int i=0,j=(int)down.size()-1;i+1<up.size()||j>0;){
        if(ret<dist(up[i], down[j])){
            ret = dist(up[i], down[j]);
            ans = {up[i], down[j]};
        }
        
        
        ll dxup = up[i+1].xx - up[i].xx;
        ll dyup = up[i+1].yy - up[i].yy;
        ll dxdn = down[j].xx - down[j-1].xx;
        ll dydn = down[j].yy - down[j-1].yy;
        
        if(i+1==up.size()) --j;
        else if(j==0) ++i;
        else if(dyup * dxdn > dydn * dxup) ++i;
        else --j;
    }
    return ret;
}

int main(){
    fast_io
    int N; cin >> N;
    vector<pll> P(N);
    for(int i=0;i<N;i++){
        cin >> P[i].xx >> P[i].yy;
    }
    cout << rotating_calipers(P);
}