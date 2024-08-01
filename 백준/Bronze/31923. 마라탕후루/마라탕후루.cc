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
    int N, P, Q; cin >> N >> P >> Q;
    vector<int> A(N), B(N);
    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<N;i++) cin >> B[i];
    vector<int> ans(N);

    bool ok = true;
    for(int i=0;i<N;i++){
        int d1 = P - Q;
        int d2 = A[i] - B[i];
        if(d1 * d2 < 0 || !d2){
            if(d1 && d2 % d1 == 0) ans[i] = abs(d2 / d1);
            else if(d1 == 0 && d2 == 0) ans[i] = 0;
            else ok= false;
        }else ok = false;
    }
    if(ok){
        cout << "YES\n";
        for(int a : ans) cout << a << ' ';
    }else{
        cout << "NO\n";
    }
}