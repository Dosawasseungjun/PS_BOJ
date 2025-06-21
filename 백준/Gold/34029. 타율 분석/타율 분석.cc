#include <iostream>
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
    double A;
    int B;
    cin >> A >> B;
    vector dp = vector(B+1, vector<double>(B+1, 0)); // dp[i][j] : i번의 타석에서, j번 타격성공했을 때 확률
    double p = A, q = 1-A;
    dp[0][0] = 1;
    for(int i=1;i<=B;i++){
        for(int j=0;j<=B;j++){
            dp[i][j] = dp[i-1][j] * q + (j ? dp[i-1][j-1] * p : 0);
        }
    }
    int c = -1;
    double R = 0;
    while(R + dp[B][c+1] < 0.05){
        c++;
        R += dp[B][c];
    }
    cout << c+1 ;
}