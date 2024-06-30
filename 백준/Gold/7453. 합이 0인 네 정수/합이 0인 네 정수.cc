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
    vector<int> A(n), B(n), C(n), D(n);
    for(int i=0;i<n;i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    vector<int> P1, P2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            P1.push_back(A[i] + B[j]);
            P2.push_back(C[i] + D[j]);
        }
    }
    sort(P1.begin(), P1.end());
    sort(P2.begin(), P2.end());
    int r = P2.size() - 1;
    ll res = 0;
    ll k1 = 1, k2 = 0;
    for(int i=0;i<P1.size();i++){
        if(i < P1.size() - 1 && P1[i] == P1[i+1]){
            k1++;
            continue;
        }
        while(r >= 0 && P1[i] + P2[r] >= 0){
            if(P1[i] + P2[r] == 0) k2++;
            r--;
        }
        res += k1 * k2;
        k1 = 1;
        k2 = 0;
    }
    cout << res;
}