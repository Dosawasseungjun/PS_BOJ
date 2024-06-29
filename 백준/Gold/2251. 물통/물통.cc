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
    int a, b, c; cin >> a >> b >> c;
    vector vst = vector(201, vector(201, vector<int> (201, 0)));
    vst[0][0][c] = 1;
    queue<tiii> q;
    q.push({0, 0, c});
    while(!q.empty()){
        auto [x, y, z] = q.front();
        q.pop();
        int over = 0;
        if(x){
            // 1 to 2
            over = max(0, y + x - b);
            if(!vst[over][min(b, y + x)][z]){
                vst[over][min(b, y + x)][z] = 1;
                q.push({over, min(b, y+x), z});
            }
            // 1 to 3
            over = max(0, x + z - c);
            if(!vst[over][y][min(c, x+z)]){
                vst[over][y][min(c, x + z)] = 1;
                q.push({over, y, min(c, x+z)});
            }
        }
        
        if(y){
            // 2 to 1
            over = max(0, x + y - a);
            if(!vst[min(a, x + y)][over][z]){
                vst[min(a, x + y)][over][z] = 1;
                q.push({min(a, x+y), over, z});
            }
            // 2 to 3
            over = max(0, y + z - c);
            if(!vst[x][over][min(c, y + z)]){
                vst[x][over][min(c, y + z)] = 1;
                q.push({x, over, min(c, y+z)});
            }
        }
        
        if(z){
            // 3 to 1
            over = max(0, x + z - a);
            if(!vst[min(a, x + z)][y][over]){
                vst[min(a, x + z)][y][over] = 1;
                q.push({min(a, x+z), y, over});
            }
            // 3 to 2
            over = max(0, y + z - b);
            if(!vst[x][min(b, y + z)][over]){
                vst[x][min(b, y + z)][over] = 1;
                q.push({x, min(b, y+z), over});
            }
        }
        
    }
    vector<int> C(201, 0);
    
    for(int j=0;j<201;j++){
        for(int k=0;k<201;k++) if(vst[0][j][k]) C[k] = 1;
    }
    
    for(int i=0;i<=200;i++) if(C[i]) cout << i << ' ';
}