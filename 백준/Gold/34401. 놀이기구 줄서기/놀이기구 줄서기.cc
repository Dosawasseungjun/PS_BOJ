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
    ll N, P, K; cin >> N >> P >> K;
    vector<pii> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i].xx >> A[i].yy;
    }
    sort(A.begin(), A.end());

    ll i = 0, t = 0, tk = 0, tt = 0, tcnt = 0;
    ll res = 0;
    queue<int> q[6];
    vector<bool> used(N, false);
    while(i < N || !q[K-tk].empty()){
        while(!q[K-tk].empty()){
            int ori = tk;
            if(!used[q[K-tk].front()]){
                tt += A[q[K-ori].front()].xx;
                tk += A[q[K-ori].front()].yy;
                tcnt++;
                used[q[K-ori].front()] = 1;
            }
            q[K-ori].pop();
        }
        while(i < N && A[i].xx <= t){
            if(tk + A[i].yy <= K){
                tk += A[i].yy;
                tt += A[i].xx;
                tcnt++;
                used[i] = 1;
            }else{
                for(int j=A[i].yy;j<=K;j++){
                    q[j].push(i);
                }
                
            }
            i++;
        }
        res += t*tcnt - tt;
        tk = 0; tt = 0; tcnt = 0;
        t += P;
    }
    cout << res;
}