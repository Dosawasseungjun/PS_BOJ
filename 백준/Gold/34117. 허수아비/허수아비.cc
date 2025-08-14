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
    ll N, P; cin >> N >> P;
    vector<ll> A(N), f(N);
    for(int i=0;i<N;i++) cin >> A[i];
    priority_queue<int, vector<int>, greater<int>> pq;
    ll S = 0;
    for(int i=0;i<N;i++){
        pq.push(A[i]);
        S += A[i];
        while(!pq.empty() && S - pq.top() >= P) {
            S -= pq.top();
            pq.pop();
        }
        if(S < P) f[i] = -1;
        else f[i] = pq.size();
    }
    for(ll ff : f) cout << ff << ' ';
}