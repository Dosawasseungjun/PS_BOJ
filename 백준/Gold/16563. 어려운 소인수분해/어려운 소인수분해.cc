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

vector<ll> eratos(int n){ // n은 1이상의 자연수 
    vector<ll> table(n+1, 0), primes;
    // table[i] = i면 소수
    // table[i] != i면 합성수고 i를 인수로 가짐
    for(ll i = 2 ; i <= n; i++){
        if(table[i]) continue;
        table[i] = i; // 색칠하고
        primes.push_back(table[i]);
        for(ll j = i * i; j < n; j += i){
            table[i] = i;
        }
    }
    return primes;
    // return table;
}

template <int SZ>
struct NumTheory{
    vector<ll> primes;
    ll table[SZ + 1];
    vector<ll> eratos(int sz = SZ){
        table[1] = 1; // 소인수분해 할때만 1로 해둡시다.예외로
        for(ll i = 2;i<sz;i++){
            if(table[i]) continue;
            table[i] = i;
            primes.push_back(i);
            for(ll j = i * i; j < sz ; j += i){
                table[j] = i;
            }
        }
        return primes;
    }
    vector<int> factorization(int n){
        vector<int> ret;
        while(n != 1){
            ret.push_back(table[n]);
            n /= table[n];
        }
        // ret.push_back(1);
        sort(ret.begin(), ret.end());
        return ret;
    }
};

template <int SZ, ll MOD>
struct PrimeControl
{
    vector<ll> P;
    ll p[SZ + 1];
    // p[i] = i면 소수 - 물론 1은 제외
    // P[i] != i면 합성수고 i를 인수로 가짐
    void eratos(int sz = SZ)
    {
        p[1] = 1;
        for (ll i = 2; i < sz; i++)
        {
            if (p[i])
                continue;
            p[i] = i;
            P.push_back(i);
            for (ll j = i * i; j < sz; j += i)
                p[j] = i;
        }
    }
    // n을 소인수 분해
    vector<int> factorization(int n)
    {
        vector<int> ret;
        while (n != 1)
        {
            ret.push_back(p[n]);
            n /= p[n];
        }
        return ret;
    }
};

vector<ll> factors(int x){ // x를 소인수분해
    vector<ll> f;
    for(ll i = 1; i * i<= x; i++){
        if(x % i == 0){
            ll a = i;
            ll b = x / i;
            if(a != b) f.push_back(a);
            f.push_back(b);
        }
    }
    return f;
}

const int MAX = 5e6;
NumTheory<MAX> nt; // table 용량땜에 전역변수로 했음
int main(){
    fast_io
    int n; cin >> n;
    nt.eratos();
    for(int i=0;i<n;i++){
        int k; cin >> k;
        vector<int> factors = nt.factorization(k);
        for(int f : factors){
            cout << f << ' ';
        }
        cout << '\n';
    }
}