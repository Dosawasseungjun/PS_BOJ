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
    vector G = vector(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> G[i][j];
        }
    }
    if((n & 1) && (m & 1)){
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    if(n & 1){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j+=2){
                cout << G[i][j+1] << ' ';
                cout << G[i][j] << ' ';
            }
            cout << '\n';
        }
    }else{
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << G[i ^ 1][j] << ' ';
            }
            cout << '\n';
        }
    }
}