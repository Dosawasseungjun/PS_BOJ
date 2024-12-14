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
    vector<int> ans(5);
    ans[0] = n / 60;
    int r = n % 60;
    if(r > 35){
        ans[0] += 1;
        r = 60 - r;
        ans[2] = r / 10;
        r %= 10;
        if(r > 5){
            ans[2] += 1;
            ans[3] = 10 - r;
        }else{
            ans[4] = r;
        }
    }else{
        ans[1] = r / 10;
        r %= 10;
        if(r > 5){
            ans[1] += 1; 
            ans[4] = 10 - r;
        }else{
            ans[3] = r;
        }
    }


    for(int a : ans) cout << a << ' ';
    cout << '\n';
}

int main(){
    fast_io
    int tt; cin >> tt;
    while(tt--) solv();
}