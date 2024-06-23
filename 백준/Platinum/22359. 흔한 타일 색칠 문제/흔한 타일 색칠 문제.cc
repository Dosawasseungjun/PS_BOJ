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

vector<vector<char>> G;

void recur(int a, int b, int sz, int y, int x){
    if(sz == 2){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                int Y = y+i;
                int X = x+j;
                if(G[Y][X] != '.') continue;
                int pp = Y % 4;
                int qq = X % 4;
                if(pp < 2 && qq < 2) G[Y][X] = 'a';
                else if(pp < 2) G[Y][X] = 'b';
                else if(qq < 2) G[Y][X] = 'b';
                else G[Y][X] = 'a';
            }
        }
        return;
    }
    int P = 0;
    int nsz = sz / 2;
    if(a < nsz && b < nsz) P = 1;
    else if(a < nsz) P = 2;
    else if(b < nsz) P = 3;
    else P = 4;

    if(P == 1){
        G[y+nsz-1][x+nsz] = 'c';
        G[y+nsz][x+nsz-1] = 'c';
        G[y+nsz][x+nsz] = 'c';
        recur(a, b, nsz, y+0, x+0); // 1
        recur(nsz-1, 0, nsz, y+0, x+nsz); // 2
        recur(0, nsz-1, nsz, y+nsz, x+0); // 3
        recur(0, 0, nsz, y+nsz, x+nsz); // 4
    }else if(P == 2){
        G[y+nsz-1][x+nsz-1] = 'c';
        G[y+nsz][x + nsz - 1] = 'c';
        G[y + nsz][x + nsz] = 'c';
        recur(nsz-1, nsz-1, nsz, y+0, x+0);         // 1
        recur(a , b-nsz, nsz, y+0, x+nsz); // 2
        recur(0, nsz - 1, nsz, y+nsz, x+0); // 3
        recur(0, 0, nsz, y+nsz, x+nsz);     // 4
    }else if(P == 3){
        G[y+nsz-1][x+nsz-1] = 'c';
        G[y + nsz - 1][x+nsz] = 'c';
        G[y + nsz][x + nsz] = 'c';
        recur(nsz - 1, nsz - 1, nsz, y + 0, x + 0); // 1
        recur(nsz-1, 0, nsz, y + 0, x + nsz);     // 2
        recur(a-nsz, b, nsz, y + nsz, x + 0);     // 3
        recur(0, 0, nsz, y + nsz, x + nsz);         // 4
    }else{
        G[y+nsz-1][x+nsz-1] = 'c';
        G[y + nsz - 1][x+nsz] = 'c';
        G[y+nsz][x + nsz - 1] = 'c';
        recur(nsz - 1, nsz - 1, nsz, y + 0, x + 0); // 1
        recur(nsz - 1, 0, nsz, y + 0, x + nsz);     // 2
        recur(0, nsz-1, nsz, y + nsz, x + 0);     // 3
        recur(a-nsz, b-nsz, nsz, y + nsz, x + nsz);         // 4
    }
}

void solv(int k){
    G = vector((1 << k), vector<char>(1 << k, '.'));
    int a, b;
    cin >> a >> b;
    a--; b--; 
    G[a][b] = '@';
    recur(a, b, 1 << k, 0, 0);
    
    for(int i=0;i<(1<<k);i++){
        for(int j=0;j<(1<<k);j++){
            cout << G[i][j];
        }
        cout << '\n';
    }
}

int main(){
    fast_io
    int tt; cin >> tt;
    int k; cin >> k;
    while(tt--) solv(k);
}