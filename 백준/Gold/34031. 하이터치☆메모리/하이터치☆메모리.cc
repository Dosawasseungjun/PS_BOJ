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
    string A, B;
    cin >> A >> B;
    int n = A.length();
    int m = B.length();
    vector<ll> ps1(n+1, 0), ps2(m+1, 0);
    for(int i=0;i<n;i++){
        ps1[i+1] = ps1[i]+(A[i] == '(' ? 1 : -1);
    }
    for(int i=0;i<m;i++){
        ps2[i+1] = ps2[i]+(B[i] == '(' ? 1 : -1);
    }
    ll res = 0;
    vector<ll> cnt(n+1, 0);
    for(int i=1;i<=n;i++){
        if(ps1[i] < 0){
            break;
        }else{
            cnt[ps1[i]]++;
        }
    }
    ll mn = 2e5+1;
    for(int i=1;i<=m;i++){
        mn = min(mn, ps2[i]);
        if(ps2[i] > 0) continue;
        ll x = -ps2[i];
        if(ps2[i] > mn) continue;
        res += (cnt[x]);
    }
    cout << res;
}