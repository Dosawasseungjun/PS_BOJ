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
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << a[0];
        return 0;
    }
    sort(a.begin(), a.end());
    double x = (a[0] + a[1]) / 2.0;
    for(int i=2;i<n;i++){
        x = (x + a[i]) / 2.0;
    }
    cout << fixed;
    cout.precision(15);
    cout << x;
}