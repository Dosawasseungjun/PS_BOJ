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
    int a, d, k; cin >> a >> d >> k;
    int A = a;
    double P = d / 100.0;
    double RP = 1.0;
    double res = 0;
    while(P < 1){
        res += A * P * RP;
        RP *= (1 - P);
        P += P * k / 100;
        A += a;
    }
    res += A * RP;
    cout << fixed;
    cout.precision(10);
    cout << res;
}