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
            P.push_back(i);
            for(ll j=i*i;j<sz;j += i) p[j] = i;
        }
    }
    // n을 소인수 분해
    vector<int> factorization(int n){
        vector<int> ret;
        while(n!=1){
            ret.push_back(p[n]);
            n /= p[n];
        }
        return ret;
    }
};

const int MAX = 1e5+1;
PrimeControl<MAX, numeric_limits<ll>::max()> pc;

int main(){
    fast_io    
    pc.eratos();
    int a, b; cin >> a >> b;
    int res = 0;
    for(int i=a;i<=b;i++){
        vector<int> f = pc.factorization(i);
        int sz = f.size();
        if(sz != 1 && pc.p[sz] == sz) res += 1;
    }
    cout << res;
}