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

const ll MOD = 1e9+7;

void solv(){
    string s; cin >> s;
    int k = 0;
    vector<ll> A;
    for(int i = 0; i<s.size();i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            A.push_back(k);
            k = 0;
        }else{
            k++;
        }
    }
    if(k == s.size()){
        cout << "-1\n";
        return ;
    }
    ll res = 1;
    for(int i=1;i<A.size();i++){
        if(i) res = res * (A[i] + 1) % MOD;
    }
     
    cout << res << '\n';
}

int main(){
    fast_io
    int T; cin >> T;
    while(T--) solv();
}