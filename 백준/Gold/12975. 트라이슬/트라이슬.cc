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
    vector dp(256, vector(256, vector<int>(8, 0)));
    dp[0][0][0] = 1;
    int all_xor = 0;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        all_xor ^= x;
        vector<tiii> tmp;
        for(int j=0;j<256;j++){
            for(int k=0;k<256;k++){
                for(int p=8;p>=0;p--){
                    if(dp[j][k][p]){
                        tmp.push_back({j ^ x, k, p | (1 << 2)});
                        tmp.push_back({j, k ^ x, p | (1 << 1)});
                        tmp.push_back({j, k, p | (1 << 0)});
                    }
                }
            }
        }
        for(int j=0;j<256;j++){
            for(int k=0;k<256;k++){
                for(int p=8;p>=0;p--){
                    dp[j][k][p] = 0;
                }
            }
        }
        
        for(auto [a, b, c] : tmp){
            dp[a][b][c] = 1;
        }
    }
    int mx = 0;
    for(int i=0;i<256;i++){
        for(int j=0;j<256;j++){
            if(dp[i][j][7]) mx = max(mx, i + j + (all_xor ^ i ^ j));
        }
    }
    cout << mx;
}