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
    int n;
    while(cin >> n){
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        vector<int> x(n);
        for(int i=1;i<n;i++){
            int d = abs(a[i] - a[i - 1]);
            if(d < n) x[d] = 1;
        }
        bool ok = true;
        for(int i=1;i<n;i++) if(!x[i]) ok = false;
        cout << (ok ? "Jolly\n" : "Not jolly\n");
    }
}