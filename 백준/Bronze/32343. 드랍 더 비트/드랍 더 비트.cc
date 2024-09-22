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
    int N; cin >> N;
    int a, b; cin >> a >> b;
    int res = 0;
    if(a + b <= N){
        for(int i=0;i<a+b;i++){
            res ^= (1 << (N-1-i));
        }
        cout << res;
    }else{
        int k = a + b - N;
        for(int i=0;i<N;i++){
            res ^= (1 << (N-1-i));
        }
        for(int i=0;i<k;i++){
            res ^= (1 << i);
        }
        cout << res;
    }
}