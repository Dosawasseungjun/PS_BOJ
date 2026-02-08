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
    int n, m; cin >> n >> m;
    vector G = vector(n+1, vector<int> (m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> G[i][j];
        }
    }
    vector A = vector(min(n, m)+1, vector<int>(max(n, m)+1));
    if(n > m){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                A[i][j] = G[j][i];
            }
        }
        swap(n, m);
    }else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                A[i][j] = G[i][j];
            }
        }
    }
    ll res = 0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            vector<ll> D(21, 0);
            for(int k=1;k<=m;k++){
                D[A[i][k] + A[j][k]]++;
            }

            for(int k=1;k<=10;k++){
                if(k == 10){
                    res += D[k] * (D[k] - 1) / 2;
                }else{
                    res += D[k] * D[20-k];
                }
            }
        }
    }
    cout << res;
}