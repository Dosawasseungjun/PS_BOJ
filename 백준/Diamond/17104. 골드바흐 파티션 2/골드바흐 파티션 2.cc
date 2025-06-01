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


typedef complex<double> cpx;

// 비재귀 구현
struct FFT{
    void fft(vector<cpx> &a, bool inv){
        int n = a.size();
        
        for(int i=1, j=0;i<n;i++){
            int bit = n >> 1;
            while(j >= bit){
                j -= bit;
                bit >>= 1;
            }
            j += bit;
            if(i < j) swap(a[i], a[j]);
        }

        double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
        vector<cpx> roots(n / 2);

        for(int i=0;i<n/2;i++){
            roots[i] = cpx(cos(ang * i), sin(ang * i));
        }

        for(int i=2;i<=n;i <<= 1){
            int step = n / i;
            for(int j=0;j<n;j+=i){
                for(int k=0;k<i/2;k++){
                    cpx u = a[j + k], v = a[j + k + i/2] * roots[step * k];
                    a[j + k] = u + v;
                    a[j + k + i/2] = u - v;
                }
            }
        }
        if(inv){
            for(int i=0;i<n;i++) a[i] /= n;
        }
    }

    vector<cpx> mul(vector<cpx> a, vector<cpx> b){
        int n = 1;
        while(n < a.size() + b.size()) n <<= 1;
        a.resize(n); b.resize(n);
        vector<cpx> c(n);

        fft(a, 0); fft(b, 0);

        for(int i=0;i<n;i++) c[i] = a[i] * b[i];

        fft(c, 1);

        return c;
    }
};

template<int SZ> struct PrimeControl{
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

const int MAX = 1000001;
FFT fft_class;
PrimeControl<MAX> p_class;
vector<cpx> c;

void solv(){
    int n; cin >> n;
    if(n == 4) cout << 1 << '\n';
    else cout << ((ll)round(c[(n-2)/2].real())+1) / 2 << '\n';
}

int main(){
    fast_io
    p_class.eratos();
    vector<cpx> a(MAX/2), b(MAX/2);
    for(int p : p_class.P){
        if(p == 2) continue;
        // N = 2K = (2a+1) + (2b+1)
        // a + b = (N-2) / 2 - N은 4이상의 짝수니까 성립       
        a[(p-1)/2] = b[(p-1)/2] = 1;
        // cout << (p-1)/2 << ' ';
    }
    c = fft_class.mul(a, b);
    int tt; cin >> tt;
    while(tt--) solv();
}