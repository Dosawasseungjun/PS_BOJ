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
    int N, M; cin >> N >> M;
    vector G = vector(N+1, vector<int>());
    for(int i=0;i<M;i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=2;i<=N;i++){
        bool ok = false;
        for(int k : G[i]){
            if(k < i) ok = true;
        }
        if(!ok){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}