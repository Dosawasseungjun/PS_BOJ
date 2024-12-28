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
    int N; cin >> N;
    vector<int> V(N+1), ps(N+1);
    for(int i=1;i<=N;i++) cin >> V[i], ps[i] = ps[i-1] + V[i];
    int res = 0;
    for(int i=2;i<=N-1;i++){
        res = max(res, ps[N]-ps[1] - V[i] + ps[N] - ps[i]);
    }
    for(int i=2;i<=N-1;i++){
        res = max(res, ps[N]-ps[0]-V[N]-V[i]+ps[i-1]);
    }
    for(int i=2;i<=N-1;i++){
        res = max(res, ps[i]-V[1]+ps[N-1]-ps[i-1]);
    }
    cout << res;
}