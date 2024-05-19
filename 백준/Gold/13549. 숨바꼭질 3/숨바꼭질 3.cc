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

const int V_MAX = 2e5+1;
const int INF = 1e9+1;

vector<int> bfs(int here){
    deque<int> dq;
    vector<int> dist(V_MAX, INF);
    dq.push_back(here);
    dist[here] = 0;
    while(!dq.empty()){
        int now = dq.front();
        dq.pop_front();
        if(now + 1 < V_MAX && dist[now + 1] > dist[now] + 1){
            dq.push_back(now + 1);
            dist[now + 1] = dist[now] + 1;
        }
        if (now - 1 >= 0 && dist[now - 1] > dist[now] + 1){
            dq.push_back(now - 1);
            dist[now - 1] = dist[now] + 1;
        }
        if(2 * now < V_MAX && dist[2 * now] > dist[now]){
            dq.push_front(now * 2);
            dist[now * 2] = dist[now];
        }
    }
    return dist;
}


int main(){
    fast_io
    int N, K; cin >> N >> K;
    vector<int> D = bfs(N);
    cout << D[K];
}