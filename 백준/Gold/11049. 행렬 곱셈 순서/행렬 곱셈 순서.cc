#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int BIGINT = 2147483637;
int n;
int arr[502];
long long dp[501][501];

long long calculateNum(int start, int last){
    long long &ret = dp[start][last];
    
    if(last-start==1) return 0;
    if(last-start==2){
        return arr[start]*arr[start+1]*arr[last];
    }
    if(ret) return ret;
    ret = BIGINT;
    for(int i=start;i<last-1;i++){
        ret = min(ret, calculateNum(start, i+1)+calculateNum(i+1, last)+arr[start]*arr[i+1]*arr[last]);
    }
    return ret;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> arr[i] >> arr[i+1];
    }
    
    cout << calculateNum(0, n);
}
