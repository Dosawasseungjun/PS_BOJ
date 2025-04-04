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

const int MAX = 2e5+20;
struct tSAT{
    int n; // 정점의 개수
    vector<int> G[MAX], R[MAX], C, order;

    void DFS1(int here){
        C[here] = -1;
        for(int next : G[here]){
            if(!C[next]) DFS1(next);
        }
        order.push_back(here);
    }

    void DFS2(int here, int color){
        C[here] = color;
        for(int next : R[here]){
            if(C[next]==-1){
                DFS2(next, color);
            }
        }
    }

    int SCC(){
        C = vector<int> (2*n+1, 0);
        for(int i=0;i<=2*n;i++) if(!C[i]) DFS1(i);
        reverse(order.begin(), order.end());
        int cnt = 0;
        for(int i : order){
            if(C[i]==-1) DFS2(i, ++cnt);
        }
        return cnt;
    }
};

tSAT sat1, sat2;

int main(){
    fast_io
    int N, M; cin >> N >> M;
    vector<int> po, pe, mo, me;
    for(int i=1;i<=2*N;i+=2){
        po.push_back(i);
        pe.push_back(i+1);
        mo.push_back(-i);
        me.push_back(-i-1);
    }
    vector<tiii> PM, OE;
    for(int i=0;i<M;i++){
        char c;
        int l, r; 
        cin >> c >> l >> r;
        if(c == 'P' || c == 'M') PM.push_back({(c == 'M'), l, r});
        else OE.push_back({(c == 'O'), l, r});
    }
    // 양수음수 그래프 구성
    sat1.n = N+1;
    for(auto [c, l, r] : PM){
        int u = l-1;
        int v = r;
        int notu = u + N+1;
        int notv = v + N+1;
        if(c){ //음수면 - 둘이 달라야함
            sat1.G[u].push_back(notv);
            sat1.G[v].push_back(notu);
            sat1.G[notv].push_back(u);
            sat1.G[notu].push_back(v);

            sat1.R[notv].push_back(u);
            sat1.R[notu].push_back(v);
            sat1.R[u].push_back(notv);
            sat1.R[v].push_back(notu);
        }else{ // 양수면 - 둘이 같아야함
            sat1.G[u].push_back(v);
            sat1.G[notu].push_back(notv);
            sat1.G[v].push_back(u);
            sat1.G[notv].push_back(notu);

            sat1.R[v].push_back(u);
            sat1.R[notv].push_back(notu);
            sat1.R[u].push_back(v);
            sat1.R[notu].push_back(notv);
        }
    }
    sat1.G[0].push_back(N+1);
    sat1.R[N+1].push_back(0);

    // 홀수짝수 그래프 구성
    sat2.n = N+1;
    for(auto [c, l, r] : OE){
        int u = l-1;
        int v = r;
        int notu = u + N+1;
        int notv = v + N+1;
        if(c){ // 홀수 - 둘이 달라야함
            sat2.G[u].push_back(notv);
            sat2.G[v].push_back(notu);
            sat2.G[notu].push_back(v);
            sat2.G[notv].push_back(u);


            sat2.R[notv].push_back(u);
            sat2.R[notu].push_back(v);
            sat2.R[v].push_back(notu);
            sat2.R[u].push_back(notv);
        }else{ // 짝수 - 둘이 같아야함
            sat2.G[u].push_back(v);
            sat2.G[notu].push_back(notv);
            sat2.G[v].push_back(u);
            sat2.G[notv].push_back(notu);

            sat2.R[v].push_back(u);
            sat2.R[notv].push_back(notu);
            sat2.R[u].push_back(v);
            sat2.R[notu].push_back(notv);
        }
    }
    sat2.G[0].push_back(N + 1);
    sat2.R[N + 1].push_back(0);


    int scc1 = sat1.SCC(); // 양수음수
    int scc2 = sat2.SCC(); // 짝수홀수
    bool ok = true;
    for(int i=1;i<=N;i++){
        if(sat1.C[i] == sat1.C[i+N+1]) ok = false;
        if(sat2.C[i] == sat2.C[i+N+1]) ok = false;
    }
    if(!ok){
        cout << 0;
        return 0;
    }
    //1번배열 : 0-양수 1-음수 2번배열 : 0-짝수 1-홀수
    vector<int> b1(N+1), b2(N+1);
    vector<int> a1(N+1), a2(N+1);
    for(int i=1;i<=N;i++){
        if(sat1.C[i] > sat1.C[i+N+1]) b1[i] = 1;
        else b1[i] = 0;
    }
    for(int i=1;i<=N;i++){
        if(sat2.C[i] > sat2.C[i+N+1]) b2[i] = 1;
        else b2[i] = 0;
    }
    for(int i=1;i<=N;i++){
        a1[i] = b1[i] ^ b1[i-1];
        a2[i] = b2[i] ^ b2[i-1];
    }
    int a = 0, b = 0, c = 0, d = 0;
    for(int i=1;i<=N;i++){
        if(a1[i]&&a2[i]){
            cout << mo[a++] << ' ';
        }else if(a1[i]){
            cout << me[b++] << ' ';
        }else if(a2[i]){
            cout << po[c++] << ' ';
        }else{
            cout << pe[d++] << ' ';
        } 
    }
}