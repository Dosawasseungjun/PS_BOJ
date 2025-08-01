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
    string s; cin >> s;
    int idx = 2*n;
    while(idx >= 0 && s[idx] == '0') idx -= 2;
    bool ok = true;
    for(int i=1;i<idx-1;i+=2) if(s[i] == '-') ok = false;
    cout << (ok ? "YES\n" : "NO\n");
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}