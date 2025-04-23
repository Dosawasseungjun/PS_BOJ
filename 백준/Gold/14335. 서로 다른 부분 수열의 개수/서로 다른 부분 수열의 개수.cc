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

int f(char c){
    if(c >= '0' && c <= '9') return (c - '0');
    if(c >= 'a' && c <= 'z') return (c - 'a' + 10);
    return c - 'A' + 36;
}

void solv(){
    string s; cin >> s;
    int n = s.length();
    vector<ll> dp1(n), dp2(62);
    dp1[0] = 2;
    dp2[f(s[0])] = 1;
    for(int i=1;i<n;i++){
        dp1[i] = dp1[i-1] * 2ll - dp2[f(s[i])];
        dp2[f(s[i])] += dp1[i] - dp1[i-1];
    }
    cout << dp1[n-1] << '\n';
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}