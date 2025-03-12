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

const int MAX = 5e6+1;
const int INF = 1e9+7;
int main(){
    fast_io
    int A, B; cin >> A >> B;
    vector<int> D(MAX, INF);
    function<void(int)> bfs = [&](int src){
        D[src] = 0; 
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int now = q.front();
            int d = D[now];
            q.pop();

            for(int i : {-1, 1}){
                int nxt = now + i;
                if(nxt < MAX && nxt > 0 &&  D[nxt] == INF){
                    D[nxt] = d + 1;
                    q.push(nxt);
                }
            }
            int k = 1;
            string s = to_string(now);
            while(k <= now){
                int r = s.back() - '0';
                int nxt1 = now + k;
                if(nxt1 < MAX && nxt1 > 0 && r != 9 &&  D[nxt1] == INF){
                    D[nxt1] = d + 1;
                    q.push(nxt1);
                }
                int nxt2 = now - k;
                if(nxt2 < MAX && nxt2 > 0 && r!=0 && D[nxt2] == INF){
                    if(k*10 <= now || r != 1){
                        D[nxt2] = d + 1;
                        q.push(nxt2);
                    }
                    
                }

                k *= 10;
                s.pop_back();
            }
        }
    };

    bfs(A);
    cout << D[B];
}