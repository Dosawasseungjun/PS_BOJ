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
    if(n==2){
        cout << "YES\n";
        cout << "1 2\n";
        cout << "1 2\n";
    }else if(n == 4){
        cout << "YES\n";
        cout << "1 2 3 4\n";
        cout << "1 2 4 3\n";
    }else{
        cout << "NO\n";
    }
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt-- ) solv();
}