#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vector<int> a(N);
    for(int i=0;i<N;i++) cin >> a[i];
    if(K <= 3){
        cout << (N+2)/3;
        return 0;
    }

    int p = 0, q =0;
    int pre = -100;    
    vector<int> dp(N, 1000000000);
    dp[0] = 1; dp[1] = 1; dp[2] = 1;
    for(int i=0;i<N;i++){
        if(abs(pre - a[i]) == 1){
            q++;
        }else{
            q = 1;
        }
        pre = a[i];
        if(i - 1 >= 0) dp[i] = min(dp[i], dp[i-1] + 1);
        if(i - 2 >= 0) dp[i] = min(dp[i], dp[i-2] + 1);
        if(i - 3 >= 0) dp[i] = min(dp[i], dp[i-3] + 1);
        if(q >= K) dp[i] = min(dp[i], dp[i-K] + 1);
    }

    cout << dp[N-1];
}