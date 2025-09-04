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
    vector G = vector(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> G[i][j];
        }
    }
    string fox = "FOX";
    const int dy[] = {1, 1, 1, -1, -1, -1, 0, 0};
    const int dx[] = {-1,0, 1, -1, 0, 1, -1, 1};
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<8;k++){
                int ny = i, nx = j;
                bool ok = true;
                for(int p=0;p<3;p++){
                    if(ny >=0 && ny < n && nx >=0 && nx < m && fox[p] == G[ny][nx]){
                        ny += dy[k];
                        nx += dx[k];
                    }else{
                        ok = false;
                        break;
                    }
                }
                if(ok) res += 1;
            }
        }
    }
    cout << res;
}