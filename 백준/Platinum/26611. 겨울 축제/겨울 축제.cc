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
    ll N, M, K; cin >> N >> M >> K;
    vector<ll> A(N+1), B(N+1);
    for(int i=0;i<=N;i++) cin >> A[i];
    B[0] = A[0];
    for(int i=1;i<=N;i++){
        B[i] = A[i] + B[i-1] / K;
    }
    while(B.back()){
        ll x = B.back() / K;
        B.push_back(x);
        A.push_back(0);
    }
    B.pop_back();
    A.pop_back();
    vector<int> ans;
    int i = B.size()-1;
    for(; i >= 0 ; i--){
        // 각 축제에 x개씩 배치
        ll x = B[i] / M;
        // 총 사용한 묶음의 개수
        ll y = x * M;
        int j = i;
        if(x || !ans.empty()) ans.push_back(x);
        while(y){
            B[j] -= y;
            if(A[j] >= y){
                A[j] -= y;
                y = 0;
            }else{
                y = (y - A[j]) * K;
                A[j] = 0;
                j--;
            }
        }
    }

    for(int an : ans) cout << an;
    if(ans.empty()) cout << 0;
}