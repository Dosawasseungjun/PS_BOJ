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


template<int SZ, ll MOD> struct PrimeControl{
    vector<ll> P;
    ll p[SZ+1];
    // p[i] = i면 소수 - 물론 1은 제외
    // P[i] != i면 합성수고 i를 인수로 가짐
    void eratos(int sz = SZ){
        p[1] = 1;
        for(ll i=2;i<sz;i++){
            if(p[i]) continue;
            p[i] = i;
            if(i >= 2000) P.push_back(i); // 2000이 넘는 소수만
            for(ll j=i*i;j<sz;j += i) p[j] = i;
        }
    }
};

PrimeControl<2501, 1000000009> pc;

int main(){
    fast_io
    int K, N; cin >> K >> N;
    pc.eratos();
    for(int j=0;j<K;j++){
        for(int i=1;i<=N;i++){
            cout << pc.P[j] * i << ' ';
        }
        cout << '\n';
    }
    
}