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

const int MAX = 22222;
const int half = 11111;

int main(){
    fast_io
    int n, m; cin >> n >> m;
    vector<int> p(n);
    for(int i=0;i<n;i++) cin >> p[i];
    
    vector<int> D(MAX, -1);
    D[half] = 0;
    queue<int> q;
    q.push(half);
    while(!q.empty()){
        int here = q.front();
        q.pop();
        for(int pp : p){
            int nxt = here + pp;
            if(nxt < MAX && nxt >= 0 && D[nxt] == -1){
                D[nxt] = D[here] + 1;
                q.push(nxt);
            }
        }
    }
    cout << D[m + half];
}