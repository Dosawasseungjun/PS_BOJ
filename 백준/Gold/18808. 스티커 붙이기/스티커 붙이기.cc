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

    function<bool(vector<vector<int>>&)> can_attach = [&](vector<vector<int>> &S){
        int r = S.size();
        int c = S[0].size();
        for(int p=0;p+r<=N;p++){
            for(int q=0;q+c<=M;q++){
                bool can = true;
                for(int i=p;i<p+r;i++){
                    for(int j=q;j<q+c;j++){
                        if(S[i-p][j-q] && notebook[i][j]){
                            can = false;
                            goto label;
                        }
                    }
                }
                label : 
                if(can){
                    for(int i=p;i<p+r;i++){
                        for(int j=q;j<q+c;j++) notebook[i][j] += S[i-p][j-q];
                    }
                    return true;
                }
                 
            }
        }
        
        return false;
    };

    for(int k=0;k<K;k++){
        int is_attach = 0;
        vector<vector<int>> ns = stickers[k];
        for(int t=0;t<4;t++){
            if(can_attach(ns)) break;
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