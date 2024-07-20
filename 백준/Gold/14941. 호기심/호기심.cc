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

PrimeControl<MAX, 1000000009> pc;


int main(){
    fast_io
    int n; cin >> n;
    pc.eratos();
    vector<ll> ps1(MAX, 0), ps2(MAX, 0);
    vector<int> A(MAX, 0);
    for(int i=2, j=0;i<MAX;i++){
        ps1[i] = ps1[i-1];
        ps2[i] = ps2[i-1];
        if(pc.p[i] == i){  //소수면
            if(j & 1){
                ps1[i] += i;
                A[i] = 1;
            }else{
                ps2[i] += i;
                A[i] = 2;
            }
            j++;
        }
    }

    while(n--){
        int a, b;
        cin >> a >> b;
        int k = *lower_bound(pc.P.begin(), pc.P.end(), a);
        if(A[k] == 1){
            cout << 3LL * (ps1[b] - ps1[a-1]) - (ps2[b]-ps2[a-1]) << '\n';
        }else{
            cout << 3LL * (ps2[b] - ps2[a - 1]) - (ps1[b] - ps1[a - 1]) << '\n';
        }
    }
}