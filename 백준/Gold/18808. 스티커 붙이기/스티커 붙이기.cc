#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M, K; cin >> N >> M >> K;
    vector stickers = vector(K, vector<vector<int>>());
    for(int i=0;i<K;i++){
        int R, C; cin >> R >> C;
        vector tmp = vector(R, vector<int>(C));
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cin >> tmp[i][j];
            }
        }
        stickers[i] = tmp;
    }
    vector notebook = vector(N, vector<int>(M, 0));

    function<void(vector<vector<int>>&)> rotate_sticker = [&](vector<vector<int>> &S){
        int r = S.size();
        int c = S[0].size();
        vector ns = vector(c, vector<int>(r, 0));
        for(int i=0;i<c;i++){
            for(int j=0;j<r;j++){
                ns[i][j] = S[r-1-j][i];
            }
        }
        S = ns;
    };

    function<void(int, int, vector<vector<int>>&, int&)> can_attach = [&](int y, int x, vector<vector<int>> &S, int& flag){
        int r = S.size();
        int c = S[0].size();
        vector<vector<int>> tmp_notebook = notebook;
        for(int i=y;i<y+r;i++){
            for(int j=x;j<x+c;j++){
                if(S[i-y][j-x] && tmp_notebook[i][j]){
                    return ;
                }else if(S[i-y][j-x]){
                    tmp_notebook[i][j] = 1;
                }
            }
        }
        flag = 1;
        notebook = tmp_notebook;
    };

    for(int k=0;k<K;k++){
        int is_attach = 0;
        vector<vector<int>> ns = stickers[k];
        for(int t=0;t<4;t++){
            int r = ns.size();
            int c = ns[0].size();
            for(int i=0;i+r<=N;i++){
                for(int j=0;j+c<=M;j++){
                    can_attach(i, j, ns, is_attach);
                    if(is_attach) break;
                }
                if(is_attach) break;
            }
            if(is_attach) break;
            rotate_sticker(ns);
        }
    }
    int res = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            res += notebook[i][j];
        }
    }
    cout << res;
}