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
    int N, K, D;
    cin >> N >> K >> D;
    vector<pair<ll, vector<ll>>> S(N);
    for(int i=0;i<N;i++){
        ll M, d; cin >> M >> d;
        vector<ll> al(M);
        for(int j=0;j<M;j++) cin >> al[j];
        sort(al.begin(), al.end());
        S[i] = {d, al};
    }
    sort(S.begin(), S.end());
    vector<ll> cnt(31, 0);
    ll res = 0;
    for(int i=0, j=0;i<N;i++){
        while(j < i && D < S[i].xx - S[j].xx){
            for(int x : S[j].yy){
                cnt[x]--;
            }
            j++;
        }
        for(int x : S[i].yy) cnt[x]++;
        ll all_algo = 0, all_know = 0;
        ll sz = i - j + 1;
        for(int n = 1; n <= 30; n++){
            if(cnt[n]) all_algo++;
            if(cnt[n] == sz) all_know++;
        }
        res = max(res, (all_algo - all_know) * sz);
    }
    cout << res;
}