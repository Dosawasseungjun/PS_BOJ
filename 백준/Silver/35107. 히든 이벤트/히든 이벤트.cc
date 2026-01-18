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
    int n, m, k; cin >> n >> m >> k;
    double p = n-m, q = n;
    double x = 1;
    cout << fixed;
    cout.precision(12);
    for(int i=0;i<k;i++){
        x *= p / q;
        p -= 1; q -= 1;
        cout << 1 - x << '\n';
    }
}