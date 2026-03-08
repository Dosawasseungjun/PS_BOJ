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
    vector<string> G(n);
    vector<vector<int>> R;
    for(int i=0;i<n;i++) cin >> G[i];
    if(n == 1){
        for(int j=0;j<m;j++){
            if(G[0][j] == 'X'){
                vector<int> K;
                K.push_back(1+j);
                if(j+1<m&&G[0][j+1] == 'X'){
                    K.push_back(2+j);
                    j += 1;
                }
                R.emplace_back(K);
            }
        }
    }else{
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(G[i][j] == 'X'){
                    vector<int> K;
                    G[i][j] = 'O';
                    K.push_back(i + 1 + n * j);
                    if(i+1<n && G[i+1][j] =='X'){
                        G[i+1][j] = 'O';    
                        K.push_back(i+2 + n*j);
                    }
                    R.emplace_back(K);
                }
            }
        }
    }

    
    cout << R.size() << '\n';
    for(auto v : R){
        cout << v.size() << ' '; 
        for(auto x : v) cout << x << ' ';
        cout << '\n';
    }
}