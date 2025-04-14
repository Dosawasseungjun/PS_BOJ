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
    int s, n; cin >> s >> n;
    vector<int> x(n);
    for(int i=0;i<n;i++) cin >> x[i];
    vector<int> c(s+1);
    vector<int> valid(s, 1);
    int cnt = 0;
    int wildcard = s;
    for(int i=0;i<n+s;i++){
        if(i - s < 0) wildcard--;
        else if(!(--c[x[i-s]])) cnt--;

        if(i >= n) wildcard++;
        else if(!c[x[i]]++) cnt++;

        if(cnt + wildcard != s) valid[i % s] &= 0;
    }
    

    cout << accumulate(valid.begin(), valid.end(), 0) << '\n';
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}