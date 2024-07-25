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

int R, C;

vector<int> G[201 * 201 * 8];
vector<int> vst(201 * 201 * 8, 0);

void dfs(int here){
    vst[here] = true;
    for(int nxt : G[here]){
        if(vst[nxt]) continue;
        dfs(nxt);
    }
}

int main(){
    fast_io
    cin >> R >> C;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            char c; cin >> c;
            int st = (i - 1) * 8 * C + (j - 1) * 8 + 1;
            if(c == 'O'){
                for(int k=0;k<4;k++){
                    G[st + k].push_back(st + k + 4);
                    G[st + k + 4].push_back(st + k);
                }
            }else if(c == 'I'){
                G[st].push_back(st + 2);
                G[st+2].push_back(st);

                G[st + 1].push_back(st + 3);
                G[st + 3].push_back(st + 1);

                G[st + 4].push_back(st + 6);
                G[st + 6].push_back(st + 4);

                G[st + 5].push_back(st + 7);
                G[st + 7].push_back(st + 5);
            }else{
                for(int k=0;k<8;k+=2){
                    G[st + k].push_back(st + k + 1);
                    G[st + k + 1].push_back(st + k);
                }
            }

            // 옆이랑 연결
            if(j > 1){
                for(int k = 0;k<8;k+=2){
                    G[st + k].push_back(st + k - 7);
                    G[st + k - 7].push_back(st + k);
                }
            }

            // 위랑 연결
            if(i > 1){
                int d = 8 * C - 2;
                for(int k=0;k<2;k++){
                    G[st + k].push_back(st + k - d);
                    G[st + k - d].push_back(st + k);
                    
                    G[st + 4 + k].push_back(st + k + 4 - d);
                    G[st + 4 + k - d].push_back(st + 4 + k);
                }
            }
        }
    }
    int res = 0;
    for(int i=1;i<=R * C * 8;i++){
        if(!vst[i]){
            dfs(i);
            res++;
        }
    }

    cout << res;
}