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
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> T(N+1);
    for(int i=1;i<=N;i++) cin >> T[i];
    sort(++T.begin(), T.end());
    int res = 0;
    for(int i=0;i<=N;i++){
        for(int j=0;j<A;j++){
            int t = 0, r = 0;
            int x = A;
            for(int k=1;k<=N;k++){
                if(x == A && r == i) {
                    x -= j;
                    t += B * j;
                }
                
                if(T[k] >= t + x){
                    r++;
                    t += x;
                }
            }
            res = max(res, r);
        }
    }
    cout << res;
}