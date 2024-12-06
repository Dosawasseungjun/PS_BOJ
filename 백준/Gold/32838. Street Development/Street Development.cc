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

int L, n;
vector<int> a;
const int INF = 1e9+1;

bool can(int m){
    vector<int> pfx(n), sfx(n);
    for(int i=0;i<n;i++){
        if(i > 0 && pfx[i-1] < a[i]){
            if(pfx[i-1] < a[i] - m){
                pfx[i] = -INF;
            }else{
                pfx[i] = pfx[i-1] + (m - (a[i] - pfx[i-1]));
            }
        }else{
            pfx[i] = a[i] + m;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(i < n-1 && sfx[i+1] > a[i]){
            if(sfx[i+1] > a[i] + m){
                sfx[i] = INF;
            }else{
                sfx[i] = sfx[i+1] - (m - (sfx[i+1] - a[i]));
            }
        }else{
            sfx[i] = a[i] - m;
        }
    }

    for(int i=1;i<n;i++){
        if(pfx[i-1] >= sfx[i]) return true;
    }
    return false;
}

int main(){
    fast_io
    cin >> L >> n ;
    a = vector<int> (n);
    for(int i=0;i<n;i++) cin >> a[i];
    int lo = 0, hi = L+1;
    while(lo + 1 < hi){
        int mid = (lo + hi) >> 1;
        if(can(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi;
}