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
    vector<pii> A(N);
    for(int i=0;i<N;i++) cin >> A[i].xx >> A[i].yy;
    sort(A.begin(), A.end());
    ll res = 0, now = 0;
    for(auto [idx, c] : A){
        if(c >= now) {
            now = c;
        }else{
            res += now - c;
            now = c;
        }
    }
    cout << res + now;
}