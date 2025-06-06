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

template<int SZ, ll B_MOD> struct Number_Theory{
    vector<ll> fac;
    void precal(int sz = SZ){
        fac = vector<ll> (sz+1);
        fac[0] = 1;
        for(int i=1;i<=sz;i++){
            fac[i] = fac[i-1]*i;
            fac[i] %= B_MOD;
        }
    }
    
    ll fastex(ll a, ll e){
        if(!e) return 1;
        if(e==1) return a%B_MOD;
        ll half = fastex(a, e/2);
        ll ret = half*half%B_MOD;
        if(e&1) ret = (ret*a)%B_MOD;
        return ret;
    }
    
    ll binomial(int n, int k){   // 페르마 소정리, 모듈러 곱셈 역원을 이용한 이항계수
        return (fac[n]*fastex(fac[n-k]*fac[k]%B_MOD, B_MOD-2))%B_MOD;
    }
};

const int MAX = 4e6+1;
const ll MOD = 1e9+7;
Number_Theory<MAX, MOD> nt;

int main(){
    fast_io
    int n; cin >> n;
    if(n == 2){
        cout << "0 3";
        return 0;
    }
    if(n == 3){
        cout << "1 4";
        return 0;
    }
    if(n == 4){
        cout << "2 4";
        return 0;
    }
    if(n == 5){
        cout << "3 6";
        return 0;
    }

    nt.precal(n);

    cout << nt.binomial(n-2, (n-2)/2) << ' ' << (n & 1 ? 4 : 2);
}