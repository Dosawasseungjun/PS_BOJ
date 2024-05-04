#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
#define xx first
#define yy second

const int MAX = 1e5+1;
const int INF = 1e9+7;
int dp[MAX][16];    //i까지 보고 상태가 s일 때 최소 힘
int main(){
    fast_io
    vector<int> a;
    a.push_back(0);
    while (1) {
        int k; cin >> k;
        if(!k) break;
        a.push_back(k);
    }
    for(int i=0;i<MAX;i++) for(int j=0;j<16;j++) dp[i][j] = INF;
    dp[0][0] = 0;
    for(int i=1;i<a.size();i++){
        for(int j=0;j<16;j++){
            if(dp[i-1][j]==INF) continue;
            if(!j){
                dp[i][1<<(a[i]-1)] = min(dp[i][1<<(a[i]-1)] , dp[i-1][j] + 2);
            }else if(j & (1<<(a[i]-1))){
                dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            }else{
                if(j==1||j==2||j==4||j==8){
                    dp[i][j|1<<(a[i]-1)] = min(dp[i][j|1<<(a[i]-1)], dp[i-1][j] + 2);
                    dp[i][1<<(a[i]-1)] = min(dp[i][1<<(a[i]-1)], dp[i-1][j]+
                                             (((j|1<<(a[i]-1))==5||(j|1<<(a[i]-1))==10) ? 4 : 3));
                }
                int tmp = 1;
                vector<int> T;
                int cnt = 1;
                while(tmp!=16){
                    if(j&tmp) T.push_back(cnt);
                    tmp <<= 1;
                    cnt++;
                }
                if(T.size()!=2) continue;
                int idx1 = (0 | (1<<(T[0]-1)) )| 1<<(a[i]-1);
                dp[i][idx1] = min(dp[i][idx1], dp[i-1][j]+
                                  (((1<<(T[1]-1)|1<<(a[i]-1))==5||(1<<(T[1]-1)|1<<(a[i]-1))==10) ? 4 : 3));
                int idx2 = (0 | (1<<(T[1]-1)) )| 1<<(a[i]-1);
                dp[i][idx2] = min(dp[i][idx2], dp[i-1][j]+
                                  (((1<<(T[0]-1)|1<<(a[i]-1))==5||(1<<(T[0]-1)|1<<(a[i]-1))==10) ? 4 : 3));
            }
        }
    }
    int res = INF;
    for(int i=0;i<16;i++) res = min(res, dp[a.size()-1][i]);
    cout << res;
}
