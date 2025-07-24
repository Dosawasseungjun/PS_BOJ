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
    int H, M; cin >> H >> M;
    int N; cin >> N;
    int x = H*5 - M;
    if(x <0) x+=60;
    if(x > N){
        int h = (H*5 + N) % 60;
        int m = (M + 2*N) % 60;
        h /= 5;
        cout << h << ' ' << m;
    }else{
        int now = (H*5 + x) % 60;
        N -= x;
        int p = N / 80;
        now = (now + p * 80) % 60;
        int y = N % 80;
        int h = now, m = now;
        if(y <= 20){
            h = (now + y) % 60;
            m = (now - 2*y + 60) % 60;
        }else{
            now += 20;
            y -= 20;

            h = (now + y) % 60;
            m = (now + 2*y) % 60;
        }
        h /= 5;
        cout << h << ' ' << m;
    }
}