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

int N, K;
bool can(int x, vector<int> &V){
    int now = N;
    int cnt = 0;
    while(now != 1 && cnt < K){
        now -= min(now - 1, x);
        cnt++;
        if(now != 1) now = V[now];
    }
    return (now == 1);
}


int main(){
    fast_io
    cin >> N >> K;
    vector<int> A(N+1), B(N+1);
    for(int i=1;i<=N;i++) cin >> A[i];
    stack<int> no_time;
    for(int i=1;i<=N;i++){
        B[i] = i;
        if(A[i]) while(!no_time.empty()) {B[no_time.top()] = i; no_time.pop();}
        else no_time.push(i);
    }
    int lo = 0, hi = N-1;
    while(lo + 1 < hi){
        int mid = (lo + hi) >> 1;
        if(can(mid, B)) hi = mid;
        else lo = mid;
    }
    cout << hi;
}