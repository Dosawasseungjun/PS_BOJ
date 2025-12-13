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
    int L, N; cin >> L >> N;
    vector<string> S(N);
    for(int i=0;i<N;i++){
        cin >> S[i];
    }
    int K; cin >> K;
    map<string, int> mp;
    for(int i=0;i<N;i++){
        for(int j=0;j<=L-K;j++){
            mp[S[i].substr(j, K)] += 1;
        }
    }
    int mx = 0;
    for(auto [key, val] : mp){
        mx = max(mx, val);
    }
    cout << mx;
}