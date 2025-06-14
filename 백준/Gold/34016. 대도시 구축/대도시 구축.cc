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
    ll N, M; cin >> N >> M;
    ll res = N + N*(N+1)/2 - 2;
    vector<pii> B(M);
    for(int i=0;i<M;i++){
        cin >> B[i].xx >> B[i].yy;
    }
    if(M == 0){
        cout << res;
    }else if(M==1){
        if(B[0].xx == 1){
            if(B[0].yy == 2) cout << res + 2;
            else cout << res + 1;
        }else{
            cout << res;
        }
    }else{
        for(int i=0;i<M;i++){
            int other = 1 - i;
            if(B[i].xx != 1) continue;
            int a = B[i].xx, b = B[i].yy;
            if(b == 2){ //1 - 2인 상황
                a += 1; b += 1; // 2-3을 연결해야함
                if(B[other].xx == a && B[other].yy == b) res += 3; // 2-3도 못가면 2-4를 연결해야함
                else { // 2-3으로 가는 길을 만들었음.
                    if(B[other].xx == 1 && B[other].yy == 3) { // 1-3으로 못가는 경우 1-3쪽에서 2-3을 쓸 것이다. 
                        // 따라서 여긴 2-4를 써야한다. 
                        res += 1;
                    }
                    res += 2;
                }
                
            }else{ //1 - x인 상황
                a += 1; // 2 - x
                if(B[other].xx == a && B[other].yy == b){ // 2 - x로 못가면 3-x로 가야함
                    if(a == 2 && b == 3) res += 3; // 이 경우는 4-3으로 가야함 따라서 1-3대신 2-3으로 못가고 4-3으로 가니까 +3
                    else res += 2;
                }else{
                    res += 1;
                }
            }
        }
        cout << res;
    }
}