#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cassert>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 987654321;
const int MOD = 1e9+7;

int n, m;
char grid[11][11];
int dp[11][1<<11];
vector<pii> states[11];

void calStates(int row, int col, int state, int cnt){
    if(col>=m){
        states[row].push_back({state, cnt});
        return;
    }
    
    if(grid[row][col]=='x'){
        calStates(row, col+1, state, cnt);
        return;
    }
        
    calStates(row, col+2, state|1<<col, cnt+1);
    calStates(row, col+1, state, cnt);
    return;
}

bool checker(int state1,int state2){
    for(int i=0;i<m;i++){
        if(state1&(1<<i)){
            if(i>0&&state2&1<<(i-1)) return false;
            if(state2&1<<(i+1)) return false;
        }
    }
    return true;
}

int solve(){
    int res = 0;
    for(pii pi : states[0]){
        dp[0][pi.first] = pi.second;
        res = max(res, dp[0][pi.first]);
    }
    
    for(int i=1;i<n;i++){
        for(pii pj : states[i]){
            for(pii pk : states[i-1]){
                if(checker(pj.first, pk.first)){
                    dp[i][pj.first] = max(dp[i][pj.first], dp[i-1][pk.first]+pj.second);
                    res = max(res, dp[i][pj.first]);
                }
            }
        }
    }
    return res;
}

int main(){
    fast_io;
    int tt; cin >> tt;
    while (tt--) {
        cin >> n >> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cin >> grid[i][j];
        }
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<11;i++) states[i].clear();
        for(int i=0;i<n;i++) calStates(i, 0, 0, 0);
        cout << solve() << '\n';
    }
}
