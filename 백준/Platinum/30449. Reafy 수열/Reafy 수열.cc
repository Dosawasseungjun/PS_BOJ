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

ll n, k;

pii findFareyKth(int n, int k){
    int a = 0, b = 1;
    int c = 1, d = n;

    int cnt = 1;
    if(k == 1) return {a, b};

    while(1){
        int x = (n + b) / d;
        int e = x * c - a;
        int f = x * d - b;
        cnt++;
        if(cnt == k){
            return {c, d};
        }
        a = c; b = d;
        c = e; d = f;
    }
    return {1, 1};
}

int main(){
    fast_io
    cin >> n >> k;
    pii res = findFareyKth(n, k);
    cout << res.xx << ' ' << res.yy;
}