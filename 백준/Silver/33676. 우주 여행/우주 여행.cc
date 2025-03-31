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

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};

int main(){
    fast_io
    int N, M, K, L;
    cin >> N >> M >> K >> L;
    vector<pii> U(K);
    for(int i=0;i<K;i++){
        int r, c; cin >> r >> c;
        U[i] = {r, c};
    }
    if(L < N + M -2){
        cout << -1;
    }else{
        int D = L - (N + M - 2 );
        if(D & 1){
            cout << -1;
        }else{
            string ans;
            for(int i=1;i<N;i++) ans += "D";
            for(int i=1;i<M;i++) ans += "R";
            while(D){
                ans += "UD";
                D -= 2;
            }
            cout << ans;
        }
    }
    
}