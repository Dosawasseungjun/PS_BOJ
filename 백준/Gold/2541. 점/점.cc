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
    int a, b; cin >> a >> b;
    int d = abs(b-a);
    if(a == b) a = b = 1;
    else{
        while(d % 2 == 0) d /= 2;
        if(a < b){
            a = 1;
            b = 1 + d;
        }else{
            a = 1 + d;
            b = 1;
        }
    }
    for(int i=0;i<5;i++){
        int p, q; cin >> p >> q;
        if((a <= b) != (p <= q)) cout << "N\n";
        else{
            int nd = abs(q - p);
            if(d == 0 && nd == 0) cout << "Y\n";
            else if(d == 0 || nd == 0) cout << "N\n";
            else if(nd % d == 0) cout << "Y\n";
            else cout << "N\n";
        }
    }
}