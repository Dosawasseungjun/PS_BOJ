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
    ll L, N, K; cin >> L >> N >> K;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    map<ll, ll> mp;
    mp[0] = N;
    if(A[0] != 0) mp[A[0]] += 1;
    if(A[N-1] != L) mp[L-A[N-1]] += 1;
    for(int i=1;i<N;i++){
        ll d = A[i] - A[i-1] - 1;
        if(d == 0) continue;
        if(d & 1){
            mp[d/2] += 1;
            mp[d-d/2] += 1;
        }else{
            mp[d/2] += 2;
        }
    }
    ll pre = 0;
    for(auto it = (--mp.end()); it != mp.begin();it--){
        (it -> yy) += pre;
        pre = it->yy;
    }
    for(int i=0;i<min(K, N);i++){
        cout << "0\n";
    }
    K -= min(K , N);
    ll y = 1;
    auto it = ++mp.begin();
    while(K){
        while(y > (it->xx)) it++;
        ll x = min(K, it->yy);
        for(int i=0;i<x;i++){
            cout << y << '\n';
        }
        K -= x;
        y += 1;
    }

}