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
    int K; cin >> K;
    int X; cin >> X;
    vector<pii> A(X);
    int mxy = 0;
    for(int i=0;i<X;i++){
        cin >> A[i].xx >> A[i].yy;
        mxy = max(mxy, A[i].xx);
    }
    sort(A.begin(), A.end(), [](const pii &a, const pii &b){
        if(a.yy != b.yy) return a.yy < b.yy;
        return a.xx < b.xx;
    });
    
    function can = [&](int x){
        int use = 0;
        deque<int> dq;
        for(int i=0;i<X;i++){
            if(dq.empty() || A[i].yy-dq.front()+1 <= x) dq.push_back(A[i].yy);
            else{
                use += 1;
                while(!dq.empty()) dq.pop_front();
                dq.push_back(A[i].yy);
            }
        }
        use += 1;
        return use <= K;
    };
    int lo = mxy-1, hi = N;
    while(lo + 1 < hi){
        int mid = (lo + hi) >> 1;
        if(can(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi;
}