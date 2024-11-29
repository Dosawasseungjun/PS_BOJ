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

void solv(){
    int op; cin >> op;
    if(op == 1){
        int n, x, y;
        cin >> n >> x >> y;
        x--; y--;
        swap(x, y);
        //가운데
        int mx = n/2, my = n/2;
        int dx = abs(x-mx), dy = abs(y-my);
        int k = max(dx, dy);
        int st = n*n - (2*k+1) * (2*k+1) + 1;
        int cnt = 8*k;
        int val = 0;
        if(y-my==-k && x-mx < k){  // st~st+2k-1
            val = st + k + x-mx;
        }else if(x-mx==k && y-my < k){ // st+2k~st+4k-1
            val = st+2*k + k + y - my;
        }else if(y-my==k && x-mx > -k){ // st+4k~st+6k-1
            val = st+4*k+ k + mx - x;
        }else{
            val = st+6*k+ k + my - y;
        }
        cout << val << '\n';

    }else{
        int n, z;
        cin >> n >> z;
        // 1 + 8 + 16 + 24 + .. 8*n = (n+2)^2
        int diff = n*n - z;
        int k = ((int)sqrt(diff)+1) / 2;
        int st = n*n - (2*k-1)*(2*k-1) + 1;
        int d = st - z;
        int mx = n/2, my = n/2;
        int x= 0, y= 0;
        if(d <= 2*k){
            x = mx - k;
            y = my - k + d;
        }else if(d <= 4*k){
            x = mx - k + d - 2*k;
            y = my + k;
        }else if(d <= 6*k){
            x = mx + k;
            y = my + k - d + 4*k;
        }else{
            x = mx + k - d + 6*k;
            y = my -k; 
        }
        cout << y + 1  << ' ' << x + 1 << '\n';
    }
}

int main(){
    fast_io
    int Q; cin >> Q;
    while(Q--) solv();
}