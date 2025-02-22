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
    int n; cin >> n;
    cout << "YES\n";
    for(int i=1;i<=n;i++){
        cout << i << ' ';
    }
    cout << '\n';
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}