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

ll quest(ll n){
    cout << n << "\n";
    cout.flush();
    ll ret; cin >> ret;
    return ret;
}

int main(){
    fast_io
    ll K; cin >> K;
    if(K == 1){
        cout << "0\n";
        cout.flush();
        cout << "1\n";
        cout.flush();
    }else{
        cout << "1\n";
        cout.flush();
        ll res = quest(1);
        cout << (res==0 ? K : res) << '\n';
        cout.flush();
    }
}