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
    int N, M;
    cin >> N >> M;
    int R, G, B;
    cin >> R >> G >> B;
    vector<pii> b = {{R, 0}, {G, 1}, {B, 2}};
    sort(b.begin(), b.end());
    vector g = vector(N+2, vector<int> (M+2, -1));
    int a1 = 0, a2 =0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if((i + j) & 1){
                g[i][j] = b[1].yy;
                a2++;
            }else{
                g[i][j] = b[2].yy;
                a1++;
            }
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(((i+j) & 1) == 0 && a1 > b[2].xx && b[0].xx){
                a1--;
                g[i][j] = b[0].yy;
                b[0].xx--;
            }
        }
    }
    bool ok = true;
    for(int i=N;i>=1;i--){
        for(int j=M;j>=1;j--){
            if ((i + j) & 1 && a2 > b[1].xx && b[0].xx && !(g[i - 1][j] == b[0].yy || g[i][j - 1] == b[0].yy || g[i][j + 1] == b[0].yy || g[i + 1][j] == b[0].yy))
            {
                a2--;
                g[i][j] = b[0].yy;
                b[0].xx--;
            }
        }
        
    }
    ok &= (a1 == b[2].xx) & (a2 == b[1].xx) ;
    if(ok){
        cout << "YES\n";
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                if(g[i][j] == 0) cout << "R";
                else if(g[i][j] == 1) cout << "G";
                else cout << "B";
            }
            cout << '\n';
        }   
    }else{
        cout << "NO";
    }
    
    
}