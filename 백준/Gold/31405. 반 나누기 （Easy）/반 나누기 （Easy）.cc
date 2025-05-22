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

double f(vector<pll> p){
    double res = 0;
    vector<pll> tmp = p;
    tmp.push_back(p[0]);
    for(int i=0;i<p.size();i++){
        res += tmp[i].xx*tmp[i+1].yy - tmp[i+1].xx*tmp[i].yy;
    }
    return abs(res) / 2.0;
}

int main(){
    fast_io
    int n; cin >> n;
    vector<pll> P(n);
    for(int i=0;i<n;i++) cin >> P[i].xx >> P[i].yy;
    double S = f(P);
    double hs = S/2.0;
    double A = 0;
    int idx = 1;
    while(A + f({P[0], P[idx], P[idx+1]}) < hs) {
        A += f({P[0], P[idx], P[idx + 1]});
        idx++;
    }
    double k1 = hs - A;
    double k = f({P[0], P[idx], P[idx+1]});
    cout << fixed; cout.precision(15);
    cout << "YES\n";
    cout << "1 0" << '\n';
    cout << idx+1 << ' ' << k1 / k << '\n';
}