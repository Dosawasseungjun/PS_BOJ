#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
#define xx first
#define yy second

int main(){
    fast_io    
    int n, m; cin >> n >> m;
    vector<vector<char>> A(n+1, vector<char>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> A[i][j];
        }
    }
    ll res = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int p=1;p<=min(10, n-i+1);p++){
                vector<int> cnt(10, 0);
                bool f = true;
                int r = 0;
                while(r < 10){
                    if(j+r > m){ f = false; break;}
                    for(int q=0;q<p;q++){
                        if((++cnt[A[i+q][j+r]-'0']) > 1) f = false;
                    }
                    if(!f) break;
                    else{
                        r++;    
                    }
                }
                res += r;
            }
        }
    }
    cout << res;
}