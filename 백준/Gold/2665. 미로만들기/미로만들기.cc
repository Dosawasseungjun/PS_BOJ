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

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

int main(){
    fast_io
    int n; cin >> n;
    vector<string> S(n);
    for(int i=0;i<n;i++) cin >> S[i];
    vector D = vector(n, vector<int>(n, -1));
    deque<pii> dq;
    D[0][0] = 0;
    dq.push_back({0, 0});
    while(!dq.empty()){
        auto [y, x] = dq.front();
        dq.pop_front();
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny>=0&&ny<n&&nx>=0&&nx<n&&D[ny][nx]==-1){
                if(S[ny][nx] == '1'){
                    D[ny][nx] = D[y][x];
                    dq.push_front({ny, nx});
                }else{
                    D[ny][nx] = D[y][x] + 1;
                    dq.push_back({ny, nx});
                }
            }
        }
    }

    cout << D[n-1][n-1];
}