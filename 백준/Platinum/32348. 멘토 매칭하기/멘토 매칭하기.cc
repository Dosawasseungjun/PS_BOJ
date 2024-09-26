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

const int MAX = 2e5+1;
const ll MOD = 1e9+7;

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

Number_Theory<MAX, MOD> nt;

int main(){
    fast_io
    nt.precal();
    int N, M;
    cin >> N >> M;
    vector<ll> A(N+1), B(M+1);
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1;i<=M;i++) cin >> B[i];
    sort(++A.begin(), A.end());
    sort(++B.begin(), B.end());
    ll x = numeric_limits<ll>().max();
    for(int i=1, j=M;i<=N;i++){
        x = min(x, A[i] + B[j]);
        if(j) j--;
    }
    ll res = 1;
    ll left_student = 0;
    ll left_mentor = M;
    for(int i=1;i<=N;i++){
        if(A[i] < x){
            ll mt = (B.end() - lower_bound(B.begin(), B.end(), x - A[i])); // 가능한 멘토의 수
            mt -= M - left_mentor; // 이미 매칭된 멘토 빼기
            res = res * mt % MOD;
            left_mentor--;
        }else{
            left_student++;
        }
    }
    ll k = 0;
    for(int i=0;i<=min(left_student, left_mentor);i++){
        // 학생 중 매칭할 i명을 골라, 그 다음에 멘토들 i명 매칭
        k += (nt.binomial(left_student, i) * nt.fac[left_mentor]) % MOD * nt.fastex(nt.fac[left_mentor-i], MOD-2);
        k %= MOD;
    }

    res = res * k % MOD;
    cout << res;
}