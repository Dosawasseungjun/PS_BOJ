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

int n;

int main(){
    fast_io
    while(1){
        cin >> n;
        if(!n) break;
        vector<ll> legs(n);
        for(int i=0;i<n;i++) cin >> legs[i];
        ll res = LLONG_MAX;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=i+(n-1)/2;j++){
                for(int k=j+1;k<=j+(n-1)/2;k++){
                    if((i - k + n) % n <= (n-1)/2){
                        ll mn = min({legs[i], legs[j % n], legs[k % n]});
                        ll ans = 0;
                        for(int p=0;p<n;p++) ans += max(0LL, legs[p] - mn); 
                        res = min(res, ans);
                    }
                }
            }
        }
        // 짝수
        if((n & 1) == 0){
            for(int i=0;i<n/2;i++){
                ll mn = min(legs[i], legs[i+n/2]); // 맞은편
                ll a = 0, b=0;
                for(int j=i+1;j<i+n/2;j++) a = max(a, legs[j%n]);
                for(int j=i+n/2+1;j<i+n;j++) b = max(b ,legs[j % n]);
                mn = min({mn, a, b});
                ll ans = 0;
                for(int p=0;p<n;p++) ans += max(0LL, legs[p] - mn);
                res = min(res, ans);
            }
        }
        cout << res << "\n\n";
    }
}