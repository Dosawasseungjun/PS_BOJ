#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#define fast_io cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;

int n;
int dp[100001];

int solve(int n){
    int &ret = dp[n];
    if(ret) return ret;
    ret = 987654321;
    for(int i=1;i*i<n;i++){
        ret = min(ret, 1+solve(n-i*i));
    }
    return ret;
}

int main(){
    fast_io;
    cin >> n;
    for(int i=0;i*i<100001;i++){
        dp[i*i] = 1;
    }
    cout << solve(n);
}
