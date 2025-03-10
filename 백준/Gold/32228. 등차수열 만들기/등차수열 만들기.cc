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

// 오일러 파이 함수: n에 대해 φ(n)를 계산
ll eulerPhi(ll n) {
    ll result = n;
    for (ll p = 2; p * p <= n; p++){
        if(n % p == 0) {
            while(n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if(n > 1) {
        result -= result / n;
    }
    return result;
}

int main(){
    fast_io
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(int &a : A) cin >> a;
    cout << eulerPhi(M);
}