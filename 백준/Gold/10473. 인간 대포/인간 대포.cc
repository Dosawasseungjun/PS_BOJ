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

pair<double, double> P[105];
vector<pair<int, double>> G[105];
double D[105];

double dist(pair<double, double> &p1, pair<double, double> &p2){
    return sqrt((p2.xx-p1.xx)*(p2.xx-p1.xx) + (p2.yy-p1.yy)*(p2.yy-p1.yy));
}

void dijkstra(int src){
    for(int i=0;i<=104;i++) D[i] = numeric_limits<double>::max();
    D[src] = 0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({D[src], src});
    while(!pq.empty()){
        auto [dist, here] = pq.top();
        pq.pop();

        if(dist > D[here]) continue;
        for(auto [nxt, w] : G[here]){
            if(D[nxt] > dist + w){
                D[nxt] = dist + w;
                pq.push({D[nxt], nxt});
            }
        }
    }
}

int main(){
    fast_io
    cin >> P[1].xx >> P[1].yy; // 1번은 현재 위치
    cin >> P[2].xx >> P[2].yy; // 2번은 목적지 위치
    int N; cin >> N;
    for(int i=3;i<3+N;i++){
        cin >> P[i].xx >> P[i].yy;
    }

    for(int i=1;i<=N+2;i++){
        for(int j=1;j<=N+2;j++){
            if(i == j) continue;
            // 걷기
            G[i].emplace_back(j, dist(P[i], P[j]) / 5.0 );
            // 대포타기
            if(i == 1 || i ==2) continue;
            G[i].emplace_back(j, 2 + abs(50 - dist(P[i], P[j])) / 5.0);
        }
    }

    dijkstra(1);
    cout << D[2];
}