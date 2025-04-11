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
    for(int i=0;i<n;i++) cin >> a[i];
    bool ok = true;
    int pre = -1;
    for(int i=0;i<n;i++){
        if(a[i] >= pre){
            pre = a[i];
        }else{
            ok = false;
            break;
        }
    }
    pre = -1;
    for(int i=0;i<n;i++){
        if(a[i] == 1){
            pre = -1;
            continue;
        }
        if(pre != -1){
            ok = true;
            break;
        }
        int k = a[i];
        bool isprime = true;
        for(int j=2;j*j<=k;j++){
            if(k % j == 0) isprime = false;
        }
        if(!isprime) {
            ok = true;
            break;
        }
        pre = a[i];
    }

    cout << (ok ? "YES" : "NO");
}