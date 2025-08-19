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
    int n, k; cin >> n >> k;
    // n=k이면 무조건 불가능 1때문에
    if(n == k){
        cout << "Impossible";
        return 0;
    }
    //1을 제외한 i에 i가 들어가면 gcd가 i니깐 무조건 센다.
    // 1차이나면 무조건 gcd(x, x-1) =1 이다.
    // k-1개를 
    // 1 2 3 4 .. k-1 k
    // 2 3 4 5 .. k  1 
    int d = n - k;
    for(int i=1;i<d;i++)cout << i+1 << ' ';
    if(d) cout << 1 << ' ';
    for(int i=d+1;i<=n;i++) cout << i << ' ';
 }