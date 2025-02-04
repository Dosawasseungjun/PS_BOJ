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
    int n, w; cin >> n >> w;
    vector<pii> items;
    for(int i=0;i<n;i++){
        int x =1, v, c, k;
        cin >> v >> c >> k;
        while(k > x){
            k -= x;
            items.push_back({x*v, x*c});
            x *= 2;
        }
        items.push_back({k*v, k*c});
    }

    vector<int> dp(w+1);
    for(auto [weight, value] : items){
        for(int j=w;j>=weight;j--){
            dp[j] = max(dp[j] ,dp[j-weight] + value);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) ;
}