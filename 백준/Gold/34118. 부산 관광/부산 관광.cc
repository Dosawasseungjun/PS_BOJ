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

const int inf = 1e9;

int main(){
    fast_io
    int n; cin >> n;
    string a, b;
    cin >> a >> b;
    a = "0" + a;
    b = "0" + b;
    int p[5];
    int q[] = {0, 1, 3, 5, 4};
    p[0] = 0;
    cin >> p[1] >> p[2] >> p[3] >> p[4];
    vector dp = vector(6, vector(6, vector<int>(5, inf)));
    // dp[i][j][k] : 한국이는 개인티켓이 i일 남았고, 정올이는 j일 남았고, 묶음권은 k일 남았을 때 최소비용
    
    dp[0][0][0] = 0;
    for(int t=1;t<=n;t++){
        vector ndp = vector(6, vector(6, vector<int>(5, inf)));
        for(int i=0;i<=5;i++){
            for(int j=0;j<=5;j++){
                for(int k=0;k<=4;k++){
                    if(dp[i][j][k] != inf){
                        int ri = max(0, i-1);
                        int rj = max(0, j-1);
                        int rk = max(0, k-1);
                        
                        for(int x=0;x<4;x++){
                            for(int y=0;y<4;y++){
                                int ni = max(ri, q[x]);
                                int nj = max(rj, q[y]);
                                int nk = rk;

                                if((ni >= (a[t] - '0') && nj >= (b[t] - '0')) || nk) {
                                    ndp[ni][nj][nk] = min(ndp[ni][nj][nk], dp[i][j][k] + p[x] + p[y]);
                                }
                            }
                        }

                        ndp[ri][rj][4] = min(ndp[ri][rj][4], dp[i][j][k] + p[4]);
                    }
                }
            }
        }

        dp.swap(ndp);
    }

    int res = inf;
    for(int i=0;i<=5;i++){
        for(int j=0;j<=5;j++){
            for(int k=0;k<=4;k++){
                res = min(res, dp[i][j][k]);
            }
        }
    }
    cout << res;
}