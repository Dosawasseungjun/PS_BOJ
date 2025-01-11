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
    vector S = vector(N+1, vector<int>(M+1));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++) cin >> S[i][j];
        sort(++S[i].begin(), S[i].end());
    }
    vector<int> idx(M+1, 1);
    multiset<tiii> mst;
    int a = 1e9, b = 0;
    for(int i=1;i<=N;i++){
        a = min(a, S[i][1]);
        b = max(b, S[i][1]);
        mst.insert({S[i][1], i, 1});
    }
    int res = b - a;
    while(!mst.empty()){
        auto [a, y, x] = *mst.begin();
        mst.erase(mst.begin());
        if(x+1 <= M) {
            mst.insert({S[y][x + 1], y, x + 1});
            res = min(res, get<0>(*(--mst.end())) - get<0>(*mst.begin()));
        }else{
            break;
        }
    }
    cout << res;
}